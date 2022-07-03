#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
#include "widget2.h"

//Teacher 类 老师类
//Student 类 学生类
//下课后，老师会触发一个信号，饿了，学生相应信号，请客吃饭


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师的对象
    this->zt = new Teacher(this);
    //zt->setParent(this);

    //创建一个学生的对象
    this->st = new Student(this);

//    //老师饿了，学生请客的链接
//    connect(zt, &Teacher::hungry, st, &Student::treat);

//    //调用下课函数
//    classIsOver();

    //链接带参数的，信号和槽
    //指针->地址
    //函数指针->函数地址

    void (Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void (Student:: *studentSlot)(QString) = &Student::treat;
    //connect(zt, teacherSignal, st, studentSlot);
    //classIsOver();


    //点击一个下课的按钮，再触发下课
    QPushButton * btn = new QPushButton("下课", this);
    //充值窗口的大小
    this->resize(600, 400);
    //connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);

    //无参信号和槽连接
    void (Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void (Student:: *studentSlot2)(void) = &Student::treat;
    //connect(zt, teacherSignal2, st, studentSlot2);

    //信号连接信号
    //connect(btn, &QPushButton::clicked, zt, teacherSignal2);
    //connect(btn, &QPushButton::clicked, zt, teacherSignal);
    //connect(btn, &QPushButton::clicked, this, &Widget::close);

    //断开信号
    //disconnect(zt, teacherSignal2, st, studentSlot2);



    //拓展
    //1.信号是可以连接信号
    //2.一个信号可以连接多个槽函数
    //3.多个信号 可以连接同一个槽函数
    //4.信号和槽函数的参数必须类型一一匹配
    //信号的参数个数可以多与槽函数的个数

    //gt4版本以前的信号和槽函数连接方式
    //利用Qt4版本连接无参版本
    //Qt4版本底层SIGNAL("hungry")   SLOT("treat");
    //connect(zt, SIGNAL(hungry()),st, SLOT(treat()) );
    //Qt4版本优点，参数直观，缺点，类型不做检测


    [=](){
        btn->setText("上课");
    }();


    //mutable关键字用于修饰值传递的变量，修改的是拷贝，而不是本体
    QPushButton * mybtn = new QPushButton(this);
    QPushButton * mybtn2 =new QPushButton(this);
    mybtn->move(100,100);
    (*mybtn2).move(150,150);
    int m = 10;
    //默认情况下是打括号内的值不可修改是只读状态，如果要修改在小括号后加上mutable关键字
//    connect(mybtn, &QPushButton::clicked, this, [&]()mutable{ m = 100 + 10 ; qDebug() << m;});
//    connect(mybtn2, &QPushButton::clicked, this, [=](){qDebug() << m;});
//    qDebug() << m;

    //[](int num){qDebug() << num;}(10000);

//    int ret = []()->int{return 1000;}();
//    qDebug() << "ret=" << ret;


    //默认情况下是打括号内的值不可修改是只读状态，如果要修改在小括号后加上mutable关键字
    connect(btn, &QPushButton::clicked, this, [&]()->void{emit zt->hungry("宫保鸡丁");});
    //int ret = []()->int{return 1000;}();

    QPushButton * btn4 = new QPushButton("关闭", this);
    btn4->move(25,25);
    connect(btn4, &QPushButton::clicked, this, [=](){
        this->close();
        emit zt->hungry("宫保鸡丁");

    });
   // qDebug()<<"jfajk"<<endl;



    QPushButton *btn6 = new QPushButton("打开新窗口", this);
    btn6->move(150, 90);
    connect(btn6, &QPushButton::clicked, this, [=](){
       Widget * s2 = new Widget;
       s2->resize(500, 400);
       //s2->exec();
       s2->show();
    });
}

void Widget::classIsOver()
{
    //下课函数，调用后，触发老师饿了的信号
    //emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    qDebug() << "结束啦";
    delete ui;
}



