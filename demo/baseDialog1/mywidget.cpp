#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
#include "mydialog.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 添加一个对话框
    //QDialog dialog(this); 临时变量，作用域只有在构造函数内
    //dialog.show(); 一闪而过，不然就改为
    //dialog.exec(); 对话框出现了，但是阻塞了父窗口的出现

//    connect(
//                ui->showChildButton,
//                SIGNAL(clicked()),
//                this,
//                SLOT(showChildDialog())
//            );
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::showChildDialog()
{
    QDialog *dialog = new QDialog(this);
    //dialog->setModal(true);
    dialog->show();
}

void MyWidget::on_showChildButton_clicked(){
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(QObject::tr("另一窗口"));
    dialog->show();
}

void MyWidget::on_relogin_clicked()
{
    // 先关闭主界面，其实它是隐藏，并不是真正的退出
    // 只有当只有一个窗口时，能是真正的退出
    close();
    MyDialog dlg;
    // 如果按下”进入主窗口“按钮，则再次显示主界面
    //否则，因为现在已经没有显示的界面了，所以程序将退出
    if(dlg.exec() == QDialog::Accepted)
        show();
}
