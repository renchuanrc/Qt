#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
    class MyDialog;
}

class MyDialog : public QDialog
{
    /*
      使用QWidgt的信号槽功能必须添加 Q_OBJECT宏
      */
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

private:
    Ui::MyDialog *ui;
/*
 只有定义该信号的类及其子类才可以发射信号
 信号只用声明，不需要实现
 信号没有返回值
 */
signals:
    void dlgReturn(int);// 自定义的信号
private slots:
    void on_pushButton_clicked();
};

#endif // MYDIALOG_H
