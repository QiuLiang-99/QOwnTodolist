#include "mainwindow.h"

#include <QBuffer>
#include <QDebug>
#include <QHBoxLayout>
#include <QIcon>
#include <QImageReader>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWebEngineView>


MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
  setFixedSize(1280, 720); // 设置窗口大小为16:9比例
  initUI();
}

MainWindow::~MainWindow() {}

void MainWindow::initUI() {
  // 主水平布局
  QHBoxLayout* mainLayout = new QHBoxLayout;
  mainLayout->setContentsMargins(0, 0, 0, 0);
  mainLayout->setSpacing(0);

  // 左侧按钮区域
  QWidget*     leftWidget = new QWidget;
  QVBoxLayout* leftLayout = new QVBoxLayout(leftWidget);
  leftLayout->setContentsMargins(10, 10, 10, 10);
  leftLayout->setSpacing(5);

  // 创建三个可多选的按钮
  QPushButton* btnHuya = new QPushButton("虎牙");
  btnHuya->setCheckable(true);
  QPushButton* btnDouyu = new QPushButton("斗鱼");
  btnDouyu->setCheckable(true);
  QPushButton* btnBilibili = new QPushButton("b站");
  btnBilibili->setCheckable(true);

  // 设置按钮样式
  btnHuya->setStyleSheet(
      "QPushButton { background-color: yellow; font: bold 14px; }");
  btnDouyu->setStyleSheet(
      "QPushButton { background-color: orange; font: bold 14px; }");
  btnBilibili->setStyleSheet(
      "QPushButton { background-color: blue; font: bold 14px; }");

  // 将按钮依次加入左侧布局
  leftLayout->addWidget(btnHuya);
  leftLayout->addWidget(btnDouyu);
  leftLayout->addWidget(btnBilibili);
  // 添加弹簧，保证按钮紧靠左上角排列
  leftLayout->addStretch();

  // 右侧自定义窗口（暂用 QWidget 代替），固定尺寸且保持16:9比例
  QWidget* customWidget = new QWidget;
  customWidget->setStyleSheet("background-color: lightgray;"); // 可视化占位效果
  customWidget->setFixedSize(640, 360);                        // 16:9 比例

  // 将左侧按钮区域和右侧自定义窗口添加到主水平布局中
  mainLayout->addWidget(leftWidget);
  mainLayout->addWidget(customWidget);

  // 设置主布局到窗口
  this->setLayout(mainLayout);

  // 下载并设置按钮图标
  downloadAndSetIcon(
      btnHuya,
      "https://a.msstatic.com/huya/hd/h5/static-source/main/logo2.png");
  downloadAndSetIcon(btnDouyu,
                     "https://example.com/douyu.png");    // 替换为实际URL
  downloadAndSetIcon(btnBilibili,
                     "https://example.com/bilibili.png"); // 替换为实际URL
}

void MainWindow::downloadAndSetIcon(QPushButton* button, const QString& url) {
  QNetworkAccessManager* manager = new QNetworkAccessManager(this);
  connect(manager, &QNetworkAccessManager::finished, this,
          [=](QNetworkReply* reply) {
            if (reply->error() == QNetworkReply::NoError) {
              QByteArray data = reply->readAll();
              QPixmap    pixmap;
              pixmap.loadFromData(data);
              button->setIcon(QIcon(pixmap));
            }
            reply->deleteLater();
            manager->deleteLater();
          });
  manager->get(QNetworkRequest(QUrl(url)));
}