#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QGridLayout;

class VerticalSidebar;
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
    QGridLayout*     m_layout;
    QToolBar*        _quitToolbar;
    VerticalSidebar* _sidebar;
};
#endif // MAINWINDOW_H
