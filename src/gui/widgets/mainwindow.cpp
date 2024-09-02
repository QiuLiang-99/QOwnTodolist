#include "mainwindow.h"
#include "gui/component/verticalsidebar.h"
#include <QAction>
#include <QGridLayout>
#include <QPushButton>
#include <QSettings>
#include <QTimer>
#include <QToolBar>
#include <qlogging.h>
#include <qwidget.h>

static MainWindow* self = nullptr;
MainWindow*        MainWindow::instance() { return self; }

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  self = this;
  qDebug() << this->layout();
  readSettings();
  setupUi();
}

MainWindow::~MainWindow() { storeSettings(); }

void MainWindow::setupUi() {
  m_layout          = new QGridLayout;
  QPushButton* test = new QPushButton("Hello World");
  m_layout->addWidget(test, 0, 0);
  setupToolbars();
  setCentralWidget(new QWidget);
  centralWidget()->setLayout(m_layout);

  _sidebar = new VerticalSidebar(this);
}

void MainWindow::setupToolbars() {
  _quitToolbar         = new QToolBar(tr("quit toolbar"));
  QAction* action_Quit = new QAction(tr("Quit"), this);
  _quitToolbar->addAction(action_Quit);
  _quitToolbar->setObjectName(QStringLiteral("quitToolbar"));
  connect(action_Quit, &QAction::triggered, this, [&] {
    qDebug() << "ojbk";
  });
  addToolBar(_quitToolbar);
  // m_layout->addWidget(_quitToolbar, 0, 1);
}

void MainWindow::readSettings() {
  QSettings settings;
  restoreGeometry(
      settings.value(QStringLiteral("MainWindow/geometry")).toByteArray());
  // 为什么他们要延时一秒再恢复窗口的位置和大小？
  // QTimer::singleShot(1, this, [this] {  });
}
void MainWindow::storeSettings() {
  QSettings settings;

  // don't store the window settings in distraction free mode
  // if (!isInDistractionFreeMode()) {
  settings.setValue(QStringLiteral("MainWindow/geometry"), saveGeometry());
  // settings.setValue(QStringLiteral("MainWindow/menuBarGeometry"),ui->menuBar->saveGeometry());
  // }

  // store a NoteHistoryItem to open the note again after the app started
  /*const NoteHistoryItem noteHistoryItem(&currentNote, ui->noteTextEdit);
  qDebug() << __func__ << " - 'noteHistoryItem': " << noteHistoryItem;
  settings.setValue(QStringLiteral("ActiveNoteHistoryItem"),
                    QVariant::fromValue(noteHistoryItem));*/

  // store the note history of the current note folder
  /*noteHistory.storeForCurrentNoteFolder();*/

  /* Utils::Gui::storeNoteTabs(ui->noteEditTabWidget);*/
}