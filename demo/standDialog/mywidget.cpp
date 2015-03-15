#include "mywidget.h"
#include "ui_mywidget.h"

#include <QDebug>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

#include <QColorDialog>
void MyWidget::on_color_clicked()
{
    /*
    QColor color = QColorDialog::getColor(
                Qt::red,// 初始颜色
                this, // 父窗口
                QObject::tr("颜色对话框")); //标题
    */
    QColorDialog dialog(Qt::red,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();
    qDebug() << "color:" << color;
}

#include <QFileDialog>
void MyWidget::on_file_clicked()
{
    QString fileName =
            QFileDialog::getOpenFileName(
                this,
                QObject::tr("选择一个文件"));
    qDebug() << "fileName:" << fileName;
}

#include <QFontDialog>
void MyWidget::on_font_clicked()
{
    bool ok;//用于标记是否单击了 OK 按钮
    QFont font = QFontDialog::getFont(&ok,this);
    // 如果单击了 OK 按钮，那么让 “字体对话框” 使用新的字体
    if (ok)
        ui->font->setFont(font);
    else
        qDebug()<<tr("没有选择字体！");
}

#include <QInputDialog>
void MyWidget::on_input_clicked()
{
    bool ok;
    //获取字符串
    QString string = QInputDialog::getText(
                this,
                tr("字符串对话框"),
                tr("请输入用户名："),
                QLineEdit::Normal,
                tr("admin"),
                &ok
                );
    if (ok)
        qDebug() << "string:"<<string;

    // 获取整数
    int value1 = QInputDialog::getInt(
                this,
                tr("整数对话框"),
                tr("请输入-1000 到 1000 之间的数值"),
                100,
                -1000,
                1000,10,&ok
                );
    if (ok)
        qDebug()<<"int value:" << value1;

    // 获取浮点数
    double value2 = QInputDialog::getDouble(
                this,
                tr("浮点数对话框"),
                tr("请输入 -1000 到 1000 之间的数值"),
                0.00,
                -1000.00,
                1000.00,
                2,&ok
                );
    if (ok)
        qDebug()<<"double:"<<value2;

    //获取条目
    QStringList items;
    items << tr("条目1") << tr("条目2");
    QString item = QInputDialog::getItem(
                this,
                tr("条件对话框"),
                tr("请选择一个条目"),
                items,
                0,
                true,&ok
                );
    if (ok)
        qDebug() << "items:" << item;
}

#include <QMessageBox>
void MyWidget::on_message_clicked()
{
    // 问题对话框
    int ret1 = QMessageBox::question(
                this,
                tr("问题对话框"),
                tr("你了解Qt吗？"),
                QMessageBox::Yes,
                QMessageBox::No);
    if (ret1 == QMessageBox::Yes)
        qDebug()<<tr("问题！");
    // 提示对话框
    int ret2 = QMessageBox::information(
                this,
                tr("提示对话框"),
                tr("这是Qt书箱吗！"),
                QMessageBox::Ok);
    if (ret2 == QMessageBox::Ok)
        qDebug()<<tr("提示");
    // 警告对话框
    int ret3 = QMessageBox::warning(
                this,
                tr("警告对话框"),
                tr("不能提前结束！"),
                QMessageBox::Abort);
    if (ret3 == QMessageBox::Abort)
        qDebug()<<tr("警告");
    // 错误对话框
    int ret4 = QMessageBox::critical(
                this,
                tr("严重错误对话框"),
                tr("发现一个严重的错误，现在要关闭所有文件 "),
                QMessageBox::YesAll);
    if (ret4 == QMessageBox::YesAll)
        qDebug()<<tr("错误");
    // 关于对话框
    QMessageBox::about(
                this,
                tr("关于对话框"),
                tr("这是Qt的入门练习！"));
}

#include <QProgressDialog>
void MyWidget::on_progress_clicked()
{
    QProgressDialog dialog(
                tr("文件复制进度"),
                tr("取消"),
                0,50000,this);
    dialog.setWindowTitle(tr("进度对话框"));
    dialog.setWindowModality(Qt::WindowModal);//设置为模态
    dialog.show();

    for (int i = 0; i< 50000; i++){
        //演示复制进度
        dialog.setValue(i);
        QCoreApplication::processEvents();//避免界面冻结
        if(dialog.wasCanceled())
            break;
    }
    dialog.setValue(50000);
    qDebug()<<tr("复制结束！");
}

#include <QErrorMessage>
void MyWidget::on_errormsg_clicked()
{
    QErrorMessage *dialog = new QErrorMessage(this);
    dialog->setWindowTitle(tr("错误信息对话框"));
    dialog->showMessage(tr("这里是出错信息"));
}

// 向导页面
QWizardPage * MyWidget::createPage1()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("介绍"));
    return page;
}
QWizardPage * MyWidget::createPage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("用户选择信息"));
    return page;
}
QWizardPage * MyWidget::createPage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}

void MyWidget::on_guide_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}
