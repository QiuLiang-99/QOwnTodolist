#include "mainwindow.h"
#include <QPushButton>
#include <QToolBar>
#include <qaction.h>
static MainWindow* self = nullptr;
MainWindow*        MainWindow::instance() { return self; }

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  self = this;
  setupUi();
}

MainWindow::~MainWindow() {}

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