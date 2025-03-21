#include "gui/signinwidget.h"

#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QDesktopServices>

#include <QTimer>
#include <QUrl>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  SignInWidget w;
  w.show();
  return a.exec();
}
