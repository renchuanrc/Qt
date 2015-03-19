#include "mainwindow.h"
#include "ui_mainwindow.h"

// 框架
#include <QTextFrame>

#include <QDebug>

// 查找功能
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

// 高亮显示
#include "syntaxhighlighter.h"

// 自动补全
#include <QStringList>
#include <QCompleter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //框架
    // 获取文档对象
    QTextDocument *document = ui->textEdit->document();
    // 获取根框架
    QTextFrame *rootFrame = document->rootFrame();
    // 创建框架格式
    QTextFrameFormat format;
    format.setBorderBrush(Qt::red);//边界颜色
    format.setBorder(3);//边界宽度
    rootFrame->setFrameFormat(format);//框架使用格式

    // 创建另一个框架格式
    QTextFrameFormat format2;
    format2.setBackground(Qt::lightGray);
    format2.setMargin(0);
    format2.setPadding(5);
    format2.setBorder(2);
    format2.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);
    //获取光标
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertFrame(format2);

    QAction *action_textFrame = new QAction(tr("框架"),this);
    connect(action_textFrame,
            SIGNAL(triggered()),
            this,
            SLOT(showTextFrame()));
    ui->mainToolBar->addAction(action_textFrame);

    QAction *action_textBlock = new QAction(tr("文本块"),this);
    connect(action_textBlock,
            SIGNAL(triggered()),
            this,
            SLOT(showTextBlock()));
    ui->mainToolBar->addAction(action_textBlock);

    QAction *action_font = new QAction(tr("字体"),this);
    action_font->setCheckable(true);
    connect(action_font,
            SIGNAL(toggled(bool)),
            this,
            SLOT(setTextFont(bool)));
    ui->mainToolBar->addAction(action_font);

    QAction *action_table = new QAction(tr("表格"),this);
    connect(action_table,
            SIGNAL(triggered()),
            this,
            SLOT(insertTable()));
    ui->mainToolBar->addAction(action_table);

    QAction *action_list = new QAction(tr("列表"),this);
    connect(action_list,
            SIGNAL(triggered()),
            this,
            SLOT(insertList()));
    ui->mainToolBar->addAction(action_list);

    QAction *action_image = new QAction(tr("图片"),this);
    connect(action_image,
            SIGNAL(triggered()),
            this,
            SLOT(insertImage()));
    ui->mainToolBar->addAction(action_image);

    QAction *action_find = new QAction(tr("查找"),this);
    connect(action_find,
            SIGNAL(triggered()),
            this,
            SLOT(textFind()));
    ui->mainToolBar->addAction(action_find);

    highlighter = new SyntaxHighlighter(ui->textEdit->document());
    ui->textEdit->append(tr("<h1><font color=red>使用HTML</font></h1>"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextFrame()
{
    QTextDocument *document = ui->textEdit->document();
    QTextFrame *frame = document->rootFrame();
    QTextFrame::iterator it;

    for (it = frame->begin(); !(it.atEnd()); ++it){
        QTextFrame *childrenFrame = it.currentFrame();
        QTextBlock childBlock = it.currentBlock();
        if (childrenFrame)
            qDebug()<<"Frame";
        else if (childBlock.isValid())
            qDebug()<<"Block"<<childBlock.text();
    }
}

void MainWindow::showTextBlock(){
    QTextDocument *document = ui->textEdit->document();
    QTextBlock block = document->firstBlock();
    for(int i = 0; i < document->blockCount(); ++i){
        qDebug()<<tr("文本块%1,文本块首行行号为：%2，长度为：%3，内容为")
                   .arg(i).arg(block.firstLineNumber()).arg(block.length())
                << block.text();
        block = block.next();
    }
}

void MainWindow::setTextFont(bool checked){
    if (checked){
        QTextCursor cursor = ui->textEdit->textCursor();//选中
        // 创建文本块格式
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);

        // 字符格式
        QTextCharFormat charFormat;
        charFormat.setBackground(Qt::lightGray);
        charFormat.setForeground(Qt::blue);
        charFormat.setFont(QFont(tr("微软雅黑"),12,QFont::Bold,true));
        charFormat.setFontUnderline(true);

        cursor.setCharFormat(charFormat);
        cursor.insertText(tr("测试字体"));
    }
}

void MainWindow::insertTable(){
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat format;
    format.setCellSpacing(2);//外边白
    format.setCellPadding(10);//内边
    cursor.insertTable(2,2,format);
}

void MainWindow::insertList(){
    QTextListFormat format;
    format.setStyle(QTextListFormat::ListDecimal);//数字编号
    ui->textEdit->textCursor().insertList(format);//这种写法方便
}

void MainWindow::insertImage(){
    QTextImageFormat format;
    format.setName("https://www.baidu.com/img/bdlogo.png");
    ui->textEdit->textCursor().insertImage(format);
}

void MainWindow::textFind(){
    QDialog *dlg = new QDialog(this);//非模态的对话框
    lineEdit = new QLineEdit(dlg);
    // 创建查找按钮
    QPushButton *btn = new QPushButton(dlg);
    btn->setText(tr("查找下一个"));
    connect(btn,
            SIGNAL(clicked()),
            this,
            SLOT(findNext()));
    //创建垂直布局对话框
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(btn);
    dlg->setLayout(layout);
    dlg->show();
}

void MainWindow::findNext(){
    QString string = lineEdit->text();//获取所有文本
    //开始查找，类似PHP的 strpos() 函数，返回一个位置
    bool isfind = ui->textEdit->find(
                string,
                QTextDocument::FindBackward);//向后查找
    if (isfind){
        qDebug()<<tr("行号：%1 列号：%2")
                   .arg(ui->textEdit->textCursor().blockNumber())
                   .arg(ui->textEdit->textCursor().columnNumber());
    }
}
