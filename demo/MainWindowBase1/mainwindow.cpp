#include "mainwindow.h"
#include "ui_mainwindow.h"

// 工具栏添加其它窗口部件
#include <QToolButton>
#include <QSpinBox>

// 状态栏信息
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //添加编辑菜单
    QMenu *editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    //为菜单添加Action
    QAction *action_Open = editMenu->addAction(
                QIcon(":/images/images/open.png"),
                tr("打开文件(&O)")
                );
    //设置快捷键
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    //将Action添加到工具栏
    ui->mainToolBar->addAction(action_Open);

    // QAction 组，可以设置单选
    QActionGroup *group = new QActionGroup(this);
    QAction *action_L = group->addAction(tr("左对齐(&L)"));
    // 设置是否选中状态
    action_L->setCheckable(true);
    QAction *action_R = group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction *action_C = group->addAction(tr("居中对齐(&C)"));
    action_C->setCheckable(true);
    // 添加间隔线
    editMenu->addSeparator();
    // 向菜单中添加动作
    editMenu->addAction(action_L);
    editMenu->addAction(action_C);
    editMenu->addAction(action_R);

    //在工具栏添加其它窗口部件
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText(tr("颜色"));
    //设置弹出方式
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolBtn);

    //创建一个菜单
    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBtn->setMenu(colorMenu);

    QSpinBox *spinBox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinBox);

    //向状态栏添加信息
    // 显示临时信息，显示 2000 毫秒即 2秒钟
    ui->statusBar->showMessage(tr("欢迎使用多文档编辑器"),2000);
    // 创建标签
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setText("2015-03-18");
    ui->statusBar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <QTextEdit>
#include <QMdiSubWindow>
void MainWindow::on_action_N_triggered()
{
    // 新建文本编辑器部件
    QTextEdit *edit = new QTextEdit(this);
    // 使用QMdiArea类的 addSubWindow()函数创建子窗口
    // 以文本编辑器为中心部件
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();
}

void MainWindow::on_showDock_triggered()
{
    if(ui->dockWidget->isVisible())
        ui->dockWidget->hide();
    else
        ui->dockWidget->show();
}
