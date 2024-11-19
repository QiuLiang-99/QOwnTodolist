#include "mainwindow.h"
// #include "gui/widgets/calendarwindow.h"
#include "widgets/FunctionWidget/schedulewidget.h"
#include <ElaDockWidget.h>
#include <ElaMenu.h>
#include <ElaMenuBar.h>
#include <ElaProgressBar.h>
#include <ElaStatusBar.h>
#include <ElaText.h>
#include <ElaToolBar.h>
#include <ElaToolButton.h>
#include <QSettings>
#include <QVBoxLayout>
#include <qwidget.h>

static MainWindow* self = nullptr;
MainWindow*        MainWindow::instance() { return self; }

MainWindow::MainWindow(QWidget* parent) : ElaWindow(parent) {
  self = this;
  // setIsEnableMica(true);
  setWindowIcon(QIcon(":/include/Image/Cirno.jpg"));
  // resize(1200, 740);
  //  ElaLog::getInstance()->initMessageLog(true);
  //  eApp->setThemeMode(ElaThemeType::Dark);
  //  setIsNavigationBarEnable(false);
  //  setNavigationBarDisplayMode(ElaNavigationType::Compact);
  //  setWindowButtonFlag(ElaAppBarType::MinimizeButtonHint, false);
  //  setUserInfoCardPixmap(QPixmap(":/Resource/Image/Cirno.jpg"));
  setUserInfoCardTitle("Q  L  ");
  // setUserInfoCardSubTitle("Liniyous@gmail.com");
  setWindowTitle("QOwnTodolist");
  // setIsStayTop(true);
  // setUserInfoCardVisible(false);

  readSettings();
  setupUi();
  setupFunctionWidgets();
}

MainWindow::~MainWindow() { storeSettings(); }

