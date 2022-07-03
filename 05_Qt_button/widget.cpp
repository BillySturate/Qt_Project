#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
#include <string>
#include <vector>

using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置单选按钮男选中
    ui->rBtnMan->setChecked(true);

    //选中女后 打印信息

    connect(ui->rBtnWoman, &QRadioButton::clicked, [=](){
        qDebug() << "选中了女！";
    });

    //多选按钮
    connect(ui->cBox, &QCheckBox::stateChanged, [=](int state){
        qDebug() << state;
});


    //利用listWidget写一首诗
    QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
    //将一行诗放入到listwidget中
    ui->listWidget->addItem(item);

    item->setTextAlignment(Qt::AlignHCenter);


    vector<QString> src;
    src.push_back("锄禾日当午");
    src.push_back("汗滴禾下土");
    src.push_back("谁之盘中餐");
    src.push_back("粒粒皆辛苦");
    for(int i = 0 ; i <= 3 ; i++)
    {
        QListWidgetItem *item = new QListWidgetItem(src[i]);
        ui->listWidget->addItem(item);
        item->setTextAlignment(Qt::AlignHCenter);
    }
    //QStringList  QList<QString>
    //QStringList list;
    //list << "锄禾日当午" << "汗滴禾下土" << "谁之盘中餐" << "粒粒皆辛苦";

    QStringList() << "锄禾日当午" << "汗滴禾下土";
    //ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}



