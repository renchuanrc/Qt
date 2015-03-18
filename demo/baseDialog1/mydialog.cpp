#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    qDebug()<<"MyDialog::MyDialog - start";
    ui->setupUi(this);
    qDebug()<<"MyDialog::MyDialog - end";
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_toMain_clicked(){
    accept();// 当使用 exec() 来显示窗口时
    //done(2);
    //accept() 会返回 QDialog::Accepted 值
}
