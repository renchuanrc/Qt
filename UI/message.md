### 窗口消息传递

例如：单击一个按钮，显示一个对话框（界面）

##### Qt:信号与槽
```
// 手动关联
1.在类中添加槽
public slots:
	void showChildDialog();//被信息调用的函数
2.在类中关联信号与槽
connect(
			ui->showChildButton,# 发送信号的对象
			SIGNAL(chicked()), # 发送的信号
			this, # 接收信号的对象
			SLOT(showChildDialog()) # 执行的槽
		);

// 自动关联
在类中添加槽，以 on_信号对象_发送信息 为函数槽名
public slots:
	void on_showChildButton_clicked();
```


##### iOS:委托代理