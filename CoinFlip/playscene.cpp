#include "playscene.h"
#include <QMenuBar>
#include <QPainter>
#include <QPushButton>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include <dataconfig.h>
#include <QTimer>
#include <QDebug>
#include <QPropertyAnimation>
#include <QSound>

PlayScene::PlayScene(int levelNum)
{
    this->levelIndex = levelNum;

    //初始化游戏场景
    //设置固定大小
    this->setFixedSize(520, 788);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币场景");
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


    //添加音效
    QSound * backSound = new QSound(":/res/BackButtonSound.wav", this);
    //翻金币音效
    QSound * flipSound = new QSound(":/res/ConFlipSound.wav", this);
    //胜利按钮音效
    QSound * winSound = new QSound(":/res/LevelWinSound.wav", this);


    //返回按钮
    MyPushButton * backbtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width() - backbtn->width(), this->height() - backbtn->height());

    //点击返回
    connect(backbtn, &MyPushButton::clicked, [=](){
        backSound->play();

        QTimer::singleShot(500, this, [=](){
             emit this->chooseSceneBack();
        });

    });

    //显示当前关卡数
    QLabel *label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(30);
    QString str1 = QString("Level:%1").arg(this->levelIndex);
    //将字体设置到标签控件中
    label->setFont(font);
    label->setText(str1);
    //label->setGeometry(30, this->height() - 50, 200, 50);
    label->setFixedSize(200, 50);
    label->move(30, this->height() - 50);


    dataConfig config;
    //初始化每个关卡的二维数组
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {

            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }


    //胜利图片显示
    QLabel *winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    tmpPix = tmpPix.scaled(tmpPix.width() * 1.3, tmpPix.height() * 1.3);
    winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move((this->width() - tmpPix.width()) * 0.5, -tmpPix.height());



    //显示金币背景图
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            //绘制背景图片
            QLabel *label = new QLabel;
            QPixmap px;
            px.load(":/res/BoardNode(1).png");
            px = px.scaled(px.width()*1.5, px.height()*1.5);
            label->setGeometry(50, 50, px.width(), px.height());
            label->setPixmap(px);
            label->setParent(this);
            label->move(100 + i*px.width(), 260 + j*px.height());

            //创建金币
            QString str;
            if(this->gameArray[i][j] == 1)
            {
                str = ":/res/Coin0001.png";
            }else
            {
                str = ":/res/Coin0008.png";
            }
            MyCoin *coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(103 + i*px.width(), 264 + j*px.height());

            //将金币放入金币的二维数组里，以便以后的维护
            coinBtn[i][j] = coin;

            //给金币赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];      //1正面 0反面

            //点击金币 进行翻转
            connect(coin, &MyCoin::clicked, [=](){
                flipSound->play();
                //点击按钮 将所有按钮先都禁用
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        this->coinBtn[i][j]->isWin = true;
                    }
                }
                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;

                //翻转周围硬币
                //周围右侧金币翻转的条件,延时翻转
                QTimer::singleShot(300, this, [=](){
                    if(coin->posX + 1 <= 3)
                    {
                        coinBtn[coin->posX + 1][coin->posY] ->changeFlag();
                        this->gameArray[coin->posX + 1][coin->posY] = this->gameArray[coin->posX + 1][coin->posY] == 0 ? 1 : 0;
                    }

                    //周围左侧硬币翻转的条件
                    if(coin->posX - 1 >= 0)
                    {
                        coinBtn[coin->posX - 1][coin->posY] ->changeFlag();
                        this->gameArray[coin->posX - 1][coin->posY] = this->gameArray[coin->posX - 1][coin->posY] == 0 ? 1 : 0;
                    }
                    //周围上方金币翻转的条件
                    if(coin->posY + 1 <= 3)
                    {
                        coinBtn[coin->posX][coin->posY + 1] ->changeFlag();
                        this->gameArray[coin->posX][coin->posY + 1] = this->gameArray[coin->posX][coin->posY + 1] == 0 ? 1 : 0;
                    }
                    //周围下方金币翻转的条件
                    if(coin->posY - 1 >= 0)
                    {
                        coinBtn[coin->posX][coin->posY - 1] ->changeFlag();
                        this->gameArray[coin->posX][coin->posY - 1] = this->gameArray[coin->posX][coin->posY - 1] == 0 ? 1 : 0;
                    }


                    //翻完周围金币后，将所有金币解开禁用
                    for(int i = 0; i < 4; i++)
                    {
                        for(int j = 0; j < 4; j++)
                        {
                           this->coinBtn[i][j]->isWin = false;
                        }
                    }

                    //判断是否胜利
                    this->isWin = true;


                    for(int i = 0; i < 4; i++)
                    {
                        for(int j = 0; j < 4; j++)
                        {
                            if(coinBtn[i][j]->flag == false)       //只要有一个是反面，那就算失败
                            {
                                this->isWin = false;
                            }
                        }
                    }



                    if(this->isWin == true)
                    {
                        winSound->play();
                        //胜利了
                        qDebug() << "胜利了";
                        //将胜利的图片砸下来
                        QPropertyAnimation *animation = new QPropertyAnimation(winLabel, "geometry");
                        //设置事件间隔
                        animation->setDuration(1000);
                        //设置开始位置
                        animation->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
                        //设置结束位置
                        animation->setEndValue(QRect(winLabel->x(), winLabel->y() + 160, winLabel->width(), winLabel->height()));
                        //设置缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        //执行动画
                        animation->start();
                        //将所有按钮的胜利标志改为true
                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < 4; j++)
                            {
                                coinBtn[i][j]->isWin = true;
                            }
                        }
                    }
                });

            });

        }
    }

}
//重写绘图事件
void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //画背景上的图标
    pix.load(":/res/Title.png");

    //缩放图片
    //pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);

    painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}


















