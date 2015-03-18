#include "mywidget.h"
#include "ui_mywidget.h"

//基本布局管理器
#include <QHBoxLayout>
//栅局布局管理器
#include <QGridLayout>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
/*
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(ui->fontComboBox);
    layout->addWidget(ui->textEdit);
    layout->setSpacing(50);//部件间隔
    layout->setContentsMargins(0,0,50,100);//左，上，右，下
    setLayout(layout);
*/
/*
    QGridLayout *layout = new QGridLayout;
    //添加部件，从第0行0列开始，占据1行2列
    layout->addWidget(ui->fontComboBox,
                      0,0,1,2);
    //从0行2列开始，占据1行1列
    layout->addWidget(ui->pushButton,
                      0,2,1,1);
    //从1行0列开始，占据1行3列
    layout->addWidget(ui->textEdit,
                      1,0,1,3);
    setLayout(layout);
*/

}

myWidget::~myWidget()
{
    delete ui;
}
// 隐藏窗口按钮
void myWidget::on_pushButton_toggled(bool checked)
{
    ui->textEdit->setVisible(checked);
    if (checked)
        ui->pushButton->setText(tr("隐藏可扩展窗口"));
    else
        ui->pushButton->setText(tr("显示可扩展窗口"));
}
