#ifndef FUNCTIONWIDGET_H
#define FUNCTIONWIDGET_H

#include <ElaScrollPage.h>

class FunctionWidget : public ElaScrollPage {
    Q_OBJECT

  public:
    explicit FunctionWidget(QWidget* parent = nullptr);
    ~FunctionWidget() override;
};

#endif // FUNCTIONWIDGET_H