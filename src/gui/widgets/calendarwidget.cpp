#include "CalendarWidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>


CalendarWidget::CalendarWidget(QWidget* parent) :
    QWidget(parent), currentDate(QDate::currentDate()),
    displayedDate(QDate::currentDate()) {
  setupUI();
  updateCalendar(currentMonthWidget, displayedDate);
  updateCalendar(nextMonthWidget, displayedDate.addMonths(1));
}

void CalendarWidget::setupUI() {
  auto* mainLayout    = new QVBoxLayout(this);

  // 顶部切换按钮布局
  auto* headerLayout  = new QHBoxLayout();
  previousMonthButton = new QPushButton("<<", this);
  nextMonthButton     = new QPushButton(">>", this);

  connect(previousMonthButton, &QPushButton::clicked, this,
          &CalendarWidget::showPreviousMonth);
  connect(nextMonthButton, &QPushButton::clicked, this,
          &CalendarWidget::showNextMonth);

  headerLayout->addWidget(previousMonthButton);
  headerLayout->addStretch();
  headerLayout->addWidget(nextMonthButton);
  mainLayout->addLayout(headerLayout);

  // 滚动日历布局
  stackedWidget      = new QStackedWidget(this);
  currentMonthWidget = new QWidget(this);
  nextMonthWidget    = new QWidget(this);

  stackedWidget->addWidget(currentMonthWidget);
  stackedWidget->addWidget(nextMonthWidget);

  mainLayout->addWidget(stackedWidget);

  // 按钮组
  buttonGroup = new QButtonGroup(this);
  buttonGroup->setExclusive(true);

  setLayout(mainLayout);
}

void CalendarWidget::updateCalendar(QWidget* monthWidget, const QDate& date) {
  auto* layout = new QGridLayout(monthWidget);
  monthWidget->setLayout(layout);

  QDate firstDayOfMonth = QDate(date.year(), date.month(), 1);
  int   startDayOfWeek  = firstDayOfMonth.dayOfWeek();
  int   daysInMonth     = firstDayOfMonth.daysInMonth();

  // 清空布局和按钮
  QLayoutItem* item;
  while ((item = layout->takeAt(0)) != nullptr) {
    delete item->widget();
    delete item;
  }

  const QList<QAbstractButton*> buttons = buttonGroup->buttons();
  for (QAbstractButton* button : buttons) {
    buttonGroup->removeButton(button);
    delete button;
  }

  int day = 1;
  for (int row = 0; row < 6; ++row) {
    for (int col = 0; col < 7; ++col) {
      if (row == 0 && col < startDayOfWeek - 1) { continue; }
      if (day > daysInMonth) { break; }

      QPushButton* btn = new QPushButton(QString::number(day), this);
      btn->setCheckable(true);
      btn->setFixedSize(50, 50);
      btn->setStyleSheet(
          "QPushButton {"
          "background-color: #004c4c;"
          "color: white;"
          "border-radius: 25px;"
          "font-size: 14px;"
          "}"
          "QPushButton:hover { background-color: #005f5f; }"
          "QPushButton:checked { background-color: #ffffff; color: black; }");

      if (date.year() == currentDate.year() &&
          date.month() == currentDate.month() && day == currentDate.day()) {
        btn->setStyleSheet(btn->styleSheet() +
                           "QPushButton { background-color: #66c2c2; }");
      }

      layout->addWidget(btn, row, col);
      buttonGroup->addButton(btn);

      ++day;
    }
  }
}

void CalendarWidget::animateToNextMonth() {
  QPropertyAnimation* animation =
      new QPropertyAnimation(stackedWidget, "geometry");
  animation->setDuration(300);
  animation->setStartValue(stackedWidget->geometry());
  QRect endRect = stackedWidget->geometry();
  endRect.moveLeft(endRect.left() - stackedWidget->width());
  animation->setEndValue(endRect);

  connect(animation, &QPropertyAnimation::finished, this, [=]() {
    stackedWidget->setCurrentIndex((stackedWidget->currentIndex() + 1) % 2);
    updateCalendar(currentMonthWidget, displayedDate);
    updateCalendar(nextMonthWidget, displayedDate.addMonths(1));
    animation->deleteLater();
  });

  animation->start();
}

void CalendarWidget::animateToPreviousMonth() {
  QPropertyAnimation* animation =
      new QPropertyAnimation(stackedWidget, "geometry");
  animation->setDuration(300);
  animation->setStartValue(stackedWidget->geometry());
  QRect endRect = stackedWidget->geometry();
  endRect.moveLeft(endRect.left() + stackedWidget->width());
  animation->setEndValue(endRect);

  connect(animation, &QPropertyAnimation::finished, this, [=]() {
    stackedWidget->setCurrentIndex((stackedWidget->currentIndex() - 1 + 2) % 2);
    updateCalendar(currentMonthWidget, displayedDate);
    updateCalendar(nextMonthWidget, displayedDate.addMonths(1));
    animation->deleteLater();
  });

  animation->start();
}

void CalendarWidget::showPreviousMonth() {
  displayedDate = displayedDate.addMonths(-1);
  animateToPreviousMonth();
}

void CalendarWidget::showNextMonth() {
  displayedDate = displayedDate.addMonths(1);
  animateToNextMonth();
}

void CalendarWidget::onDateClicked(QAbstractButton* button) {
  // 按钮互斥逻辑通过 QButtonGroup 自动管理，无需额外操作
}
