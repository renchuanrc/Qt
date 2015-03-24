#include "widget.h"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



    qDebug()<<"-----------------";
    QRegExp rx4("(\\d+)");
    QString str4 = "Offsets:12 14 99 231 7";
    QStringList list;
    int pos2 = 0;
    while ((pos2 = rx4.indexIn(str4,pos2)) != -1){
        list << rx4.cap(1);//第一个捕获到的文本
        pos2 += rx4.matchedLength();//上一个匹配的字符串的长度
    }
    qDebug()<<list;

    QRegExp rxlen("(\\d+)(?:\\s*)(cm|inch)");
    int pos3 = rxlen.indexIn("Length:189cm");
    if (pos3 > -1){
        QString value = rxlen.cap(1);//189
        QString unit = rxlen.cap(2);//cm
        QString string = rxlen.cap(0);//189cm
        qDebug()<<value<<unit<<string;
    }

    QRegExp rx5("\\b(\\w+)\\W+\\1\\b");
    rx5.setCaseSensitivity(Qt::CaseInsensitive);
    qDebug()<<rx5.indexIn("Hello- -hello");//0
    qDebug()<<rx5.cap(1);//Hello

    QRegExp rx6("\\b你好\\b");
    qDebug()<<rx6.indexIn("你好");
    qDebug()<<rx6.cap(0);
}

Widget::~Widget()
{
    delete ui;
}

void pregTest(){
    QRegExp rx("^\\d\\d?$");//两个字符都必须是数字，第二个字符可以没有
    qDebug()<<rx.indexIn("a1");//-1
    qDebug()<<rx.indexIn("5");//0
    qDebug()<<rx.indexIn("5b");//-1
    qDebug()<<rx.indexIn("123");//-1

    qDebug()<<"**************";

    rx.setPattern("\\b(main|letter)\\b");
    qDebug()<<rx.indexIn("emailletter");
    qDebug()<<rx.indexIn("my mail");
    qDebug()<<rx.indexIn("m email letter");

    qDebug()<<"*************";
    rx.setPattern("M(?!ail)");//匹配字符串M，后面不能跟 ail
    QString str1="this is M";
    str1.replace(rx,"Mail");
    qDebug()<<"str1:"<<str1;

    QString str2 = "my M,your Ms,his Mail";
    str2.replace(rx,"Mail");
    qDebug()<<"str2:"<<str2;

    qDebug()<<"************";
    QString str3="One Eric another Erik,and an Eiric."
            "How many Eirik,ErickBBY?";
    QRegExp rx2("\\bEi?ri[ck]\\b");
    int pos = 0;
    int count = 0;
    while (pos >= 0){
        pos = rx2.indexIn(str3,pos);
        if (pos >= 0){
            ++pos;
            ++ count;
        }
    }
    qDebug()<<"count:"<<count;

    qDebug()<<"*****************";
    QRegExp rx3("*.txt");
    rx3.setPatternSyntax(QRegExp::Wildcard);//一种简单的模式匹配语法
    qDebug()<<rx3.exactMatch("README.txt");
    qDebug()<<rx3.exactMatch("welcome.txt.bak");
    qDebug()<<rx3.exactMatch("goodtxt");
}
