#ifndef MACTION_H
#define MACTION_H

#include <QWidgetAction>

class QLineEdit;//前置声明？？

class mAction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit mAction(QObject *parent = 0);

protected:
    //声明函数，实现 QWidgetAction 类的虚函数
    QWidget* createWidget(QWidget *parent);

signals:
    // 信号，按下回车时，将行编辑器中的内容发射出去
    void getText(const QString &string);

public slots:
    // 槽，用来与编辑器的按下回车键信号关联
    void sendText();
private:
    //定义行编辑器对象的指针
    QLineEdit* lineEdit;

};

#endif // MACTION_H
