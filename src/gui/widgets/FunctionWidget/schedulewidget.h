#ifndef SCHEDULEWIDGET_H
#define SCHEDULEWIDGET_H

#include "FunctionWidget.h"
class QVBoxLayout;
class ElaTableView;
class ScheduleWidget : public FunctionWidget {
    Q_OBJECT

  public:
    explicit ScheduleWidget(QWidget* parent = nullptr);
    ~ScheduleWidget() override;

  private:
    void setupUi();
    void setupToolbars();

  private:
    QVBoxLayout* layout_;
    ElaTableView* _tableView;
};

#endif // SCHEDULEWIDGET_H