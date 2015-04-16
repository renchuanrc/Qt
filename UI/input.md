### 窗口部件

##### QFrame

带有边框的部件的基类，子类包括

* QLabel 标签
* QLCDNumber 液晶显示
* QSplitter
* QStackedWidget 多页面
* QToolBox 层叠窗口部件

QAbstractScrollArea 带有滚动区域的部件抽象类

* QTextEdit 
* QLineEdit (自事撤销恢复、剪切拖放等操作)（示例：Line Edits）

QAbstractButton 按钮部件 （示例：Group Box Example）

* QGroupBox
* QCheckBox 复选框
* QPushButton 标准按钮
* QRadioButton 单选按钮
* QToolButton 工具按钮

QAbstractSpinBox 数值设定框

* QDateTimeEdit 日期
* QSpinBox 整数
* QDoubleSpinBox 浮点数

QAbstractSlider 滑块部件

* QScrollBar 滚动条
* QSlider 进度滑块
* QDial 刻度表

#### 比较

| 部件 | iOS | Qt |
|---|---|---|
|Views| Action Sheets <br/><img src="./pic/actionSheet.png" />| |
||Activity Indicators(菊花) <br/><img src="./pic/ActivityIndicators.png" />||
||Alert Views <br/><img src="./pic/alterView.png" />||
||Collection Views <br/><img src="./pic/collectionView.png" />||
||Image Views||
||Labels<br/><img src="./pic/labels.png" />| QLabel |
||Navigation Bar<br/><img src="./pic/NavigationBar.png" />||
||Picker Views <br/><img src="./pic/PickerViews.png" />| Combo Box <br/><img src="./pic/comboBox.png" />|
||Progress Views<br/><img src="./pic/ProgressViews.png" />| progress Bar<br/><img src="./pic/progressBar.png"/>|
||Scroll Views<br/><img src="./pic/ScrollViews.png" />|Horizontal Scroll Bar<br/>Vertical Scroll Bar<br/><img src="./pic/scrollBar.png" /><br/>Scroll Area|
||Search Bars<br/><img src="./pic/SearchBars.png" />||
||Tab Bars<br/><img src="./pic/TabBars.png" />||
||Table Views<br/><img src="./pic/TableViews.png" />||
||Text Views<br/><img src="./pic/TextViews.png" />|Text Browser|
||Toolbars<br/><img src="./pic/Toolbars.png" />||
||Web Views<br/><img src="./pic/WebViews.png" />| QWeiView|
|Controls| Buttons <br/><img src="./pic/buttons.png" />| |
||Date Pickers<br/><img src="./pic/DatePickers.png" />| Time Edit<br/>Date Edit<br/>Date/Time Edit<br/><img src="./pic/qtdateandtime.png" /><br/>Calendar<br/><img src="./pic/calendar.png" />|
||Page Controls<br/><img src="./pic/PageControls.png" />||
||Segmented Controls<br/><img src="./pic/SegmentedControls.png" />||
||Sliders<br/><img src="./pic/sliders.png" />| Horizontal Slider <br/> Vertical Slider <br/><img src="./pic/qtSlider.png" />|
||Steppers<br/><img src="./pic/steppers.png" />||
||Switches<br/><img src="./pic/switches.png" />||
||Text Fields<br/><img src="./pic/textFields.png" />| Line Edit|
|View Controller| Split View Controllers<br/><img src="./pic/splitviewController.png" />||
|Other|fixed space bar button item<br/><img src='./pic/fixedspacebarbuttonitem.png' />| Horizontal Spacer<br/>Vertical Spacer <br/><img src="./pic/qtSpacer.png" />|


#### 参考资料

* [About Views](https://developer.apple.com/library/ios/documentation/UserExperience/Conceptual/UIKitUICatalog/index.html#//apple_ref/doc/uid/TP40012857-UIView-SW1)
* [Swift UI控件实现大全](https://github.com/HunkSmile/Swift)