#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <mypushbutton.h>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include "playscene.h"
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{

    //配置选择关卡场景
    this->setFixedSize(520, 788);

    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("选择关卡场景");

    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu *startmenu = bar->addMenu("开始");
    //创建退出菜单
    QAction *quitAction = startmenu->addAction("退出");

    //点击退出 实现退出游戏
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //选择关卡音效
    QSound * chooseSound = new QSound(":/res/TapButtonSound.wav", this);
    QSound * backSound = new QSound(":/res/BackButtonSound.wav", this);

    //返回按钮
    MyPushButton * backbtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width() - backbtn->width(), this->height() - backbtn->height());

    //点击返回
    connect(backbtn, &MyPushButton::clicked, [=](){
        backSound->play();
        //告诉主场景我返回了，主场景监听ChooseLevelScene的返回按钮
        //延时返回
        //延时进入到选择关卡场景中,本例是过了500ms进入其中执行
        QTimer::singleShot(500, this, [=](){
             emit this->chooseSceneBack();
        });
    });

    //创建选择关卡按钮
    for(int i = 0; i < 20; i++)
    {
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(70 + i%4 * 100, 220 + i/4 * 100);

        //监听每个按钮的点击事件
        connect(menuBtn, &MyPushButton::clicked, [=](){
            //播放选择关卡的音效
            chooseSound->play();
            QString str = QString("您选择的是第%1关").arg(i+1);
            qDebug() << str;

            //进入到游戏场景
            this->hide();   //将选关场景隐藏掉
            play = new PlayScene(i+1);  //创建游戏场景\
            //设置游戏场景的初始位置
            play->setGeometry(this->geometry());
            play->show();//显示游戏场景

            connect(play, &PlayScene::chooseSceneBack, [=](){
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = NULL;
            });


        });

        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(70 + i%4 * 100, 220 + i/4 * 100);
        label->setScaledContents(true);
        //设置label上的文字的对齐方式 水平居中和垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        //设置鼠标进行穿透  51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);

    }

}

//重写绘图事件
void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*1.5, pix.height()*1.5);
    painter.drawPixmap((this->width() - pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}




















