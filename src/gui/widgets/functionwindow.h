#ifndef FUNCTIONWINDOW_H
#define FUNCTIONWINDOW_H

#include <QWidget>

class FunctionWindow : public QWidget {
    Q_OBJECT

  public:
    explicit FunctionWindow(QWidget* parent = nullptr);
    ~FunctionWindow() override;
};

#endif // FUNCTIONWINDOW_H