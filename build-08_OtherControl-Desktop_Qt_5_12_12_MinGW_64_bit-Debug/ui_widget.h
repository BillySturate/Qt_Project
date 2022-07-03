/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QWidget *page_5;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_10;
    QWidget *page_2;
    QPushButton *pushButton_11;
    QWidget *page_3;
    QPushButton *pushButton_12;
    QWidget *page_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QPushButton *btn_scrollArea;
    QPushButton *btn_ToolBox;
    QPushButton *btn_TabWidget;
    QComboBox *comboBox;
    QPushButton *btn_select;
    QLabel *lb_image;
    QProgressBar *progressBar;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(130, 70, 411, 331));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        scrollArea = new QScrollArea(page_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(130, 0, 141, 311));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 330));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        toolBox = new QToolBox(page_5);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(120, 20, 191, 271));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 191, 181));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_10 = new QPushButton(page);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout_2->addWidget(pushButton_10);

        toolBox->addItem(page, QString::fromUtf8("\345\256\266\344\272\272"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 191, 181));
        pushButton_11 = new QPushButton(page_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(40, 60, 93, 28));
        toolBox->addItem(page_2, QString::fromUtf8("\346\234\213\345\217\213"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        pushButton_12 = new QPushButton(page_3);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(40, 50, 93, 28));
        toolBox->addItem(page_3, QString::fromUtf8("\351\273\221\345\220\215\345\215\225"));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        tabWidget = new QTabWidget(page_6);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(60, 20, 281, 251));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        stackedWidget->addWidget(page_6);
        btn_scrollArea = new QPushButton(Widget);
        btn_scrollArea->setObjectName(QString::fromUtf8("btn_scrollArea"));
        btn_scrollArea->setGeometry(QRect(610, 180, 93, 28));
        btn_ToolBox = new QPushButton(Widget);
        btn_ToolBox->setObjectName(QString::fromUtf8("btn_ToolBox"));
        btn_ToolBox->setGeometry(QRect(610, 120, 93, 28));
        btn_TabWidget = new QPushButton(Widget);
        btn_TabWidget->setObjectName(QString::fromUtf8("btn_TabWidget"));
        btn_TabWidget->setGeometry(QRect(610, 70, 93, 28));
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(100, 420, 87, 22));
        btn_select = new QPushButton(Widget);
        btn_select->setObjectName(QString::fromUtf8("btn_select"));
        btn_select->setGeometry(QRect(100, 490, 93, 28));
        lb_image = new QLabel(Widget);
        lb_image->setObjectName(QString::fromUtf8("lb_image"));
        lb_image->setGeometry(QRect(640, 260, 131, 71));
        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(260, 440, 118, 23));
        progressBar->setValue(24);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(540, 510, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(460, 510, 46, 22));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);
        toolBox->setCurrentIndex(0);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QApplication::translate("Widget", "PushButton", nullptr));
        pushButton_6->setText(QApplication::translate("Widget", "PushButton", nullptr));
        pushButton_5->setText(QApplication::translate("Widget", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("Widget", "PushButton", nullptr));
        pushButton_9->setText(QApplication::translate("Widget", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "PushButton", nullptr));
        pushButton_8->setText(QApplication::translate("Widget", "PushButton", nullptr));
        pushButton_7->setText(QApplication::translate("Widget", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "PushButton", nullptr));
        pushButton_10->setText(QApplication::translate("Widget", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Widget", "\345\256\266\344\272\272", nullptr));
        pushButton_11->setText(QApplication::translate("Widget", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Widget", "\346\234\213\345\217\213", nullptr));
        pushButton_12->setText(QApplication::translate("Widget", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("Widget", "\351\273\221\345\220\215\345\215\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "google", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "baidu", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "souhu", nullptr));
        btn_scrollArea->setText(QApplication::translate("Widget", "scrolArea", nullptr));
        btn_ToolBox->setText(QApplication::translate("Widget", "ToolBox", nullptr));
        btn_TabWidget->setText(QApplication::translate("Widget", "TabWidget", nullptr));
        btn_select->setText(QApplication::translate("Widget", "\351\200\211\344\270\255\346\213\226\346\213\211\346\234\272", nullptr));
        lb_image->setText(QApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
