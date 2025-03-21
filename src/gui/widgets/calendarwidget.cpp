#include "CalendarWidget.h"

CalendarWidget::CalendarWidget(QWidget* parent) :
    QWidget(parent), calendar(new QCalendarWidget(this)),
    infoLabel(new QLabel("请选择日期", this)) {
  // 配置日历控件
  calendar->setGridVisible(true); // 显示网格
  calendar->setSelectionMode(QCalendarWidget::SingleSelection);

  // 自定义样式表
  calendar->setStyleSheet("QCalendarWidget {"
                          "    background-color: #004c4c;"
                          "    color: white;"
                          "    font-size: 14px;"
                          "}"
                          "QCalendarWidget QAbstractItemView:enabled {"
                          "    selection-background-color: white;"
                          "    selection-color: black;"
                          "    border-radius: 5px;"
                          "}"
                          "QCalendarWidget QWidget {"
                          "    alternate-background-color: #006666;"
                          "}"
                          "QCalendarWidget QToolButton {"
                          "    background-color: #005f5f;"
                          "    color: white;"
                          "    border: none;"
                          "    font-size: 14px;"
                          "}"
                          "QCalendarWidget QToolButton:hover {"
                          "    background-color: #007f7f;"
                          "}"
                          "QCalendarWidget QToolButton:pressed {"
                          "    background-color: #009f9f;"
                          "}"
                          "QCalendarWidget QTableView {"
                          "    border: none;"
                          "    gridline-color: #007f7f;"
                          "}");

  // 信号与槽连接
  connect(calendar, &QCalendarWidget::clicked, this,
          &CalendarWidget::onDateSelected);

  // 布局
  QVBoxLayout* mainLayout = new QVBoxLayout(this);
  mainLayout->addWidget(calendar);
  mainLayout->addWidget(infoLabel);

  setLayout(mainLayout);
  resize(600, 500); // 设置窗口大小
}

void CalendarWidget::onDateSelected(const QDate& date) {
  // 更新选中日期的信息
  infoLabel->setText("选中日期: " + date.toString("yyyy-MM-dd"));
}
