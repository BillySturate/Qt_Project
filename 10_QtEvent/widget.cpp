#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    id1 = startTimer(1000); //参数1 间隔 单位 毫秒
    id2 = startTimer(2000);

    //定时器的第二种方法
    QTimer *timer = new QTimer(this);
    //启动定时器
    timer->start(500);
    connect(timer, &QTimer::timeout, [=](){
        static int num4 = 1;
        ui->label_4->setText(QString::number(num4++));
    });

    //点击暂停按钮 实现停止计时器
    connect(ui->ptn, &QPushButton::clicked, [=](){
        timer->stop();
    });

    //给label1安装上事件过滤器
    //步骤1安装事件过滤器
    ui->label->installEventFilter(this);
}
//步骤二：重写eventFilter事件
bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->label)
    {
        //如果是鼠标按下，在event事件分发中做拦截操作
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *ev = dynamic_cast<QMouseEvent *>(event);
            QString str = QString("事件过滤器中::鼠标按下了 x=%1, y=%2").arg(ev->x()).arg(ev->y());
            qDebug() << str;
            QString str2 = QString("事件过滤器中::鼠标按下了 globalx=%1, globaly=%2").arg(ev->globalX()).arg(ev->globalY());
            qDebug() << str2;
            return true; //代表用户自己处理这个事件，不向下分发
        }
    }
    //其他默认处理
    return QWidget::eventFilter(watched, event);
}
Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1){
    static int num = 1;
    ui->label_2->setText(QString::number(num++));
    }
    if(event->timerId() == id2){
    static int num2 = 1;
    ui->label_3->setText(QString::number(num2++));
    }

}
