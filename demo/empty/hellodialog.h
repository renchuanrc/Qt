#ifndef HELLODIALOG_H
#define HELLODIALOG_H

#include <QDialog>

namespace Ui{ //定义命名空间Ui
    class emptyDialog;
    // 前置声明 emptyDialog 类，加快编译速度
    // 界面设计的头文件（运行项目即可自动生成）
}

class HelloDialog : public QDialog
{
    Q_OBJECT // Q_OBJECT 宏，扩展 C++ 类功能
    // 比如信号和槽功能，必须在类定义最开始处
public:
    explicit HelloDialog(QWidget *parent = 0);
    // 显示构造函数，指定父窗口
signals:

public slots:

private:
    Ui::emptyDialog *ui;//指向界面
};

#endif // HELLODIALOG_H
