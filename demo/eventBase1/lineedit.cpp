#include "lineedit.h"

#include <QKeyEvent>
#include <QDebug>

lineEdit::lineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void lineEdit::keyPressEvent(QKeyEvent *event)
{

    qDebug()<<tr("LineEdit 键盘被点击")<<event->text();
    //执行QLineEdit类的默认处理
    QLineEdit::keyPressEvent(event);
    event->ignore();//如果不忽略，事件不会冒泡出去
}

bool lineEdit::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
        qDebug()<<tr("lineEdit 的 event() 函数");
    return QLineEdit::event(event);
}
