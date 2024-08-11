#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

  public:
    static MainWindow* instance();

  public:
    void setupUi();
    void setupToolbars();
    void readSettings();
    void storeSettings();

  private:
    QToolBar* _quitToolbar;
};
#endif // MAINWINDOW_H
