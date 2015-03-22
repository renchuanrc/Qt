#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT

    //注册userName属性
    Q_PROPERTY(
        QString userName
        READ getUserName
        WRITE setUserName
        NOTIFY userNameChanged
        );
public:
    explicit MyClass(QObject *parent = 0);

    // 实现 READ 函数
    QString getUserName() const{
        return m_userName;
    }
    // 实现 WRITE 函数
    void setUserName(QString userName){
        m_userName = userName;
        // 当属性修改时发射信号
        emit userNameChanged(userName);
    }

signals:
    //声明 NOTIFY通知消息
    void userNameChanged(QString);

public slots:

private:
    QString m_userName;// 私有变量，存放userName

};

#endif // MYCLASS_H
