#include "widget.h"
#include <QApplication>     //包含一个应用程序类的头文件

//main程序入口, argc命令行变量的数量 argv命令行变量的数组
int main(int argc, char *argv[])
{
    //a应用程序对象，QT中，应用程序对象有且仅有一个
    QApplication a(argc, argv);
    Widget w;
    w.show();
    //让应用进入消息循环
    //让代码阻塞在这行
    return a.exec();
}
