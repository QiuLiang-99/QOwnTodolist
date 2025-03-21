#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QWidget>

class QVBoxLayout;
class QWebEngineView;
class QPushButton;

class PreviewWindow : public QWidget {
    Q_OBJECT

  public:
    explicit PreviewWindow(QWidget* parent = nullptr);
    ~PreviewWindow();

  private slots:
    void onImportButtonClicked();

  private:
    void initUI();

    QVBoxLayout*    layout;
    QWebEngineView* webView;
    QPushButton*    importButton;
    QVBoxLayout*    platformLayout;
};

#endif // PREVIEWWINDOW_H