void MainWindow::setupUi() {
  // 菜单栏
  ElaMenuBar* menuBar = new ElaMenuBar(this);
  menuBar->setFixedHeight(30);
  QWidget*     customWidget = new QWidget(this);
  QVBoxLayout* customLayout = new QVBoxLayout(customWidget);
  customLayout->setContentsMargins(0, 0, 0, 0);
  customLayout->addWidget(menuBar);
  customLayout->addStretch();
  // this->setMenuBar(menuBar);
  this->setCustomWidget(customWidget);
  this->setCustomWidgetMaximumWidth(500);

  menuBar->addElaIconAction(ElaIconType::AtomSimple, "动作菜单");
  ElaMenu* iconMenu = menuBar->addMenu(ElaIconType::Aperture, "图标菜单");
  iconMenu->setMenuItemHeight(27);
  iconMenu->addElaIconAction(ElaIconType::BoxCheck, "排序方式",
                             QKeySequence::SelectAll);
  iconMenu->addElaIconAction(ElaIconType::Copy, "复制");
  iconMenu->addElaIconAction(ElaIconType::MagnifyingGlassPlus, "显示设置");
  iconMenu->addSeparator();
  iconMenu->addElaIconAction(ElaIconType::ArrowRotateRight, "刷新");
  iconMenu->addElaIconAction(ElaIconType::ArrowRotateLeft, "撤销");
  // menuBar->addSeparator();
  ElaMenu* shortCutMenu = new ElaMenu("快捷菜单(&A)", this);
  shortCutMenu->setMenuItemHeight(27);
  shortCutMenu->addElaIconAction(ElaIconType::BoxCheck, "排序方式",
                                 QKeySequence::Find);
  shortCutMenu->addElaIconAction(ElaIconType::Copy, "复制");
  shortCutMenu->addElaIconAction(ElaIconType::MagnifyingGlassPlus, "显示设置");
  shortCutMenu->addSeparator();
  shortCutMenu->addElaIconAction(ElaIconType::ArrowRotateRight, "刷新");
  shortCutMenu->addElaIconAction(ElaIconType::ArrowRotateLeft, "撤销");
  menuBar->addMenu(shortCutMenu);

  menuBar->addMenu("样例菜单(&B)")
      ->addElaIconAction(ElaIconType::ArrowRotateRight, "样例选项");
  menuBar->addMenu("样例菜单(&C)")
      ->addElaIconAction(ElaIconType::ArrowRotateRight, "样例选项");
  menuBar->addMenu("样例菜单(&D)")
      ->addElaIconAction(ElaIconType::ArrowRotateRight, "样例选项");
  menuBar->addMenu("样例菜单(&E)")
      ->addElaIconAction(ElaIconType::ArrowRotateRight, "样例选项");
  menuBar->addMenu("样例菜单(&F)")
      ->addElaIconAction(ElaIconType::ArrowRotateRight, "样例选项");
  menuBar->addMenu("样例菜单(&G)")
      ->addElaIconAction(ElaIconType::ArrowRotateRight, "样例选项");

  // 工具栏
  ElaToolBar* toolBar = new ElaToolBar("工具栏", this);
  toolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
  toolBar->setToolBarSpacing(3);
  toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
  toolBar->setIconSize(QSize(25, 25));
  // toolBar->setFloatable(false);
  // toolBar->setMovable(false);
  ElaToolButton* toolButton1 = new ElaToolButton(this);
  toolButton1->setElaIcon(ElaIconType::BadgeCheck);
  toolBar->addWidget(toolButton1);
  ElaToolButton* toolButton2 = new ElaToolButton(this);
  toolButton2->setElaIcon(ElaIconType::ChartUser);
  toolBar->addWidget(toolButton2);
  toolBar->addSeparator();
  ElaToolButton* toolButton3 = new ElaToolButton(this);
  toolButton3->setElaIcon(ElaIconType::Bluetooth);
  toolButton3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  toolButton3->setText("Bluetooth");
  toolBar->addWidget(toolButton3);
  ElaToolButton* toolButton4 = new ElaToolButton(this);
  toolButton4->setElaIcon(ElaIconType::BringFront);
  toolBar->addWidget(toolButton4);
  toolBar->addSeparator();
  ElaToolButton* toolButton5 = new ElaToolButton(this);
  toolButton5->setElaIcon(ElaIconType::ChartSimple);
  toolBar->addWidget(toolButton5);
  ElaToolButton* toolButton6 = new ElaToolButton(this);
  toolButton6->setElaIcon(ElaIconType::FaceClouds);
  toolBar->addWidget(toolButton6);
  ElaToolButton* toolButton8 = new ElaToolButton(this);
  toolButton8->setElaIcon(ElaIconType::Aperture);
  toolBar->addWidget(toolButton8);
  ElaToolButton* toolButton9 = new ElaToolButton(this);
  toolButton9->setElaIcon(ElaIconType::ChartMixed);
  toolBar->addWidget(toolButton9);
  ElaToolButton* toolButton10 = new ElaToolButton(this);
  toolButton10->setElaIcon(ElaIconType::Coins);
  toolBar->addWidget(toolButton10);
  ElaToolButton* toolButton11 = new ElaToolButton(this);
  toolButton11->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  toolButton11->setElaIcon(ElaIconType::AlarmPlus);
  toolButton11->setText("AlarmPlus");
  toolBar->addWidget(toolButton11);
  ElaToolButton* toolButton12 = new ElaToolButton(this);
  toolButton12->setElaIcon(ElaIconType::Crown);
  toolBar->addWidget(toolButton12);
  QAction* test = new QAction(this);
  test->setMenu(new QMenu(this));

  ElaProgressBar* progressBar = new ElaProgressBar(this);
  progressBar->setMinimum(0);
  progressBar->setMaximum(0);
  progressBar->setFixedWidth(350);
  toolBar->addWidget(progressBar);

  this->addToolBar(Qt::TopToolBarArea, toolBar);

  // 停靠窗口
  ElaDockWidget* logDockWidget = new ElaDockWidget("日志信息", this);
  // logDockWidget->setWidget(new T_LogWidget(this));
  this->addDockWidget(Qt::RightDockWidgetArea, logDockWidget);
  resizeDocks({logDockWidget}, {200}, Qt::Horizontal);

  ElaDockWidget* updateDockWidget = new ElaDockWidget("更新内容", this);
  // updateDockWidget->setWidget(new T_UpdateWidget(this));
  this->addDockWidget(Qt::RightDockWidgetArea, updateDockWidget);
  resizeDocks({updateDockWidget}, {200}, Qt::Horizontal);

  // 状态栏
  ElaStatusBar* statusBar  = new ElaStatusBar(this);
  ElaText*      statusText = new ElaText("初始化成功！", this);
  statusText->setTextPixelSize(14);
  statusBar->addWidget(statusText);
  this->setStatusBar(statusBar);
}
void MainWindow::setupFunctionWidgets() {
  // 左侧按钮列表
  addPageNode("HOME", new QWidget, ElaIconType::House);
  addPageNode("课表", new ScheduleWidget, ElaIconType::Calendar);
}

void MainWindow::setupToolbars() {}

void MainWindow::readSettings() {
  QSettings settings;
  restoreGeometry(
      settings.value(QStringLiteral("MainWindow/geometry")).toByteArray());
  // 为什么他们要延时一秒再恢复窗口的位置和大小？
  // QTimer::singleShot(1, this, [this] {  });
}
void MainWindow::storeSettings() {
  QSettings settings;

  // don't store the window settings in distraction free mode
  // if (!isInDistractionFreeMode()) {
  settings.setValue(QStringLiteral("MainWindow/geometry"), saveGeometry());
  // settings.setValue(QStringLiteral("MainWindow/menuBarGeometry"),ui->menuBar->saveGeometry());
  // }

  // store a NoteHistoryItem to open the note again after the app started
  /*const NoteHistoryItem noteHistoryItem(&currentNote, ui->noteTextEdit);
  qDebug() << __func__ << " - 'noteHistoryItem': " << noteHistoryItem;
  settings.setValue(QStringLiteral("ActiveNoteHistoryItem"),
                    QVariant::fromValue(noteHistoryItem));*/

  // store the note history of the current note folder
  /*noteHistory.storeForCurrentNoteFolder();*/

  /* Utils::Gui::storeNoteTabs(ui->noteEditTabWidget);*/
}