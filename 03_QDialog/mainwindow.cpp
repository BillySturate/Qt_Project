#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮，弹出一个对话框
    connect(ui->actionnew, &QAction::triggered,[=](){
        //对话框分类
        //模态对话框 (不可以对其他窗口进行操作) 非模态对话框 (可以对其他窗口进行操作)
        //模态创建 阻塞功能
//        QDialog dlg(this);
//        dlg.resize(400, 300);
//        dlg.exec();
//        qDebug() << "模态对话框弹出了";

        //非模态对话框
//        //QDialog dlg2(this);
//        QDialog *dlg2 = new QDialog(this);
//        dlg2->resize(500, 400);
//        dlg2->show();
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);   //55号属性
//        qDebug() << "非模态对话框弹出了";

        //消息对话框
        //错误对话框
        //QMessageBox::critical(this, "critical", "错误");

        //信息对话框
        //QMessageBox::information(this, "info", "信息");

        //提问对话框
        //参数1 父亲    参数2 标题       参数3 提示内容      参数4 案件类型       参数5 默认关联回车按键
//        if(QMessageBox::Save == QMessageBox::question(this, "ques", "提问", QMessageBox::Save|QMessageBox::Cancel, QMessageBox::Cancel))
//        {
//            qDebug() << "选择的是保存";
//        }else{

//            qDebug() << "选择的是取消";
//        }


        //警告对话框
        //QMessageBox::warning(this, "warning", "警告");

        //其他对话框
        //颜色对话框
        //QColor color = QColorDialog::getColor(QColor(255, 0, 0));
        //qDebug() << "r = " << color.red() << "g = " << color.green() << "b = " << color.blue();


        //文件对话框 参数一 父亲      参数二 标题      参数三 默认打开路径      参数四 过滤文件格式
        //返回值是选取的路径
        //Qsting str = QFileDialog::getOpenFileName(this, "打开文件", "C:/Users/LH/Desktop/数据库课程设计3/数据库课程设计", "*.py");
        //qDebug() << str;


        //字体对话框
        bool flag;
        auto font = QFontDialog::getFont(&flag, QFont("华文彩云", 36));
        qDebug() << "字体" <<font.family().toUtf8().data() << "字号" << font.pointSize() << "是否加粗" <<font.bold() << "是否倾斜" << font.italic();

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

