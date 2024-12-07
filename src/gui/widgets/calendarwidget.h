#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QButtonGroup>
#include <QDate>
#include <QGridLayout>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>


class CalendarWidget : public QWidget {
    Q_OBJECT

  public:
    explicit CalendarWidget(QWidget* parent = nullptr);

  private slots:
    void onDateClicked(QAbstractButton* button);
    void showPreviousMonth();
    void showNextMonth();

  private:
    void setupUI();
    void updateCalendar(QWidget* monthWidget, const QDate& date);

    QStackedWidget* stackedWidget;
    QButtonGroup*   buttonGroup;
    QPushButton*    previousMonthButton;
    QPushButton*    nextMonthButton;

    QDate    currentDate;
    QDate    displayedDate;
    QWidget* currentMonthWidget;
    QWidget* nextMonthWidget;

    void animateToNextMonth();
    void animateToPreviousMonth();
};

#endif // CALENDARWIDGET_H
