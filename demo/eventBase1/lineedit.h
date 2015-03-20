#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class lineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit lineEdit(QWidget *parent = 0);

    bool event(QEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:

};

#endif // LINEEDIT_H
