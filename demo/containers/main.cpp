#include <QtCore/QCoreApplication>
#include <QList>
#include <QMap>
#include <QDebug>

#include <QListIterator>
#include <QMutableListIterator>

#include <QMapIterator>
#include <QMutableMapIterator>

void qListDemo();
void qListInteratorDemo();
void qListMutableInteratorDemo();

void qMapDemo();
void qMapInteratorDemo();

void qListSTLIterator();

void foreachDemo();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //qListDemo();
    //qMapDemo();

    // Java 风格迭代器
    //qListInteratorDemo();
    //qListMutableInteratorDemo();
    //qMapInteratorDemo();

    // STL 风格迭代器
    //qListSTLIterator();

    foreachDemo();

    return a.exec();
}

void foreachDemo(){
    QList<QString> list;
    list.insert(0,"A");
    list << "B" <<"C"<<"D";
    qDebug()<<"the lsit is:";
    foreach( QString str,list){
        qDebug()<<str;
    }

    QMap<QString,int> map;
    map.insert("first",1);
    map.insert("second",3);
    map.insert("third",2);
    qDebug()<<endl<<"the map is:";
    foreach (QString str, map.keys()){
        qDebug()<<str<<":"<<map.value(str);
    }

    QMultiMap<QString,int> map2;
    map2.insert("first",1);
    map2.insert("first",2);
    map2.insert("first",3);
    map2.insert("second",2);
    qDebug()<<endl<<"the map2 is:";

    QList<QString> keys = map2.uniqueKeys();//返回所有键列表
    foreach(QString str,keys){
        foreach(int i,map2.values(str))
            qDebug()<<str<<":"<<i;
    }
}

void qListSTLIterator(){
    QList<QString> list;
    list << "A" <<"B"<<"C"<<"D";

    QList<QString>::iterator i;// 读写迭代器
    qDebug()<<"the forward is:";
    for (i=list.begin(); i != list.end(); ++i){
        *i = (*i).toLower();
        qDebug() << *i;
    }

    qDebug()<<"the backward is:";
    while (i != list.begin()){
        --i;
        qDebug()<<*i;
    }

    QList<QString>::const_iterator j;//只读迭代器
    qDebug()<<"the forward is:";
    for (j = list.constBegin(); j != list.constEnd(); ++j){
        qDebug()<<*j;
    }
}

void qMapInteratorDemo(){
    QMap<QString,QString> map;
    map.insert("Paris","France");
    map.insert("Guatemala City","Guatemala");
    map.insert("Mexico City","Mexico");
    map.insert("Moscow","Russia");

    QMapIterator<QString,QString> i(map);

    while(i.hasNext()){
        i.next();
        qDebug()<<i.key()<<":"<<i.value();
    }

    if (i.findPrevious("Mexico"))
        qDebug()<<"find Mexico";

    QMutableMapIterator<QString,QString> j(map);
    while(j.hasNext()){
        if (j.next().key().endsWith("City")){
            j.remove();
        }
    }
    while(j.hasPrevious()){
        j.previous();
        qDebug()<<j.key()<<":"<<j.value();
    }
}

void qListMutableInteratorDemo(){
    QList<QString> list;
    list <<"A"<<"B"<<"C"<<"D"<<"E";
    QMutableListIterator<QString> j(list);

    while(j.hasPrevious()){
        QString str = j.previous();
        if (str == "B")
            j.remove();
    }

    j.insert("Q");
    j.toBack();
    if(j.hasPrevious())
        j.previous() = "N";//直接赋值
    j.previous();
    j.setValue("M");
    j.toFront();

    // 正向遍历
    qDebug()<<"the forward is:";
    while(j.hasNext())
        qDebug()<<j.next();
}

void qListInteratorDemo(){
    QList<QString> list;
    list <<"A"<<"B"<<"C"<<"D";

    QListIterator<QString> i(list);
    qDebug()<<"the forward is:";
    // 正向遍历
    while (i.hasNext())
        qDebug()<<i.next();

    // 返回遍历
    qDebug()<<"the backward is:";
    while( i.hasPrevious())
        qDebug()<<i.previous();
}

void qMapDemo(){
    QMap<QString,int>map;
    map["one"] = 1;
    map["three"] = 3;
    map.insert("seven",7);

    // 获取键的值，如果没有该键，那么会自动插入
    int value1 = map["six"];
    qDebug()<<"value1:"<<value1;
    qDebug()<<"contains 'six'?"<<map.contains("six");

    // 使用value()获取键的值，如果没有该键，不会自动插入
    int value2 = map.value("five");
    qDebug()<<"value2:"<<value2;
    qDebug()<<"contains 'five'?"<<map.contains("five");

    // 当键不存在时，为该键设置值
    int value3 = map.value("nine",9);
    qDebug()<<"value3:"<<value3;

    // map 默认是一个键汪个值，如果重新给该键设置为值，那么以前的值会被替换
    map.insert("ten",10);
    map.insert("ten",100);
    qDebug()<<"ten:"<<map.value("ten");

    //可以使用 insertMulti()实现一键多值，然后使用 vlaues() 获取值
    map.insertMulti("two",2);
    map.insertMulti("two",4);
    QList<int> values = map.values("two");
    qDebug()<<"two:"<<values;

    // 也可以使用 QMultiMap 来实现一键多值
    QMultiMap<QString,int>map1,map2,map3;
    map1.insert("vs",1);
    map1.insert("vs",2);
    map1.insert("vs",3);
    // 可以进行相加
    map3 = map1 + map2;
    QList<int> myValues = map3.values("vs");
    for (int i = 0; i<myValues.size();++i){
        qDebug()<<myValues.at(i);
    }
}

void qListDemo(){
    QList<QString> list;
    // 插入项目
    list << "aa" << "bb" << "cc";
    if (list[1] == "bb")
        list[1] = "ab";
    list.replace(2,"bc");

    //输出整个项目
    qDebug()<<"the list is:";
    for( int i = 0; i<list.size(); ++i){
        qDebug()<<list.at(i);
    }

    // 追加
    list.append("dd");
    list.prepend("mm");

    // 删除并获取
    QString str = list.takeAt(2);
    qDebug()<<"at(2) item is:"<<str;

    qDebug()<<"the list is:";
    for( int i = 0; i<list.size(); ++i){
        qDebug()<<list.at(i);
    }

    // 插入
    list.insert(2,"mm");
    list.swap(1,3);
    qDebug()<<"the list is:";
    for( int i = 0; i<list.size(); ++i){
        qDebug()<<list.at(i);
    }

    qDebug()<<"contains 'mm'?"<<list.contains("mm");
    qDebug()<<"the 'mm' count:"<<list.count("mm");
    //第一个mm的位置
    qDebug()<<"first 'mm' index:"<<list.indexOf("mm");
    // 第二个mm的位置
    qDebug()<<"second 'mm' index:"<<list.indexOf("mm",1);
}
