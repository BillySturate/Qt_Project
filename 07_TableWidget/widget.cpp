#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TableWidget控件
    //先要设置列数
    ui->tableWidget->setColumnCount(3);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);

    //设置正文
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("亚瑟"));

    QStringList nameList;
    nameList << "亚瑟" << "关羽" << "赵云" << "张飞" << "花木兰";
    QList<QString> sexList;
    //sexList << "男" << "男" << "男" << "男" << "女";
    sexList.push_back("男");
    sexList.push_back("男");
    sexList.push_back("男");
    sexList.push_back("男");
    sexList.push_back("女");
    for(int i = 0; i < 5; i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(nameList[i]));  //可能会数组越界
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(sexList.at(i))); //数组越界会抛出异常
        //int转QString类型
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(i + 18)));
    }



}

Widget::~Widget()
{
    delete ui;
}

