#include "widget.h"
#include "widget2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //Widget2 s2;
    w.show();
    return a.exec();
}
