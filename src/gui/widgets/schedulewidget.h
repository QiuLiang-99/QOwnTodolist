#ifndef SCHEDULEWIDGET_H
#define SCHEDULEWIDGET_H

#include "functionwindow.h"

class ScheduleWidget : public FunctionWindow {
    Q_OBJECT

  public:
    explicit ScheduleWidget(QWidget* parent = nullptr);
    ~ScheduleWidget() override;
};

#endif // SCHEDULEWIDGET_H