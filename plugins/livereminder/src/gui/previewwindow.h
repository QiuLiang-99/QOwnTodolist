#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include "previewwindowmodel.h"
#include <QWidget>

class QVBoxLayout;
class QWebEngineView;
class QPushButton;
class PreviewWindowModel;
class PreviewWindow : public QWidget {
    Q_OBJECT

  public:
    explicit PreviewWindow(QWidget* parent = nullptr);
    ~PreviewWindow();
    void                setModel(PreviewWindowModel* model);
    PreviewWindowModel* Model() const;

  protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
    // 鼠标悬停事件处理
  private slots:
    void onImportButtonClicked();

  private:
    void initUI();

    QVBoxLayout*        layout;
    QWebEngineView*     webView;
    QPushButton*        importButton;
    QVBoxLayout*        platformLayout;
    PreviewWindowModel* model; // 预览窗口模型
};

#endif // PREVIEWWINDOW_H