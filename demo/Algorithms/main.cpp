#include <QtCore/QCoreApplication>

#include <QTextCodec>
#include <QVector>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    QStringList list;
    list << "one" << "two" << "three";

    qDebug()<<tr("qCopy()算法：");

    QVector<QString> vect(3);

    // 将 list 中所有的项目复制到 vect中

    qCopy(list.begin(),list.end(),vect.begin());
    qDebug()<<vect;

    qDebug()<<endl<<tr("qEaual()算法");
    // 从 list 的开始到结束的所有项目与vect的开始及其后面的等数量的项目
    // 进行比较，全部相同则返回 true

    bool ret1 = qEqual(list.begin(),list.end(),vect.begin());
    qDebug()<<"equal:"<<ret1;

    qDebug()<<endl<<tr("qFind()算法");
    //返回第一个对应的值的迭代器，如果没有找到，则返回 end()
    QList<QString>::iterator i = qFind(list.begin(),list.end(),"two");
    qDebug()<< *i;

    qDebug()<<endl<<tr("qFill()算法");
    qFill(list.begin(),list.end(),"eleven");
    qDebug()<<list;

    QList<int> list1;
    list1 << 3 << 3 << 6 << 6 << 6 << 8;

    qDebug()<<endl<<tr("qCount()算法");
    int countOf6 = 0;
    qCount(list1.begin(),list1.empty(),6,countOf6);
    qDebug()<<"countOf6:" << countOf6;

    return a.exec();
}
