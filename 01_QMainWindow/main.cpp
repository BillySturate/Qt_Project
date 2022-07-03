#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDebug>
using namespace std;
int main(int argc, char *argv[])
{
    cout << "开始啦" <<endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    qDebug() << "结束啦" <<endl;
    return a.exec();
}
