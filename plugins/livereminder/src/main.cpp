#include "core/livestatusfetcher.h"
#include "gui/mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QDesktopServices>
#include <qlogging.h>

#include "gui/signinwidget.h"
int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow   w;
  w.show();
  ////PreviewWindow previewWindow;
  ////previewWindow.show();
  ////callApi();
  SignInWidget s;
  s.show();
  LiveStatusFetcher client;
  const QString url = "https://www.huya.com/chuhe";
  // 可选质量参数，例如 "TX" 或 "HW"，此处使用默认第一档
  StreamData info = client.getStreamInfo(url, "TX");

  qDebug() << "Anchor:" << info.anchorName;
  if (!info.isLive) {
      qDebug() << "The stream is currently offline.";
  } else {
      qDebug() << "Title: " << info.title;
      qDebug() << "M3U8 URL: " << info.m3u8Url;
      qDebug() << "FLV URL: " << info.flvUrl;
      qDebug() << "Record URL: " << info.recordUrl;
  }
  return a.exec();
}
