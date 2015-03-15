#include <QtGui>

int main(int argc,char *argv[]){
    QApplication a(argc,argv);

    QWidget widget;
    widget.show();

    int x = widget.x();
    int y = widget.y();

    QRect geometry = widget.geometry();
    QRect frame = widget.frameGeometry();

    return a.exec();
}

int mainDemo1(int argc,char *argv[]){
    QApplication a(argc,argv);

    // 代码中使用中文字符
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    // 新建 QWidget 类对象，独立窗口
    QWidget *widget = new QWidget(0,Qt::Dialog);
    widget->setWindowTitle(QObject::tr("我是widget"));

    // 新建 QLable，独立窗口
    QLabel *label = new QLabel(0,Qt::Dialog);
    label->setWindowTitle(QObject::tr("我是label"));
    label->setText(QObject::tr("label:我是个窗口"));
    label->resize(180,20);

    // 新建子窗口
    QLabel *label2 = new QLabel(widget);
    label2->setText(QObject::tr("我不是独立的窗口"));
    label2->resize(250,20);

    // 在屏幕上显示出来
    label->show();
    widget->show();

    int ret = a.exec();
    delete label;
    delete widget;
    return ret;
}
