#include "widget2.h"
#include <QPushButton>
#include <QDebug>

Widget2::Widget2(QWidget *parent) : QWidget(parent)
{
    QPushButton * sr2 = new QPushButton("新窗口", this);
    setFixedSize(500,500);
    sr2 -> move(20, 40);
    connect(sr2, &QPushButton::clicked, this, &Widget2::close);



}

Widget2::~Widget2()
{
    qDebug() << "widget2的析构函数";
}
