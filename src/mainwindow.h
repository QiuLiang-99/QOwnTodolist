#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

  public:
    static MainWindow* instance();

  public:
    void setupUi();
    void setupToolbars();

  private:
    QToolBar* _quitToolbar;
};
#endif // MAINWINDOW_H
