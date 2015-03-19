### 文件操作

#### 数据流 QMimeData
```
# 写入数据
QByteArray itemData;
QDataStream dataStream(&itemData,QIODevice::WriteOnly);
dataStream << 数据1 << 数据2;
// 将数据封装到自定义的 QMimeData 中
QMimeData *mimeData = new QMimeData;
mimeData->setData("myimage/png",itemData);

# 读取数据
if (mimeData->hasFormat("myimage/png")){
	QByteArray itemData = mimeData->data("myimage/png");
	QDataStream dataStream(&itemData,QIODevice::ReadOnly);
	dataStream >> 数据1 >> 数据2;
}
```