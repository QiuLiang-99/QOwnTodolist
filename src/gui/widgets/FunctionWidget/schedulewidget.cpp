#include "schedulewidget.h"
#include "ElaTableView.h"
#include "ElaText.h"
#include "core/schedule/scheduleparser.h"
#include <QHeaderView>
#include <QVBoxLayout>
#include <qboxlayout.h>
#include <qpushbutton.h>

ScheduleWidget::ScheduleWidget(QWidget* parent) : FunctionWidget(parent) {
  layout_             = new QVBoxLayout(this);
  QPushButton* button = new QPushButton("导入", this);
  layout_->addWidget(button);
  setLayout(layout_);
  connect(button, &QPushButton::clicked, this, []() {
    ScheduleParser::selectFile();
  });

  setupUi();
  setupToolbars();
}

ScheduleWidget::~ScheduleWidget() {}

void ScheduleWidget::setupUi() {
  // ElaTableView
  ElaText* tableText = new ElaText("ElaTableView", this);
  tableText->setTextPixelSize(18);
  _tableView            = new ElaTableView(this);
  QFont tableHeaderFont = _tableView->horizontalHeader()->font();
  tableHeaderFont.setPixelSize(16);
  _tableView->horizontalHeader()->setFont(tableHeaderFont);
  //_tableView->setModel(new T_TableViewModel(this));
  _tableView->setAlternatingRowColors(true);
  _tableView->setIconSize(QSize(38, 38));
  _tableView->verticalHeader()->setHidden(true);
  _tableView->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Interactive);
  _tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
  _tableView->horizontalHeader()->setMinimumSectionSize(60);
  _tableView->verticalHeader()->setMinimumSectionSize(46);
  _tableView->setFixedHeight(450);
  connect(_tableView, &ElaTableView::tableViewShow, [this]() {
    _tableView->setColumnWidth(0, 60);
    _tableView->setColumnWidth(1, 205);
    _tableView->setColumnWidth(2, 170);
    _tableView->setColumnWidth(3, 150);
    _tableView->setColumnWidth(4, 60);
  });
}

void ScheduleWidget::setupToolbars() {}