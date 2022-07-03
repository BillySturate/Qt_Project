#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>

#include <QWidget>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);

    //构造函数 参数一 正常显示的图片路径  参数2 按下后显示的图片路径
    MyPushButton(QString normalImage, QString pressImg = "");

    //成员属性 保存用户传入的默认显示路径 以及按下后显示的图片路径
    QString normalImgPath;
    QString pressImgPath;


    //弹跳函数
    void zoom1();   //向上跳
    void zoom2();   //向下跳

    //重写按钮按下和释放事件
    void mousePressEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // MYPUSHBUTTON_H
