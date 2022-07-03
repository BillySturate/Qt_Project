#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

//构造函数 参数一 正常显示的图片路径  参数2 按下后显示的图片路径
MyPushButton::MyPushButton(QString normalImage, QString pressImg)
{
    this->normalImgPath = normalImage;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImage);
    pix = pix.scaled(pix.width()*1.5, pix.height()*1.5);
    if(!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }

    //设置图片固定的大小
    this->setFixedSize(pix.width(), pix.height());

    //设置不规则图片格式
    this->setStyleSheet("QPushButton{border:Opx;}");

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));

}


//弹跳函数
void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画的时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //结束位置
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}
void MyPushButton::zoom2()
{
    //创建动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画的时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    //结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}

//重写按钮按下和释放事件
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath !="")//传入的按下图片不为空 说明需要有按下状态，切换图片
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        pix = pix.scaled(pix.width()*1.5, pix.height()*1.5);
        if(!ret)
        {
            qDebug() << "图片加载失败";
            return;
        }

        //设置图片固定的大小
        this->setFixedSize(pix.width(), pix.height());

        //设置不规则图片格式
        this->setStyleSheet("QPushButton{border:Opx;}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    //让父类执行其他的内容
    return QPushButton::mousePressEvent(e);


}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath !="")//传入的按下图片不为空 说明需要有按下状态，切换成初始图片
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        pix = pix.scaled(pix.width()*1.5, pix.height()*1.5);
        if(!ret)
        {
            qDebug() << "图片加载失败";
            return;
        }

        //设置图片固定的大小
        this->setFixedSize(pix.width(), pix.height());

        //设置不规则图片格式
        this->setStyleSheet("QPushButton{border:Opx;}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    //让父类执行其他的内容
    return QPushButton::mouseReleaseEvent(e);
}




















