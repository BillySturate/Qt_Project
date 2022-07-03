#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include <mypushbutton.h>
#include <QDebug>
#include <QTimer>
#include <QSound>      //多媒体模块下的音效头文件


MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    this->setFixedSize(520, 788);

    //设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("翻金币");

    //退出按钮的实现
    connect(ui->actionquit, &QAction::triggered, [=](){
        this->close();
    });

    //准备开始音效
    QSound *startSound = new QSound(":/res/TapButtonSound.wav", this);

    //设置循环音效
    //startSound->setLoops(-1);     //如果是-1是无限循环
    //startSound->play();

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(width()*0.5 - startBtn->width()*0.5, this->height()*0.7);


    //实例化选择关卡场景
    chooscene = new ChooseLevelScene;


    //监听选择关卡的返回按钮的信号
    connect(chooscene, &ChooseLevelScene::chooseSceneBack, this, [=](){
        this->setGeometry(chooscene->geometry());

        chooscene->hide();  //将选择关卡场景隐藏掉
        this->show();   //重新显示主场景
    });

    connect(startBtn, &MyPushButton::clicked, [=](){

        //播放开始的音效资源
        startSound->play();
        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();


        //延时进入到选择关卡场景中,本例是过了500ms进入其中执行
        QTimer::singleShot(500, this, [=](){
            //设置chooseScene场景的位置
            chooscene->setGeometry(this->geometry());
            //进入到选择关卡场景中
            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooscene->show();

        });

    });

}


//重写paintEvent事件
void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //画背景上的图标
    pix.load(":/res/Title.png");

    //缩放图片
    //pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);

    painter.drawPixmap(10, 30, pix);





}

MainScene::~MainScene()
{
    delete ui;
}

