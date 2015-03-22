#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
#include <QDebug>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mybutton *button = new mybutton(this);
    button->setText(tr("button"));

    mybutton *button2 = new mybutton;
    mybutton *button3 = new mybutton;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button2);
    layout->addWidget(button3);
    // 在该窗口中使用布局管理器
    setLayout(layout);

    //输出所有子部件的列表，目的：查看 layout 的子部件是否自动转
    //为当前窗口的子部件
    qDebug()<<children();
}

Widget::~Widget()
{
    delete ui;
    qDebug()<<"delete widget";
}
