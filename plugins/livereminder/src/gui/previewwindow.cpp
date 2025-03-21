#include "previewwindow.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPushButton>
#include <QVBoxLayout>

PreviewWindow::PreviewWindow(QWidget* parent) : QWidget(parent) { initUI(); }

PreviewWindow::~PreviewWindow() {}

void PreviewWindow::initUI() {
  // 1. 创建布局
  layout = new QVBoxLayout;
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);
}

void PreviewWindow::onImportButtonClicked() {}
