### 应用程序运行流程

#### iOS
```
文件：AppDelegate.m
类　：AppDelegate : UIResponder <UIApplicationDelegate>
```

* 启动
`- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
`

* 当应用程序将要进入非活动状态时执行，在此期间，应用程序不接收消息或事件，比如来电话了
`- (void)applicationWillResignActive:(UIApplication *)application`

* 当应用程序进入活动状态时执行，这个刚好跟上面那个方法相反
`-  (void)applicationDidBecomeActive:(UIApplication *)application`

* 当程序被推送到后台的时候调用。
`- (void)applicationDidEnterBackground:(UIApplication  *)applicatio`

* 当程序从后台将要重新回到前台时候调用，这个刚好跟上面的那个方法相反。
`-  (void)applicationWillEnterForeground:(UIApplication *)application`

* 当程序将要退出是被调用，通常是用来保存数据和一些退出前的清理工作。
`-  (void)applicationWillTerminate:(UIApplication *)application`