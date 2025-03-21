#include "signinwidget.h"

#include <QDesktopServices>
#include <QIcon>
#include <QPushButton>
#include <QUrl>
#include <QVBoxLayout>


SignInWidget::SignInWidget(QWidget* parent) : QWidget(parent) { initUI(); }

SignInWidget::~SignInWidget() {}

void SignInWidget::initUI() {
  // 1. 创建布局
  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);

  // 2. 创建按钮并设置图标
  QPushButton* huyaButton = new QPushButton(this);
  QIcon huyaIcon(":/icons/huya.png"); // 假设图标文件位于资源文件中
  huyaButton->setIcon(huyaIcon);
  huyaButton->setIconSize(QSize(64, 64)); // 设置图标大小
  layout->addWidget(huyaButton, 0, Qt::AlignCenter);

  // 3. 连接按钮点击信号到槽函数
  connect(huyaButton, &QPushButton::clicked, this, []() {
    QDesktopServices::openUrl(
        QUrl("https://www.huya.com/udb_web/checkLogin.php"));
  });

  // 4. 设置布局
  setLayout(layout);
}