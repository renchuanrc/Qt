#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //拖动进入事件
    void dragEnterEvent(QDragEnterEvent *event);
    //放下事件
    void dropEvent(QDropEvent *event);

    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);
    //拖动事件
    void dragMoveEvent(QDragMoveEvent *event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
