#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>

class TaskWidget : public QWidget {
    Q_OBJECT

  public:
    explicit TaskWidget(QWidget* parent = nullptr);
    ~TaskWidget() override;

  private:
    void initUI();
};

#endif // TASKWIDGET_H