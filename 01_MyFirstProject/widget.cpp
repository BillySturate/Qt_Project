#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个按钮
    QPushButton * btn = new QPushButton;
   // btn->show();    //以顶层的方式弹出窗口控件

    //让btn对象 依赖在widget窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("第一个窗口");

    //创建第二个窗口
    QPushButton * btn2 = new QPushButton("第二个按钮",this);

    //重置窗口大小
    resize(600,400);

    //移动按钮
    btn->move(100,100);

    //设置骨钉窗口大小
    setFixedSize(800,650);

    //设置窗口标题
    setWindowTitle("第一个窗口");


    //创建一个自己按钮的对象
    MyPushButton * mybtn = new MyPushButton;
    mybtn->setText("我自己的按钮");

    mybtn->move(100,75);
    mybtn->setParent(this); //设置到对象树中


    //需求:点击我的按钮,关闭窗口
    //参数1 信号的发送者 参数2 发送的信号(函数的地址) 参数3 参数的接受者 参数4 处理的槽函数
    connect( mybtn, &MyPushButton::clicked, this, &Widget::close);


}

Widget::~Widget()
{
    qDebug() << "myWidget的析构函数";
    delete ui;
}

