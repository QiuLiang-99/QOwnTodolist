#include "gui/mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QDesktopServices>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow   w;
  w.show();
  return a.exec();
}
