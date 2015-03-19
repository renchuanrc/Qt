#include "syntaxhighlighter.h"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
}

void SyntaxHighlighter::highlightBlock(const QString &text)
{
    //字符格式
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    format.setForeground(Qt::green);
    QString pattern = "\\bchar\\b";

    QRegExp expression(pattern);//创建一个正则表达式

    int index = text.indexOf(expression);
    // 如果匹配成功，那么返回值为字符串的起始位置，它大于或等于0
    while(index >= 0){
        int length = expression.matchedLength();//要匹配的字符串长度
        setFormat(index,length,format);
        index = text.indexOf(expression,index+length);//继续匹配
    }
}
