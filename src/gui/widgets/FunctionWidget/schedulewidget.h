#ifndef SCHEDULEWIDGET_H
#define SCHEDULEWIDGET_H

#include "FunctionWidget.h"

class ScheduleWidget : public FunctionWidget {
    Q_OBJECT

  public:
    explicit ScheduleWidget(QWidget* parent = nullptr);
    ~ScheduleWidget() override;
};

#endif // SCHEDULEWIDGET_H