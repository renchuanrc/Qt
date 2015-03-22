## 容器类

### Qt 顺序容器

##### QList

* 数组，快速地基于索引访问，数量小于1000时性能较好
* QList::append(), QList::prepend()
* QList::insert()
* QStringList 继承自 QList<QString>

##### QLinkedList 链表

* 使用迭代器访问
* insert 操作具有更好的性能

##### QVector

* 连续的内存空间
* prepend 和 insert 操作非常缓慢

##### QStack

* QVector 的子类
* 添加了 push(), pop(), top() 等操作

##### QQueue

* QList 的子类
* 添加了 enqueue(), dequeue(),head() 等操作

### Qt 关联容器

##### QSet<T>

* 快速查询单值数学集

##### QMap / QMultiMap

* 字典（关联数组）
* 键有序

##### QHash / QMultiHash

* 查找速度更快
* 无序

### 迭代器


* 只读迭代器 QXxxIterator<T> , QXxx<T>::const_iterator
* 读写迭代器 QMutableXxxIterator<T> , QXxx<T>::iterator
* Qt foreach()

```
# java 风格
QListIterator<QString> i<list>;
while (i.hasNext()){
	qDebug()<<i.next();
}

# STL 风格
QList<QString>::const_iterator i;
for (i = list.begin(); i != list.end(); ++i)
	qDebug()<< *i;

# foreach 风格，比 PHP 的 foreach 麻烦
foreach (type Value,array)
```

### 通用算法

* STL 算法 > Qt 算法