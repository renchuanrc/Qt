#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QTextStream>

#include <QLabel>
#include <QMouseEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置窗口的部件可拖动
    setAcceptDrops(true);
    QLabel *label = new QLabel(this);
    QPixmap pix("E:/Qt/images/66.png");
    label->setPixmap(pix);
    label->resize(pix.size());
    label->move(100,100);
    // 当窗口关闭时销毁图片
    label->setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    //数据中是否包含Url
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();//接收动作
    else if(event->mimeData()->hasFormat("myimage/png")){
        // 进行移动操作
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else
        event->ignore();//忽略事件
}
// 放下事件
void MainWindow::dropEvent(QDropEvent *event)
{
    //获取 MIME 数据
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls()){
        QList<QUrl> urlList = mimeData->urls();//获取URL列表
        //将其中第一个URL表示为本地文件路径
        QString fileName = urlList.at(0).toLocalFile();
        if (!fileName.isEmpty()){
            QFile file(fileName);
            // 以只读方式打开
            if (!file.open(QIODevice::ReadOnly))
                return;
            // 建立文本流对象
            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
        }
    } else if (mimeData->hasFormat("myimage/png")){
        QByteArray itemData = mimeData->data("myimage/png");
        QDataStream dataStream(&itemData,QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint offset;
        //使用数据流将字节数组中的数据读入到 Qpixmap 和 offset
        dataStream >> pixmap >> offset;
        // 新建标签，为其添加图片，并根据图片大小设置标签的大小
        QLabel *newLabel = new QLabel(this);
        newLabel->setPixmap(pixmap);
        newLabel->resize(pixmap.size());
        // 让图片移动到放下的位置
        newLabel->move(event->pos()-offset);
        newLabel->show();
        newLabel->setAttribute(Qt::WA_DeleteOnClose);
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

// 鼠标按下事件
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //1.获取图片
    // 将鼠标指针所在位置的部件强制转换为 QLable 类型
    QLabel *child = static_cast<QLabel *>(childAt(event->pos()));
    if (!child->inherits("QLabel"))
        return;
    //获取图片
    QPixmap pixmap = *child->pixmap();

    //2.自琮义MIME类型
    QByteArray itemData;
    QDataStream dataStream(&itemData,QIODevice::WriteOnly);
    // 将图片信息，位置信息输入到字节数组中
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    //3.将数据放入到 QMimeData 中
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("myimage/png",itemData);

    //4.将QMimeData 数据放入 QDrap 中
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);//在移动过程中显示图片，否则是一个小方块
    drag->setHotSpot(event->pos() - child->pos());//移动后鼠标相对位置

    //5.给原图片添加阴影
    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    //在图片的外接矩形中添加一层透明的淡黑色开成阴影
    painter.fillRect(pixmap.rect(),QColor(127,127,127,127));
    painter.end();
    child->setPixmap(tempPixmap);

    //6.执行拖放操作
    //设置拖动可以是移动和复制，默认是复制
    if (drag->exec(Qt::CopyAction | Qt::MoveAction,
                   Qt::CopyAction)== Qt::MoveAction)
        child->close();
    else{
        child->show();
        child->setPixmap(pixmap);
    }
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("myimage/png")){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }else{
        event->ignore();
    }
}


