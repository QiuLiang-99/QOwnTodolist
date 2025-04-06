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
  initUI();
  resize(1280, 720); // 设置默认大小，但不固定
}

MainWindow::~MainWindow() {}

void MainWindow::initUI() {
  // 主水平布局
  QHBoxLayout* mainLayout = new QHBoxLayout;
  mainLayout->setContentsMargins(0, 0, 0, 0);
  mainLayout->setSpacing(10); // 增加左右间距让按钮不贴住右边窗口

  // 左侧按钮区域
  QWidget*     leftWidget = new QWidget;
  QVBoxLayout* leftLayout = new QVBoxLayout(leftWidget);
  leftLayout->setContentsMargins(10, 10, 10, 10);
  leftLayout->setSpacing(10); // 按钮之间留点空间

  // 创建三个可多选的按钮（大小：100 x 50）
  QPushButton* btnHuya = new QPushButton("虎牙");
  btnHuya->setCheckable(true);
  btnHuya->setFixedSize(100, 50);
  btnHuya->setStyleSheet(
      "QPushButton { background-color: yellow; font: bold 14px; }");

  QPushButton* btnDouyu = new QPushButton("斗鱼");
  btnDouyu->setCheckable(true);
  btnDouyu->setFixedSize(100, 50);
  btnDouyu->setStyleSheet(
      "QPushButton { background-color: orange; font: bold 14px; }");

  QPushButton* btnBilibili = new QPushButton("b站");
  btnBilibili->setCheckable(true);
  btnBilibili->setFixedSize(100, 50);
  btnBilibili->setStyleSheet(
      "QPushButton { background-color: blue; font: bold 14px; }");

  // 将按钮加入左侧布局
  leftLayout->addWidget(btnHuya);
  leftLayout->addWidget(btnDouyu);
  leftLayout->addWidget(btnBilibili);
  leftLayout->addStretch(); // 按钮贴近顶部

  // 右侧自定义窗口
  QWidget* customWidget = new QWidget;
  customWidget->setStyleSheet("background-color: lightgray;");
  ////customWidget->setFixedSize(640, 360); // 16:9 占位符窗口

  // 添加到主布局
  mainLayout->addWidget(leftWidget);
  mainLayout->addWidget(customWidget);
  // 加入这两行
  mainLayout->setStretch(0, 0); // 左侧不拉伸
  mainLayout->setStretch(1, 1); // 右侧占据剩余空间

  // 应用主布局
  this->setLayout(mainLayout);

  // 自动适应内容大小
  this->adjustSize();
}
