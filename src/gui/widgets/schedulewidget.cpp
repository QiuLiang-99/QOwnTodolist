#include "schedulewidget.h"
#include <qboxlayout.h>
#include <qpushbutton.h>

ScheduleWidget::ScheduleWidget(QWidget* parent) : FunctionWindow(parent) {
      auto layout = new QVBoxLayout(this);
  auto button = new QPushButton("导入", this);
  layout->addWidget(button);
  setLayout(layout);
}

ScheduleWidget::~ScheduleWidget() {}