#include "widget.h"
#include "ui_widget.h"
#include <QPainter>  //画家类
#include <QEvent>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    timer->start(10);
    //点击移动按钮，移动图片
    connect(timer, &QTimer::timeout, [=](){
        update();
    });
//    connect(ui->pushButton, &QPushButton::clicked, [=](){

//        //如果要手动调用绘图事件，用update更新
//        update();
//    });
}

//绘图事件
void Widget::paintEvent(QPaintEvent *event)
{
//    //实例化画家对象 this指的是绘画的设备
//    QPainter painter(this);
//    //设置画笔的颜色
//    QPen pen(QColor(255, 0, 0));
//    //设置画笔的宽度
//    pen.setWidth(5);
//    //设置画笔的风格
//    pen.setStyle(Qt::DotLine);
//    //让画家使用这个笔
//    painter.setPen(pen);


//    //设置画刷
//    QBrush brush(Qt::gray);
//    //设置画刷的风格
//    brush.setStyle(Qt::Dense1Pattern);
//    //让画家使用画刷
//    painter.setBrush(brush);


//    //画线
//    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
//    //画⚪
//    painter.drawEllipse(QPoint(100, 100), 100, 50);

//    //画一个矩形
//    painter.drawRect(QRect(20, 20, 50, 50));
//    //画文字
//    //int a = 10;
//    painter.drawText(QRect(10, 200, 100, 50), "好好学习，天天向上");




    ///////////////////////////////////////////////高级设置

//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100, 50), 50, 50);
//    //设置抗锯齿能力  效率较低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200, 50), 50, 50);


    //画一个矩形
    //    painter.drawRect(QRect(20, 20, 50, 50));

    //    //移动画家的位置
    //    painter.translate(100, 0);

    //    //保存画家的状态
    //    painter.save();

    //    painter.drawRect(QRect(20, 20, 50, 50));
    //    painter.translate(100, 0);

    //    //还原画家的状态
    //    painter.restore();

    //    painter.drawRect(QRect(20, 20, 50, 50));






    ///////////////////////////////////////////////////利用画家画资源图片


    QPainter painter(this);
    posX+=20;
    if(posX > this->width())
    {
        posX = 0;
    }
    painter.drawPixmap(posX, 0, QPixmap(":\\images\\1.jpg"));


}

Widget::~Widget()
{
    delete ui;
}

