#include "taskwidget.h"

#include <QHBoxLayout>

TaskWidget::TaskWidget(QWidget* parent) : QWidget(parent) { initUI(); }

TaskWidget::~TaskWidget() {}

void TaskWidget::initUI() {
  auto layout = new QHBoxLayout(this);
  setLayout(layout);
}
