#include "mywidget.h"
#include "ui_mywidget.h"

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    // 设置时间为现在系统时间
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    // 设置时间的显示格式
    ui->dateTimeEdit->setDisplayFormat(
                tr("yyyy年MM月dd日 ddd HH时mm分ss秒")
                // ddd 表示星期
                );
}

myWidget::~myWidget()
{
    delete ui;
}
