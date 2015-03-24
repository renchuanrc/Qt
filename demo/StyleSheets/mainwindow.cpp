#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置 pushButton 的背景为黄色
//    ui->pushButton->setStyleSheet("background:yellow");
//    ui->horizontalSlider->setStyleSheet("background:blue");

   // setStyleSheet("QPushButton{background:yellow}QSlider{background:grey}");
    QFile file(":/qss/my.qss");
    // 只读方式打开该文件
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());// tr() 转换为QString类型
    qApp->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file(":/qss/my1.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());
    qApp->setStyleSheet(styleSheet);
}
