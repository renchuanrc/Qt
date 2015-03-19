#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    // 必须将 QObject 修改为 QTextDocument 否则不起作用
    explicit SyntaxHighlighter(QTextDocument *parent);

protected:
    // 必须重新实现该函数
    void highlightBlock(const QString &text);

signals:

public slots:

};

#endif // SYNTAXHIGHLIGHTER_H
