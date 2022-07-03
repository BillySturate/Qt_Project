#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //重写定时器事件
    void timerEvent(QTimerEvent *event);\

    int id1; //定义标识符1
    int id2; //定义标识符2

    //重写事件过滤器事件
    bool eventFilter(QObject *watched, QEvent *event);


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
