#include "widget.h"
#include "ui_widget.h"

#include <QPixmap>
#include <QBitmap>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pix;
    //加载图片
    pix.load(":/rc/images/bg.png");
    //设置窗口大小为图片大小
    resize(pix.size());
    //为窗口设遮罩
    setMask(pix.mask());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //从窗口左上角开始绘制图片
    painter.drawPixmap(0,0,QPixmap(":/rc/images/bg.png"));
}

void Widget::mousePressEvent(QMouseEvent *)
{
    close();
}
