#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QVBoxLayout;
class QWebEngineView;
class QPushButton;
class QString;

class MainWindow : public QWidget {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

  private:
    void initUI();

    QVBoxLayout*    layout;
    QWebEngineView* webView;
};

#endif // MAINWINDOW_H