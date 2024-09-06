#include "verticalsidebar.h"
#include <QIcon>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <qlabel.h>


VerticalSidebar::VerticalSidebar(QWidget* parent) :
    QWidget(parent), layout(new QVBoxLayout(this)),
    avatarLabel(new QLabel(this)) {
  layout->setSpacing(20);                 // 设置控件之间的间隔
  layout->setContentsMargins(0, 0, 0, 0); // 设置布局的边距

  // 设置用户头像
  avatarLabel->setPixmap(
      QPixmap(":/path_to_avatar_image").scaled(50, 50, Qt::KeepAspectRatio));
  layout->addWidget(avatarLabel);
  layout->addStretch(); // 在头像和按钮之间添加一个弹性空间

  // 创建按钮
  QPushButton* btn1 = createButton(":/path_to_icon1");
  QPushButton* btn2 = createButton(":/path_to_icon2");
  QPushButton* btn3 = createButton(":/path_to_icon3");
  QPushButton* btn4 = createButton(":/path_to_icon4");
  QPushButton* btn5 = createButton(":/path_to_icon5");

  // 将按钮添加到布局中
  layout->addWidget(btn1);
  layout->addWidget(btn2);
  layout->addWidget(btn3);
  layout->addWidget(btn4);
  layout->addWidget(btn5);
layout->addWidget(new QLabel("Hello World"));
  layout->addStretch(); // 在按钮和底部控件之间添加一个弹性空间

  // 添加底部的按钮
  QPushButton* bottomBtn1 = createButton(":/path_to_bottom_icon1");
  QPushButton* bottomBtn2 = createButton(":/path_to_bottom_icon2");
  QPushButton* bottomBtn3 = createButton(":/path_to_bottom_icon3");

  layout->addWidget(bottomBtn1);
  layout->addWidget(bottomBtn2);
  layout->addWidget(bottomBtn3);

  // 设置背景颜色
  setStyleSheet("background-color: #E8F4FF;"); // 使用浅蓝色背景
}

QPushButton* VerticalSidebar::createButton(const QString& iconPath) {
  QPushButton* button = new QPushButton(this);
  button->setIcon(QIcon(iconPath));
  button->setIconSize(QSize(24, 24)); // 设置图标大小
  button->setFixedSize(50, 50);       // 设置按钮大小
  button->setFlat(true);              // 去掉按钮边框
  return button;
}
