#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
    class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private slots:
    void on_pushButton_toggled(bool checked);

    void on_showSelectResult_clicked();

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
