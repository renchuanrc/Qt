### 新建项目

#### 项目(应用)类别

* Qt C++ 项目 -> Qt Gui 相当于 iOS:Single View Application
* 其他项目 -> 空的 Qt 项目 相当于 iOS:Empty Application

#### 非空项目文件比较

| | Qt | iOS |
| --- | --- | --- |
| 项目信息文件 | *.pro | *.xcodeproj |
| 入口文件 | main.cpp | main.m |
| 流程控制文件 | | AppDelegate.h + AppDelegate.m |
| 类文件 | *.h + *.cpp | *.h + *.m |
| 界面文件 | *.ui | *.storyboard |
| 配置文件 | *.pro | info.plist |

#### 空项目文件比较

| | Qt | iOS |
| --- | --- | --- |
| 项目信息文件 | *.pro | *.xcodeproj |
| 入口文件 |  | main.m |
| 流程控制文件 | | AppDelegate.h + AppDelegate.m |
| 类文件 |  |  |
| 界面文件 |  |  |
| 配置文件 | *.pro | info.plist |

#### 空项目类文件

* 入口文件 main

```
// Qt 需要手动建立 (文件->C++源文件)

#include <QApplication>
#include <QDialog>
#include <QLabel>

int main(int argc,char * argv[]){
    QApplication a(argc,argv);
    QDialog w;
    QLabel label(&w);
    label.setText("Hello World!你好 Qt!");
    w.show(); //形成窗口
    return a.exec();
}

// iOS 不需要建立 main.m

#import <UIKit/UIKit.h>
#import <AppDelegate.h>

int main(int argc,char * argv[]){
	@autoreleasepool{
		return UIApplicationMain(argc,argv,nil,NSStringFromClass([AppDelegate class]))
	}
}
```

iOS 的 UIKit.h 包含了绝大部分常用的头文件（表单控件等），但在 Qt 中这些控件需要手动导入，所以这里的 `#import <UIKit/UIKit.h> 可以看作 #include <QDialog>
#include <QLabel>`

QApplication 用于管理应用程序，通过 `a.exec()` 让 QApplication 对象进入事件循环，相当于 iOS 中的 `UIApplicationMain()`

在 iOS 的 AppDelegate.h 文件中，有一个窗体 `@property (strong,nonatomic) UIWindow *window` 相当于 Qt 的 `QDialog w`，可以简单理解为主窗件。

Qt 可以将视图代码直接写在 main.cpp 中，但在 iOS 中，很少这样做。大多数情况下两者都是通过新建类文件来控制逻辑。

#### 项目文件介绍

```
// Qt *.pro

QT += core gui #项目模块，core 为 非图形用户界面核心功能， gui 扩展了 core 模块的图形界面功能

TARGET = helloworld # 生成的 exe 文件名称
TEMPLAE = app # 使用 app 模板，表明这是个应用程序

SOURCES += main.cpp\ # 源文件
		hellodialog.cpp

HEADERS += hellodialog.h # 头文件

FORMS += hellodialog.ui # 界面文件

RC_FILE += myico.rc # 应用程序图标

// Qt *.pro.user
本地构建信息，含Qt版本、构建目录，因系统环境而不同
一般桌面程序不需要包含
```

#### 资料

* [QDialog](UI/window.md#QDialog)