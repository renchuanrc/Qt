#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void showValue(int value);

    //�Զ�����
    void on_myButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
