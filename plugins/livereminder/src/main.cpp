#include "gui/mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QDesktopServices>
#include <qlogging.h>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow   w;
  qDebug() << "Current working directory:"
           << QCoreApplication::applicationDirPath();
  w.show();
  return a.exec();
}
