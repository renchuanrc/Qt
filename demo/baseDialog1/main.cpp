#include <QtGui/QApplication>
#include "mywidget.h"
#include <QTextCodec>

#include "mydialog.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    MyWidget w;
    MyDialog dialog;
    qDebug()<<"dialog init end";

    int msg = dialog.exec();
    qDebug()<<"dialog.exec():"<<msg;
    if (msg == QDialog::Accepted){//ÅÐ¶Ï dialog Ö´ÐÐÐ§¹û
        w.show();
        return a.exec();
    }
    else return 0;
}
