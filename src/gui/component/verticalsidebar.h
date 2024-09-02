#ifndef VERTICALSIDEBAR_H
#define VERTICALSIDEBAR_H

#include <QWidget>

// 前置声明类
class QVBoxLayout;
class QPushButton;
class QLabel;

class VerticalSidebar : public QWidget {
    Q_OBJECT

  public:
    VerticalSidebar(QWidget* parent = nullptr);

  private:
    QPushButton* createButton(const QString& iconPath);

    QVBoxLayout* layout;      // 垂直布局
    QLabel*      avatarLabel; // 用户头像
};

#endif // VERTICALSIDEBAR_H
