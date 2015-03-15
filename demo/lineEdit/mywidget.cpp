#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QValidator>
#include <QCompleter>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 1.显示模式
    // 2.输入掩码
    ui->lineEdit2->setInputMask(">AA-90-bb-! aa\#H;*");
    // 3.输入验证
    QValidator *validator = new QIntValidator(100,999,this);
    ui->lineEdit3->setValidator(validator);
    // 4.自动补全
    QStringList wordList;
    wordList << "Qt" << "Qt Creator" << tr("你好");
    QCompleter *completer = new QCompleter(wordList,this);
    completer->setCaseSensitivity(Qt::CaseSensitive);//大小写不敏感
    ui->lineEdit4->setCompleter(completer);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_lineEdit2_returnPressed()
{
    ui->lineEdit3->setFocus();//获取焦点
    qDebug()<<ui->lineEdit2->text();//输出内容
    qDebug()<<ui->lineEdit2->displayText();//输出显示内容
}
