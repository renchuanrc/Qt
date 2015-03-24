#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ���� pushButton �ı���Ϊ��ɫ
//    ui->pushButton->setStyleSheet("background:yellow");
//    ui->horizontalSlider->setStyleSheet("background:blue");

   // setStyleSheet("QPushButton{background:yellow}QSlider{background:grey}");
    QFile file(":/qss/my.qss");
    // ֻ����ʽ�򿪸��ļ�
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());// tr() ת��ΪQString����
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