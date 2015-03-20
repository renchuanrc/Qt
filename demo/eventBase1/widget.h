#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class lineEdit;

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    bool eventFilter(QObject *obj, QEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    // 鼠标事件
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;
    lineEdit *le;

    QPoint offset;// 用来存储鼠标指针位置与窗口位置的差值

    //解决按钮的自动重复（按着不放）
    bool keyUp;//向上方向键的标志
    bool keyLeft;
    bool wmove;//是否完成一次移动
};

#endif // WIDGET_H
