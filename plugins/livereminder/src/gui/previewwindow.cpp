#include "previewwindow.h"
#include "previewwindowmodel.h"
#include <QDebug>
#include <QEvent>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWebEngineView>

PreviewWindow::PreviewWindow(QWidget* parent) : QWidget(parent) { initUI(); }

PreviewWindow::~PreviewWindow() {}

void PreviewWindow::setModel(PreviewWindowModel* model) { this->model = model; }

PreviewWindowModel* PreviewWindow::Model() const { return model; }

void PreviewWindow::initUI() {
  // 创建布局
  layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);

  // 创建 WebView，用于显示图片/直播
  webView = new QWebEngineView(this);
  layout->addWidget(webView);

  // 设置初始内容：一张图片
  QString imageHtml =
      R"(
      <html>
        <head><style>body { margin: 0; }</style></head>
        <body>
          <img src='https://i.imgur.com/ExdKOOz.png' width='100%' height='100%' />
        </body>
      </html>
      )";
  webView->setHtml(imageHtml);

  // 启用鼠标事件监控
  webView->installEventFilter(this);

  // 可选：导入按钮（根据你的类定义）
  importButton = new QPushButton("导入", this);
  layout->addWidget(importButton);

  connect(importButton, &QPushButton::clicked, this,
          &PreviewWindow::onImportButtonClicked);
}

void PreviewWindow::onImportButtonClicked() { qDebug() << "导入按钮被点击"; }

// 鼠标悬停事件处理
bool PreviewWindow::eventFilter(QObject* obj, QEvent* event) {
  if (obj == webView) {
    if (event->type() == QEvent::Enter) {
      // 鼠标进入：切换为直播流
      webView->load(QUrl("https://live.bilibili.com/6")); // 示例：B站直播
    } else if (event->type() == QEvent::Leave) {
      // 鼠标离开：切换回图片
      QString imageHtml =
          R"(
          <html>
            <head><style>body { margin: 0; }</style></head>
            <body>
              <img src='https://i.imgur.com/ExdKOOz.png' width='100%' height='100%' />
            </body>
          </html>
          )";
      webView->setHtml(imageHtml);
    }
  }
  return QWidget::eventFilter(obj, event);
}
