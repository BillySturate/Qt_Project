#include "widget.h"
#include "ui_widget.h"
#include <QMovie>
f
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //栈控件的使用

    //设置默认值
    ui->stackedWidget->setCurrentIndex(1);


    //scrollArea按钮
    connect(ui->btn_scrollArea, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->btn_TabWidget, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btn_ToolBox, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //下拉框
    ui->comboBox->addItem("benz");
    ui->comboBox->addItem("bmw");
    ui->comboBox->addItem("audi");

    //点击按钮选中拖拉机
    connect(ui->btn_select, &QPushButton::clicked, [=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("benz");
    });

    //利用Qlabel显示图片
    //QPixmap *src = new QPixmap(":/images/chou.jpg");  此功能行不通后面又时间再看吧
    //ui->lb_image->setPixmap(src);
    ui->lb_image->setPixmap(QPixmap(":/images/chou.jpg"));


    //利用QLabel显示动态图
    //QMovie * movie = new QMovie(":/images/giphy.gif");
    //ui->lb_image->setMovie(":/images/giphy.gif");
//    ui->lb_image->setMovie(movie);
//    movie->start();

}

Widget::~Widget()
{
    delete ui;
}

