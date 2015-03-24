#include <QtCore/QCoreApplication>
#include <QTextCodec>
#include <QDebug>
#include <QStringList>

void QstringEdit(){
    qDebug()<<QObject::tr("以下是编辑字符串操作")<<endl;

    QString str = "Hello";
    qDebug()<<"string size:"<<str.size();
    qDebug()<<"string length"<<str.length();

    str[0] = QChar('h');
    qDebug()<<QObject::tr("第一个字符修改后：")<< str;

    str.append(" Qt");
    str.replace(1,4,"i");
    str.insert(2," my");
    qDebug()<<"str:"<<str;

    str = str + "!!!";
    qDebug()<<QObject::tr("使用加号连接：")<<str;

    str="hi\r\n Qt!\n ";
    qDebug()<<QObject::tr("str=")<<str;

    QString str1 = str.trimmed();//除去字符串两端的空白
    qDebug()<<QObject::tr("str1:")<<str1;

    QString str2 = str.simplified();// 去除两端及中间多余的空白
    qDebug()<<QObject::tr("str2:")<<str2;

    str = "hi,my,,Qt";
    //从字符串中有 ， 的地方将其分为多个子字符串
    // QString::SkipEmptyParts 表示跳过空的项目
    QStringList list = str.split(",",QString::SkipEmptyParts);
    qDebug()<<QObject::tr("str拆分后为：")<<list;

    str = list.join(" ");//组合
    qDebug()<<QObject::tr("list组全后为：")<<str;

    qDebug()<<QString().isNull();
    qDebug()<<QString().isEmpty();
    qDebug()<<QString("").isNull();
    qDebug()<<QString("").isEmpty();
}

void QstringQuery(){
    qDebug()<<QObject::tr("以下是在字符串中进行查询操作：");

    QString str="yafeilinux";
    qDebug()<<QObject::tr("字符串为：")<<str;

    // 执行下面一行代码后，结果为 linux
    qDebug()<<QObject::tr("包含右侧5个字符串子字符串：")<<str.right(5);
    qDebug()<<QObject::tr("包含左侧5个字行串的子字符串：")<<str.left(5);

    //执行下面一行代码后，结果为fei
    qDebug()<<QObject::tr("包含第2个字符以后3个字符的子字符串：")<<str.mid(2,3);
    qDebug()<<QObject::tr("fei的位置：")<<str.indexOf("fei");
    qDebug()<<QObject::tr("str的第0个字符串：")<<str.at(0);
    qDebug()<<QObject::tr("str中i字符的个数：")<<str.count('i');

    qDebug()<<QObject::tr("str是否以ya开始？")<<str.startsWith("ya");
    qDebug()<<QObject::tr("是否以linux结尾？")<<str.endsWith("linux");
    qDebug()<<QObject::tr("str是否包含lin字符串？")<<str.contains("lin");

    QString temp = "hello";

    if (temp > str)
        qDebug()<<temp;
    else
        qDebug()<<str;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    qDebug()<<QObject::tr("以下是字符串的转换操作：")<<endl;

    QString str="100";
    qDebug()<<QObject::tr("字符串转换为整数")<<str.toInt();

    int num = 45;
    qDebug()<<QObject::tr("整数转换为字符串：")<<QString::number(num);

    str = "FF";
    bool ok;

    int hex = str.toInt(&ok,16);
    // 结果为 ok: true 255
    qDebug()<<"ok"<<ok<<QObject::tr("转换为16进制：")<<hex;

    num = 26;
    qDebug()<<QObject::tr("使用16进制将整数转换为字符串：")
            <<QString::number(num,16);
    str="123.456";
    qDebug()<<QObject::tr("字符串转换为浮点型：")<<str.toFloat();

    str = "abc";
    qDebug()<<QObject::tr("转换为大写：")<<str.toUpper();
    str = "ABC";
    qDebug()<<QObject::tr("转换为小写：")<<str.toLower();

    int age = 25;
    QString name = "yafie";
    // name 代替 %1,age 代替2%
    str = QString("name is %1,age is %2").arg(name).arg(age);
    qDebug()<<QObject::tr("更改后的str为：")<<str;

    str="%1 %2";
    qDebug()<<str.arg("1f","hello");
    qDebug()<<str.arg("1f").arg("hello");

    str = QString("ni %1").arg("hi",5,'x');//???
    qDebug()<<QObject::tr("设置字段宽度为5，使用'*'填充：")<<str;

    qreal value = 123.456;
    str = QString("number:%1").arg(value,0,'f',2);
    qDebug()<<QObject::tr("设置小数点位数为两位：")<<str;

    // 执行下面一行代码，结果为number：123.45 不会显示引号
    qDebug()<<QObject::tr("将str转换为const char*:")<<qPrintable(str);

    return a.exec();

}
