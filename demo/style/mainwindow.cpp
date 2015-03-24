#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWindowsXPStyle>
#include <QDebug>
#include <QStyleFactory>

//调色板
#include <QPalette>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //单个部件使用风格
    ui->progressBar->setStyle(new QWindowsXPStyle);

    //打印当前系统所支持的风格
    qDebug()<<QStyleFactory::keys();

    //获取 pushButton 的调色板
    QPalette palette1 = ui->pushButton->palette();
    //设置按钮文本颜色为红色
    palette1.setColor(QPalette::ButtonText,Qt::red);
    //设置按钮背景色为绿色
    palette1.setColor(QPalette::Button,Qt::green);
    //pushButton使用修改后的调色板
    ui->pushButton->setPalette(palette1);

    //设置 lineEdit 不可用
    ui->lineEdit->setDisabled(true);
    QPalette palette2 = ui->lineEdit->palette();
    //设置行编辑器不可用时的背景颜色为蓝色
    palette2.setColor(QPalette::Disabled,QPalette::Base,Qt::blue);
    ui->lineEdit->setPalette(palette2);
    qDebug()<<Qt::red;
}

MainWindow::~MainWindow()
{
    delete ui;
}
