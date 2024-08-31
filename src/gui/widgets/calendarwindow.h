#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include "functionwindow.h"

class CalendarWindow : public FunctionWindow {
    Q_OBJECT

  public:
    explicit CalendarWindow(QWidget* parent = nullptr);
    ~CalendarWindow() override;
};

#endif // CALENDARWINDOW_H