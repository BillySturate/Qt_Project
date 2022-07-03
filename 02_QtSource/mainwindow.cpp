#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //ui->actionnew->setIcon(QIcon("E:\\Fatigue driving detection system\\images\\555.ico"));

    //使用QT资源 ": +前缀名 + 文件名"
    ui->actionnew->setIcon(QIcon(":/images/555.ico"));
    ui->actionopen->setIcon(QIcon(":/images/ui3.png"));




}

MainWindow::~MainWindow()
{
    delete ui;
}

