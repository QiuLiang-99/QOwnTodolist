#include "gui/mainwindow.h"
#include "gui/previewwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QDesktopServices>
#include <qlogging.h>

int main(int argc, char* argv[]) {
  QApplication  a(argc, argv);
  MainWindow    w;
  PreviewWindow previewWindow;
  previewWindow.show();
  w.show();
  return a.exec();
}
