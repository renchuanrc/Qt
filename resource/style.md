### 样式

##### Qt 风格

* 调色板 QPalette
* Qt样式表 setStyleSheet

```
# 换皮肤 Qt Style Sheets Examples
QFile file(":/qss/xx.qss");
file.open(QFile::ReadOnly);
QString styleSheet = tr(file.readAll());
qApp->setStyleSheet(styleSheet);
```

* 不规则窗件（遮罩）setMask
* 透明窗体 setWindowOpacity
