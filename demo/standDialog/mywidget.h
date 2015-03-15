#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

// 向导对话框
#include <QWizard>

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
    void on_color_clicked();
    void on_font_clicked();
    void on_file_clicked();

    void on_input_clicked();

    void on_message_clicked();

    void on_progress_clicked();

    void on_errormsg_clicked();

    void on_guide_clicked();

private:
    Ui::MyWidget *ui;

    //向导对话框
    QWizardPage *createPage1();
    QWizardPage *createPage2();
    QWizardPage *createPage3();
};

#endif // MYWIDGET_H
