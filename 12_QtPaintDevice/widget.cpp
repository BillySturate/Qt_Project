#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //Pixmap绘图设备 专门为平台做了显示优化
//    QPixmap pix(300, 300);

//    //申明画家
//    QPainter painter(&pix);

//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    //保存
//    pix.save("E:\\QT_Project\\12_QtPaintDevice\\pix.png");


//    //Qimage 绘图设备，可以对像素进行访问
//    QImage img(300, 300, QImage::Format_RGB32);
//    //填充颜色
//    img.fill(Qt::yellow);

//    QPainter painter(&img);

//    painter.setPen(QPen(Qt::red));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);
//    img.save("E:\\QT_Project\\12_QtPaintDevice\\img.png");

    //QPicture绘图设备，可以记录和重现绘制指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(QPen(Qt::red));
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    painter.end();
    pic.save("E:/QT_Project/12_QtPaintDevice/pic.lh");
}

//绘图事件
void Widget::paintEvent(QPaintEvent *event)
{
//   //Painter painter(&img);
//    //利用QImge对像素进行修改
//    QImage img;
//    QPainter painter(this);
//    img.load(":/images/2.jpg");

//    //修改像素点
//    for(int i = 50; i < 100; i++)
//    {
//        for(int j = 50; j < 100; j++)
//        {
//            QRgb value = qRgb(255, 0, 0);
//            img.setPixel(i, j, value);
//        }
//    }
//    painter.drawImage(0, 0, img);


    QPainter painter(this);
    //重现Qpicture的绘图指令
    QPicture pic;
    pic.load("E:/QT_Project/12_QtPaintDevice/pic.lh");
    painter.drawPicture(0, 0, pic);


}

Widget::~Widget()
{
    delete ui;
}






















