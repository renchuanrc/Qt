### C++ 简介

* 编译

```
g++ -Wall fac.cpp
g++ -Wall -o execFile fac.cpp

-Wall 用于获取编译过程中的调试信息
```

* 命名空间

`using namespace std;`

* 标准输入与输出

```
#include <iostream>
1. cin 控制台输入，默认为键盘
2. cout 控制台输出，默认为控制台屏幕
3. cerr 控制台错误
```

* 函数重载
* qmake, 工程文件及 Makefile

```
make 只会重新编译发生变化（或受影响）的文件
makefile 格式" 目标:依赖 命令"
---- makefile start
main : overload.cpp
        g++ -o main overload.cpp # 注意前面的 tab
---- makefile end
```

* #include 查找头文件

```
#include <headerFile>
#include "headerFile"
#include "path/to/headerFile"
```

* 字符串

```
1. const char* # C 语言风格
2. string # C++ 标准库
3. QString # Qt
```

* 文件流

```
#include <fstream>
ofstream write;
ifstream read;
```

* const 关键字
* 运算符 new 和 delete

### 类与对象

* struct

```
struct Fraction {
	int number, denom;
	string description;
}
```

* 类定义

```
class ClassName {
	public:
		publicMembers
	private:
		privateMembers
};
```

* 成员访问限定符

```
public:
protected:
private:
```

* 类的友元

```
class Timer {
	friend class Clock; // 友元类，Clock 所有成员函数都可以访问 Timer:: m_Elapsed
	friend void Time::toString(); // 友元函数
	friend ostream& operator << (ostream& os,const Timer& obj);
	[...]
private:
	long m_Elapsed;
};
```

* 构造函数

与类同名，不返回任何值
```
//定义语法
ClassName::ClassName( parameterList )
	:initList // 可选，成员初始化列表
	{
		constructor body
	}
```

* 析构函数

```
ClassName:: ~ClassName(){
	
}
```

* static 关键字

```
staic 局部变量：静态存储类，首次处理时会创建并初始化
static 类成员：与类本身相关联的数据，一般可以代替全局变量
staic 全局变量：符号文件作用域，告知链接器不要将这个符号输出到程序的其他部分
块作用域内 staic 变量：第一次运行时创建并初始化
```

* 复制构造函数 与 赋值运算符

```
// 复制构造函数
ClassName (const ClassName &x);
// 赋值运算符
ClassName& operator= (const ClassName &x);
```

* const 成员函数

```
ClassName::FunctionName( parameterList ) const; // 不修改主对象状态
ClassName::FunctionName( const parameter ); // 参数不会被修改
```

### 容器

### 函数

* 函数重载

* 可选实参

```
void date(int d = 0, int m = 0, int y = 0)
```

* 运算符重载

* 按值传递

* 按引用传递

* 从函数返回引用

```
int& max(int& x, int& y){
	return (x > y) ? x : y;
}

int& max( int i, int j){
	int r = i > j ? i : j;
	return r; // 返回局部对象的引用
}
```

* inline 函数

```
inline int max(int a,int b){
	return a > b ? a : b;
}
int main(){
	int temp = max(3,5);
}
// 编译器将 inline 声明的函数展开，性能提高，内存占用变大
// define 是由 预处理器展开
int main(){
	int temp;
	{
		int a = 3;
		int b = 5;
		temp = a > b ? a : b;
	}
}
```

* 带变长实参表的函数

```
#include <cstdarg>
int printf(char* formatStr,...)
```

### 继承与多态

* 继承

```
class SubClass : public ParentClass {}
```

* 多态 virtual

```
virtual 方法为 Java 中的成员函数默认的方法，通常要求要有一个 virtual 析构函数

Parent* p = new Child();
p->say();
如果 say() 没有 virtual ，那么调用的是 Parent 的 say()
如果 say() 有 virtual ， 那么调用的是 Child 的 say()

注意：重载发生在同一作用域下
如果 say() 有 virtual，那么 Child::say 会隐藏 Parent 中全部函数名为 say 的函数。此时只有 Parent 对象才能调用 Parent 中的 say 方法
```

* 抽象基类的派生

```
纯虚函数
virtual returnType FunctionName (parameterList) = 0;
```

* 特殊成员函数

```
# 不会被继承的成员函数
1.复制构造函数
2.复制赋值运算符
3.构造函数
原因：基类无法初始化、复制或销毁子类的实例
```