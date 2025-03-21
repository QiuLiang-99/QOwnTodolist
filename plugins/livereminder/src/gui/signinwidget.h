#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QWidget>

class SignInWidget : public QWidget {
    Q_OBJECT

  public:
    explicit SignInWidget(QWidget* parent = nullptr);
    ~SignInWidget();

  private:
    void initUI();
};

#endif // SIGNINWIDGET_H