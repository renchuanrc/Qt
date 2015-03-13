### Qt 简介

* 命名约定

```
下画线一般只用于类的数据成员
类名大写开头，函数名小写开头
类名为名词，函数名为动词
采用 CamelCase 方式构造单词
if() 语句中每一个变量应该近似一个句子，如 isQualified.

非布尔型获取器： color() 或 getColor()
布尔型获取器：isChecked() 或 isValid()
设置器： setColor(const Color& newColor)
```

* 核心模块

```
core —— 包含 QObject, QThread, QFile, Qvariant ...(默认启用)
gui —— 从 QWidget 派生的类(默认启用)
xml —— 解析和序列化 XML (QT += xml)
sql —— 与 SQL 数据库通信 (QT += sql)
phonon —— 多媒体处理
webkit —— 嵌入式 Web 浏览器，QtWebkit
```

* 流和日期
* 容器

```
QList<T> 少于1000项的列表
QStringList 派生自 QList<QString>
QLinkedList<T> 快速更新，但排序、搜索较慢
QVector<T> 更新较慢
QStack<T> 派生自 QVector<T>
QMap<Key,T> 有序关联，快速更新、搜索
QMultiMap<Key,T> QMap 的子类，允许一键多值
QHash<Key,T> 无序关联，快速插入，搜索较慢（一定存在时搜索快
QMultiHash<Key,T> QHash 的子类，允许一键多值
QCache<Key,T> 最快速的访问，自动移除不常用的项
QSet<T> 集合操作（并、交、差）
```