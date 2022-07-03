#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //QSpinBox移动 QSlider跟着移动
    void(QSpinBox:: *spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal, ui->horizontalSlider, &QSlider::setValue);
    //void(QSlider:: *qsSignal)(int) = &QSlider::setValue;          错误的
    //connect(ui->horizontalSlider, qsSignal, ui->spinBox, &QSpinBox::valueChanged);
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);


}
//设置数字
void SmallWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}

//获取数字
int SmallWidget::getNum()
{
    return ui->spinBox->value();
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
