#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击获取当前的值
    connect(ui->btn_get, &QPushButton::clicked, [=](){
        qDebug() << ui->widget->getNum();
        qDebug() << ui->widget_2->getNum();
    });
    connect(ui->btn_set, &QPushButton::clicked, [=](){
        ui->widget->setNum(50);
        ui->widget_2->setNum(40);
    });
}

Widget::~Widget()
{
    delete ui;
}

