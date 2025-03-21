#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QWebEnginePage>
#include <QWebEngineProfile>
#include <QWebEngineUrlRequestInfo>
#include <QWebEngineUrlRequestInterceptor>
#include <QWebEngineView>
#include <QWidget>

class RequestInterceptor : public QWebEngineUrlRequestInterceptor {
    Q_OBJECT

  public:
    void interceptRequest(QWebEngineUrlRequestInfo& info) override {
      qDebug() << "Request URL:" << info.requestUrl().toString();
      qDebug() << "Request Method:" << info.requestMethod();
      qDebug() << "Request Body:" << info.requestBody();
      qDebug() << "Request time:"
               << QDateTime::currentDateTime().toString("hh:mm:ss");
    }
};

class WebEnginePage : public QWebEnginePage {
    Q_OBJECT

  public:
    explicit WebEnginePage(QWebEngineProfile* profile,
                           QObject*           parent = nullptr) :
        QWebEnginePage(profile, parent) {
      connect(this, &QWebEnginePage::loadFinished, this,
              &WebEnginePage::onLoadFinished);
    }

  protected:
    void javaScriptConsoleMessage(JavaScriptConsoleMessageLevel level,
                                  const QString&                message,
                                  int                           lineNumber,
                                  const QString& sourceID) override {
      Q_UNUSED(level);
      Q_UNUSED(lineNumber);
      Q_UNUSED(sourceID);
      qDebug() << "JavaScript console message:" << message;
    }

  private slots:
    void onLoadFinished(bool ok) {
      if (ok) {
        qDebug() << "Page loaded successfully.";
        // 获取服务器返回的状态码
        this->runJavaScript(
            "document.readyState", [this](const QVariant& result) {
              if (result.toString() == "complete") {
                this->runJavaScript("document.status",
                                    [](const QVariant& statusCode) {
                                      qDebug() << "Server response status code:"
                                               << statusCode.toInt();
                                    });
              }
            });
        // 停止超时计时器
        if (timeoutTimer) { timeoutTimer->stop(); }
        // 将窗口置顶
        if (window) {
          window->raise();
          window->activateWindow();
        }
      } else {
        qDebug() << "Page failed to load.";
        qDebug() << "Server response status code: 0"; // 默认状态码
      }
    }

  public:
    void setWindow(QWidget* win) { window = win; }

    void setTimeoutTimer(QTimer* timer) { timeoutTimer = timer; }

  private:
    QWidget* window       = nullptr;
    QTimer*  timeoutTimer = nullptr;
};

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("Open URL Example");

  QVBoxLayout* layout             = new QVBoxLayout(&window);

  QWebEngineProfile*  profile     = QWebEngineProfile::defaultProfile();
  RequestInterceptor* interceptor = new RequestInterceptor();
  profile->setUrlRequestInterceptor(interceptor);

  WebEnginePage*  page    = new WebEnginePage(profile);
  QWebEngineView* webView = new QWebEngineView();
  webView->setPage(page);
  layout->addWidget(webView);

  QPushButton* refreshButton = new QPushButton("Refresh Page");
  layout->addWidget(refreshButton);
  QObject::connect(refreshButton, &QPushButton::clicked, webView,
                   &QWebEngineView::reload);

  QTimer* timeoutTimer = new QTimer(&window);
  timeoutTimer->setInterval(60000); // 1分钟
  QObject::connect(timeoutTimer, &QTimer::timeout, webView,
                   &QWebEngineView::reload);
  timeoutTimer->start();

  page->setWindow(&window);
  page->setTimeoutTimer(timeoutTimer);

  ////QUrl url("http://xk.huel.edu.cn/jwglxt/xtgl/login_slogin.html");
  QUrl url("http://49.122.0.80/jwglxt/xtgl/login_slogin.html");

  ////QUrl url("https://www.bilibili.com/video/BV1Pk4y1B71N/?p=46");
  webView->setUrl(url);

  window.setLayout(layout);
  window.resize(800, 600);
  window.show();

  return app.exec();
}

#include "main.moc"