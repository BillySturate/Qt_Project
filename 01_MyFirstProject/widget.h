#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT        //Q_OBJECT宏，允许信号中使用信号和槽的机制

public:
    Widget(QWidget *parent = nullptr);      //构造函数
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
