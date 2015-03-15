#include "mywidget.h"
#include "ui_mywidget.h"
#include <QMenu>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 指定 Alt+N 为快速键
    ui->pushButton->setText(tr("&nihao"));

    ui->pushButton_2->setText(tr("帮助(&H"));
    ui->pushButton_2->setIcon(QIcon("E:/Qt/images/help.jpg"));

    ui->pushButton_3->setText(tr("z&oom"));
    QMenu *menu = new QMenu(this);
    menu->addAction(QIcon("E:/Qt/images/zoom-in.jpg"),tr("扩大"));
    ui->pushButton_3->setMenu(menu);
}

MyWidget::~MyWidget()
{
    delete ui;
}

#include <QDebug>
void MyWidget::on_pushButton_toggled(bool checked)
{
    qDebug()<<tr("按钮是否按下：")<<checked;
}

#include <QButtonGroup>
void MyWidget::on_showSelectResult_clicked()
{
    qDebug()<<tr("跑步：")<<ui->checkBox->isChecked();
    qDebug()<<tr("踢球：")<<ui->checkBox_2->isChecked();
    qDebug()<<tr("游泳：")<<ui->checkBox_3->isChecked();

//    QButtonGroup *buttonGroup = new QButtonGroup(this);
//    buttonGroup->addButton(ui->radioButton,0);
//    buttonGroup->addButton(ui->radioButton_2,1);
//    buttonGroup->addButton(ui->radioButton_3,2);
//    如何使用？

}
