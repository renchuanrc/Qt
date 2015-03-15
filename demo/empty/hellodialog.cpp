#include "hellodialog.h"
#include "ui_emptydialog.h"

HelloDialog::HelloDialog(QWidget *parent) :
    QDialog(parent)
{
    ui = new Ui::emptyDialog;
    //为这个类所代表的对话框创建界面
    ui->setupUi(this);
}
