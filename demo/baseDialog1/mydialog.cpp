#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_toMain_clicked(){
    accept();// 当使用 exec() 来显示窗口时
    //accept() 会返回 QDialog::Accepted 值
}
