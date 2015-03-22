## 事件

### Qt 事件系统

具体事件可查看文档：QEvent

* QResizeEvent 缩放事件
* QPaintEvent 绘制事件
* QMouseEvent 鼠标事件

```
mousePressEvent() -> QEvent::MouseButtonPress
mouseReleaseEvent() -> QEvent::MouseButtonRelease
mouseDoubleClickEvent() -> QEvent::MouseButtonDblClick
mouseMoveEvent() -> QEvent::MouseMove
```

* QKeyEvent 键盘事件

```
keyPressEvent() -> QEvent::KeyPress
keyReleaseEvent() -> QEvent::KeyRelease
focusInEvent() -> QEvent::FocusIn
focusOutEvent() -> QEvent::FocusOut
```

* QCloseEvent 关闭事件

* QTimerEvent 计时器事件

事件管理

* installEventFilter(QObject *) 安装事件过滤器
* eventFilter(QObject *,QEvent *); 处理监视事件
* sendEvent() 立即处理给定事件
* postEvent() 添加事件到事件队列，等待调用