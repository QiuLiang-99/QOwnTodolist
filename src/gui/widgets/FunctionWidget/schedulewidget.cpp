#include "schedulewidget.h"
#include "core/schedule/scheduleparser.h"
#include <qboxlayout.h>
#include <qpushbutton.h>

ScheduleWidget::ScheduleWidget(QWidget* parent) : FunctionWidget(parent) {
  auto layout = new QVBoxLayout(this);
  auto button = new QPushButton("导入", this);
  layout->addWidget(button);
  setLayout(layout);
  connect(button, &QPushButton::clicked, this, []() {
    ScheduleParser::selectFile();
  });
}

ScheduleWidget::~ScheduleWidget() {}