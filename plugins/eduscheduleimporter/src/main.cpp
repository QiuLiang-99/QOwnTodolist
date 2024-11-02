#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWebEngineView>
#include <QWidget>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("Open URL Example");

  QVBoxLayout* layout = new QVBoxLayout(&window);

  QPushButton* button = new QPushButton("打开教务系统");
  layout->addWidget(button);

  QWebEngineView* webView = new QWebEngineView();
  layout->addWidget(webView);

  QObject::connect(button, &QPushButton::clicked, [webView]() {
    QUrl url("http://xk.huel.edu.cn/jwglxt/xtgl/login_slogin.html");
    webView->setUrl(url);
  });
  // 加载目标网页

  // 执行JavaScript代码
  QPushButton* downloaddatabtn = new QPushButton("打开教务系统");
  layout->addWidget(downloaddatabtn);
  QObject::connect(downloaddatabtn, &QPushButton::clicked, [=]() {
    QString js = R"(
                var ifrs = document.getElementsByTagName("iframe");
                var iframeContent = "";
                for (var i = 0; i < ifrs.length; i++) {
                    iframeContent += ifrs[i].contentDocument.body.parentElement.outerHTML;
                }
                var frs = document.getElementsByTagName("frame");
                var frameContent = "";
                for (var i = 0; i < frs.length; i++) {
                    frameContent += frs[i].contentDocument.body.parentElement.outerHTML;
                }
                window.local_obj.showSource(document.getElementsByTagName('html')[0].innerHTML + iframeContent + frameContent);
            )";
    webView->page()->runJavaScript(js);
  });
  window.setLayout(layout);
  window.resize(800, 600);
  window.show();

  return app.exec();
}