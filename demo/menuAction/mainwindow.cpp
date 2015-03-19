#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "maction.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu *editmenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    //添加菜单并且加入action
    mAction *action = new mAction;
    editmenu->addAction(action);

    connect(
                action,
                SIGNAL(getText(QString)),
                this,
                SLOT(setText(QString))
                );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setText(const QString &string)
{
    ui->textEdit->setText(string);
}
