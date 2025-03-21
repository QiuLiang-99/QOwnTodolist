#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QCalendarWidget>
#include <QDate>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>


class CalendarWidget : public QWidget {
    Q_OBJECT

  public:
    explicit CalendarWidget(QWidget* parent = nullptr);

  private:
    QCalendarWidget* calendar;  // 日历控件
    QLabel*          infoLabel; // 显示选中日期信息的标签

  private slots:
    void onDateSelected(const QDate& date); // 日期选中时的槽函数
};

#endif // CALENDARWIDGET_H
