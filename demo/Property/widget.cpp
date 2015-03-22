#include "widget.h"
#include "ui_widget.h"
#include "myclass.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyClass *my = new MyClass(this);
    connect(my,
            SIGNAL(userNameChanged(QString)),
            this,
            SLOT(userChanged(QString)));
    //修改属性的值
    my->setUserName("yafei");
    qDebug()<<"userName:"<<my->getUserName();

    my->setProperty("userName","linux");
    //输出属性的值
    qDebug()<<"userName:"<<my->property("userName").toString();

    //再添加自定义属性，对其它对象无效
    my->setProperty("myValue",10);
    qDebug()<<"myValue:"<<my->property("myValue").toInt();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::userChanged(QString username){
    qDebug()<<"user changed:"<<username;
}
