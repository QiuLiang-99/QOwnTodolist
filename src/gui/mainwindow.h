#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ElaWindow.h>
class MainWindow : public ElaWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

  public:
    static MainWindow* instance();

  public:
    void setupUi();
    void setupToolbars();
    void setupFunctionWidgets();
    void readSettings();
    void storeSettings();

  private:
  //void addFunctionWidget(QWidget* widget, const QString& title, const QString& iconPath);

};
#endif // MAINWINDOW_H
