#include "widget.h"
#include "ui_widget.h"
#include "lineedit.h"
#include <QDebug>

#include <QMouseEvent>
#include <QCursor>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    le = new lineEdit(this);
    le->move(100,100);

    le->installEventFilter(this);

    QCursor cursor;//创建光标对象
    cursor.setShape(Qt::OpenHandCursor);//光标形状手掌
    setCursor(cursor);//使用光标

    // 设置鼠标跟踪
    //setMouseTracking(true);

    // 主界面获取焦点
    setFocus();

    keyUp = false;
    keyLeft = false;
    wmove = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    // 是否按下 ctrl 键
    if (event->modifiers() == Qt::ControlModifier){
        if (event->key() == Qt::Key_M)//是否按下M键
            setWindowState(Qt::WindowMaximized);
    } else if (event->key() == Qt::Key_Up){

        //qDebug()<<"press:"<<event->isAutoRepeat();//是否自动重复
        if (event->isAutoRepeat())
            return;
        keyUp = true;

    } else if(event->key() == Qt::Key_Left){

        if (event->isAutoRepeat())
            return;
        keyLeft = true;

    } else {
        qDebug() << tr("widget 被点击");
        QWidget::keyPressEvent(event);
    }

}
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
//        qDebug()<<"release:"<<event->isAutoRepeat();
//        qDebug()<<"up";
        if (event->isAutoRepeat())
            return;
        keyUp = false;
        if (wmove){
            wmove = false;
            return;
        }
        if (keyLeft){
            ui->pushButton->move(30,80);//斜移
            wmove = true;
        }else
            ui->pushButton->move(120,80);
    } else if(event->key() == Qt::Key_Left){
        if (event->isAutoRepeat())
            return;
        if (wmove){
            wmove = false;
            return;
        }
        if (keyUp){
            ui->pushButton->move(30,80);
            wmove = true;
        }else{
            ui->pushButton->move(30,120);
        }
    } else if (event->key() == Qt::Key_Down){
        ui->pushButton->move(120,120);
    }
}

// 事件过滤器
bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == le){
        if (event->type() == QEvent::KeyPress)
            qDebug()<<tr("Widget 的事件过滤器");
    }
    return QWidget::eventFilter(obj,event);
}
// 鼠标按下事件
void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        //暂时改变形状
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();
    } else if (event->button() == Qt::RightButton){
        QPixmap *px = new QPixmap(":/images/66.png");
        QCursor cursor(px->scaledToWidth(20));
        QApplication::setOverrideCursor(cursor);
    }
}
// 鼠标移动事件
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    // 这里必须使用 buttons ，鼠标移动时无法检测哪个键被按下
    if (event->buttons() && Qt::LeftButton){
        QPoint temp;
        // globalPos() 鼠标指针的位置
        temp = event->globalPos() - offset;
        move(temp);
    }
}
// 释放事件，恢复形状
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QApplication::restoreOverrideCursor();
}
// 双击事件
void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        if (windowState() != Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else
            setWindowState(Qt::WindowNoState);
    }
}
// 滑轮事件
void Widget::wheelEvent(QWheelEvent *event)
{
    //当滚轮远离使用者
    if (event->delta() > 0)
        ui->textEdit->zoomIn();
    else
        ui->textEdit->zoomOut();
}


