#include "mainwindow.h"

#include <QAction>
#include <QPushButton>
#include <QSettings>
#include <QTimer>
#include <QToolBar>

static MainWindow* self = nullptr;
MainWindow*        MainWindow::instance() { return self; }

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {

  self = this;
  readSettings();
  setupUi();
}

MainWindow::~MainWindow() { storeSettings(); }

void MainWindow::setupUi() {
  QPushButton* test = new QPushButton("Hello World", this);
  setupToolbars();
}

void MainWindow::setupToolbars() {
  _quitToolbar         = new QToolBar(tr("quit toolbar"), this);
  QAction* action_Quit = new QAction(tr("Quit"), this);
  _quitToolbar->addAction(action_Quit);
  _quitToolbar->setObjectName(QStringLiteral("quitToolbar"));
  addToolBar(_quitToolbar);
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