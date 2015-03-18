### 资源管理

##### Qt资源系统


1. 新建 Qt 资源文件 xxx.qrc 来管理资源
2. 在项目目录文件夹下手动建立文件夹(目录层次不能高于qrc文件)，如 images
3. 双击 xxx.qrc 文件，选择“添加前缀”，如/images
4. 再选择“添加文件”

```
#xxx.qrc
<RCC> #RCC 表示Qt的资源类型
	<qresource prefix="/images">
		<file>images/new.png</file>
		<file>images/open.png</file>
	</qresource>
</RCC>

#main.pro
RESOURCES += xxx.qrc

#代码中使用图片
:/images/images/new.png
```