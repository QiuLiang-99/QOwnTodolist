#ifndef FUNCTIONWIDGET_H
#define FUNCTIONWIDGET_H

#include <QWidget>

class FunctionWidget : public QWidget {
    Q_OBJECT

  public:
    explicit FunctionWidget(QWidget* parent = nullptr);
    ~FunctionWidget() override;
};

#endif // FUNCTIONWIDGET_H