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

  window.setLayout(layout);
  window.show();

  return app.exec();
}
#include <QApplication>
#include <QDesktopServices>
#include <QPushButton>
#include <QUrl>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("Open URL Example");

  QVBoxLayout* layout = new QVBoxLayout(&window);

  QPushButton* button = new QPushButton("打开教务系统");
  layout->addWidget(button);

  QObject::connect(button, &QPushButton::clicked, []() {
    QUrl url("http://xk.huel.edu.cn/jwglxt/xtgl/login_slogin.html");
    QDesktopServices::openUrl(url);
  });

  window.setLayout(layout);
  window.show();

  return app.exec();
}