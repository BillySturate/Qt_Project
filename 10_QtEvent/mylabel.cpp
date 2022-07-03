#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪
    setMouseTracking(true);
}

//鼠标进入事件
void myLabel::enterEvent(QEvent *event)
{
    //qDebug() << "鼠标进入了";
}

//鼠标离开事件
void myLabel::leaveEvent(QEvent *event)
{
    //qDebug() << "鼠标离开了";
}


//鼠标的按下
void myLabel::mousePressEvent(QMouseEvent *ev)
{
//    if(ev->button() == Qt::LeftButton)
//    {
    QString str = QString("鼠标按下了 x=%1, y=%2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
    QString str2 = QString("鼠标按下了 globalx=%1, globaly=%2").arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str2;
//    }
}

//鼠标的释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString str = QString("鼠标释放了 x=%1, y=%2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
    QString str2 = QString("鼠标释放了 globalx=%1, globaly=%2").arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str2;
}

//鼠标的移动
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
//    if(ev->buttons() & Qt::LeftButton)
//    {
    QString str = QString("鼠标移动了 x=%1, y=%2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
    QString str2 = QString("鼠标移动了 globalx=%1, globaly=%2").arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str2;
//    }
}



//通过event事件分发器拦截鼠标按下的事件
//bool event(QEvent* e)
//{
//    //如果是鼠标按下，在event事件分发中做拦截操作
//    if(e->type() == QEvent::MouseButtonPress)
//    {
//        QMouseEvent *ev = dynamic_cast<QMouseEvent *>(e);
//        QString str = QString("Event函数中::鼠标按下了 x=%1, y=%2").arg(ev->x()).arg(ev->y());
//        qDebug() << str;
//        QString str2 = QString("Event函数中::鼠标按下了 globalx=%1, globaly=%2").arg(ev->globalX()).arg(ev->globalY());
//        qDebug() << str2;
//        return true; //代表用户自己处理这个事件，不向下分发

//    }

//    //其他事件交给父类处理
//    return QLabel::event(e);
//}



































