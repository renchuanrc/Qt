## Qt 对象模型

##### 对象通信机制 —— signal and slots

* signal 和 slots 之间可以是多对多的关系
* 在非一对一情况下，执行顺序是随机的
* emit 发射信号
* QObject::sender() 和 QSignalMapper 信号映射器


##### 对象属性系统 (object properties)
##### 事件和事件过滤器 (events and event filters)
##### 国际化字符串翻译机制
##### 定时器驱动 (timers)
##### 对象树 (object trees)

* 确保对象能够正确销毁


##### 守卫指针 (QPointer)
##### 动态对象转换机制 (dynamic cast)