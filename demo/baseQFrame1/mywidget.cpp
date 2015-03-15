#include "mywidget.h"
#include "ui_mywidget.h"

// ¾²Ì¬Í¼Æ¬
#include <QPixmap>

// ¶¯Ì¬ gif Í¼Æ¬
#include <QMovie>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Sunken);
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

    //QLabel Í¼Æ¬
    ui->label->setPixmap(QPixmap("E:/Qt/images/logo.png"));

    //¶¯Ì¬ gif
    QMovie *movie = new QMovie("E:/Qt/images/test.gif");
    ui->labelMovie->setMovie(movie);
    movie->start();

    // Òº¾§Êý×ÖÐ§¹û QLCDNumber

}

MyWidget::~MyWidget()
{
    delete ui;
}
