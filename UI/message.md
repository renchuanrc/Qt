### 窗口消息传递

例如：单击一个按钮，显示一个对话框（界面）

#### Qt:信号与槽
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

// 在槽中可以继续发送信号
emit getText(lineEdit->text());//发射信号
```

##### 保护槽

###### 模式对话框 

* accept(); 隐藏模式对话框并且设置结果代码为Accepted。
* reject(); 隐藏模式对话框并且设置结果代码为Rejected
* done(int r); 隐藏模式对话框并且设置结果代码为r。
* setResult( int i );设置模式对话框的结果代码为i。

以上发送的信号会作为 `QDialog::exec()` 的返回值。（注意模式对话框会阻塞其它代码的执行，直到它返回一个值）

###### 非模式/半模式对话框 `QDialog::show`

非模式对话框马上返回值，不会阻塞代码的执行。

#### iOS:1.广播

```
NSString *messageName = "sayHi";
1.添加监听
[[NSNotificationCenter defaultCenter] //单例模式
	addObserver:self //添加监听者
	selector:@selector(toDoIfReceiveMessage) // 当接收到 name: 消息时执行此方法
	name:messageDoReceive // 想要接收的消息的名称
	object:nil // 用于过滤发送方
];

2.处理事件
-(void)toDoIfReceiveMessage:(NSNotification *)notification{
	NSDictionary *dic = [notification userInfo];#取到推送过来的字典数据
}

3.广播消息
[[NSNotificationCenter defaultCenter]
	postNotificationName:messageName //推送消息的名称
	object:nil //发送消息的实例
	userInfo:dictionary // 发送字典类型数据，如果没有可以写nil
];

监听事件 和 广播消息 可以放在不同的页面
适用于多个页面监听一个页面
```

#### iOS:2.协议委托

###### 视图A向视图B传递数据
```
1.委托方 A 定义协议
// controllerA.h
// 协议名通常是：委托方类名 + Delegate
@protocol controllerADelegate <NSObject>
	-(void)didDone:(NSString *)msg;
@end

2.委托方 A 定义代理
// controllerA.h
@interface controllerA : UIViewController
	//可以让遵守协议的控制器在彼此间交换信息
	@property (weak,nonatomic) id<controllerADelegate> delegate;
	// A 的某个公共参数
	@property (assing,nonatomic) NSInteger NumberCount;
...
@end

// controllerA.m 某个方法下的代码
[self.delegate didDone:"发送一条消息给B"];

3.代理方 B 遵守代理，设置接管对象，处理代理方法
//controllerB.h
#import "controllerA.h"
	@interface ViewController : UIViewController <controllerADelegate>
	...
@end

//controllerB.m
-(void)didDone:(NSString *)msg{
	# 在 B 中接收从 A 发送过来的信息 msg
}

或者
// prepareForSegue 在页面跳转时调用
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender{
	controllerA *controller = [segue destinationViewController];
	# 申请成为视图 A 代理，在跳转 A 时携带数据供 A 初始化时使用
	[controller setDelegate:self];#为视图A的delegate赋值
	[controller setNumberCount:xxx];//将xxx传到视图的A _NumberCount
}

适用于一个页面监听一个页面
```

##### 事件

```
//关闭窗口返回主界面(Modal segue)
[self dismissViewControllerAnimated:YES completion:nil];
```

#### 阅读资料

* [NSNotificationCenter](http://my.oschina.net/u/874588/blog/100323)