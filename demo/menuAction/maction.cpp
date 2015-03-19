#include "maction.h"

#include <QLineEdit>
#include <QSplitter>
#include <QLabel>

mAction::mAction(QObject *parent) :
    QWidgetAction(parent)
{
    lineEdit = new QLineEdit;

    //将行编辑器的按下回车键信号与我们的发送文本槽函数关联
    connect(
                lineEdit,
                SIGNAL(returnPressed()),
                this,
                SLOT(sendText())
                );
}

// 当使用到该类的对象并将其添加到一个部件上时，就会自动调用该函数
// 创建部件
QWidget* mAction::createWidget(QWidget *parent){
    //这里使用 inherits()函数判断父部件是否是菜单或者工具栏
    // 如果是，则创建该部件的子部件，并且返回子部件
    // 如果不是，则直接返回0
    if (parent->inherits("QMenu") || parent->inherits("QToolBar")){

        QLabel *label = new QLabel;
        label->setText(tr("插入文本"));

        // 创建分裂器
        QSplitter *splitter = new QSplitter(parent);
        splitter->addWidget(label);
        splitter->addWidget(lineEdit);
        return splitter;
    }
    return 0;
}


void mAction::sendText(){
    emit getText(lineEdit->text());//发射信号
    lineEdit->clear();//清空行编辑器
}
