## 本地化语言

#### Qt
在 Qt 中直接使用中文会出现乱码，需要在代码中引入 QTextCodec 类

```
...
#include <QTextCodec>

int main(int argc,char* argv[]){
    ...

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    label.setText(QObject::tr("Hello World!你好 Qt!"));
    ...
}

```

通常 setCodecForTr() 函数最好放置在 main 函数中，同时 Qt 程序中所有要显示到界面上的字符都使用 tr() 函数括起来，而对于不需要显示到界面上的字符串，如果包括中文，则可以使用 QString() 进行编码转换

```
QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

QString::fromUtf8("emptyDialog");
```