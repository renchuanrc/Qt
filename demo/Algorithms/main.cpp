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

    qDebug()<<QObject::tr("qCopy()算法：");

    QVector<QString> vect(3);

    // 将 list 中所有的项目复制到 vect中

    qCopy(list.begin(),list.end(),vect.begin());
    qDebug()<<vect;

    qDebug()<<endl<<QObject::tr("qEaual()算法");
    // 从 list 的开始到结束的所有项目与vect的开始及其后面的等数量的项目
    // 进行比较，全部相同则返回 true

    bool ret1 = qEqual(list.begin(),list.end(),vect.begin());
    qDebug()<<"equal:"<<ret1;

    qDebug()<<endl<<QObject::tr("qFind()算法");
    //返回第一个对应的值的迭代器，如果没有找到，则返回 end()
    QList<QString>::iterator i = qFind(list.begin(),list.end(),"two");
    qDebug()<< *i;

    qDebug()<<endl<<QObject::tr("qFill()算法");
    qFill(list.begin(),list.end(),"eleven");
    qDebug()<<list;

    QList<int> list1;
    list1 << 3 << 3 << 6 << 6 << 6 << 8;

    qDebug()<<endl<<QObject::tr("qCount()算法");
    int countOf6 = 0;
    qCount(list1.begin(),list1.end(),6,countOf6);
    qDebug()<<"countOf6:" << countOf6;

    qDebug()<<endl<<QObject::tr("qLowerBound()算法");
    // 返回第一个出现5的位置，如果没有5，则返回5应该在的位置
    // list1 被查找的范围中的项目必须是升序
    QList<int>::iterator j = qLowerBound(list1.begin(),list1.end(),5);
    list1.insert(j,5);
    qDebug()<<list1;

    QList<int> list2;
    list2 << 33 << 12 << 68 << 6 << 12;
    qDebug()<<endl<<QObject::tr("qSort()算法");
    qSort(list2.begin(),list2.end());
    qDebug()<<list2;

    qDebug()<<endl<<QObject::tr("qSwap()算法");
    double pi = 3.14;
    double e = 2.71;
    qSwap(pi,e);
    qDebug()<<"pi:"<<pi<<";e:"<<e;


    return a.exec();
}
