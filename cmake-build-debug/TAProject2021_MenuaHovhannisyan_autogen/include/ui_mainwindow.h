/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QPushButton *search_btn;
    QLineEdit *input_txt;
    QLabel *label1;
    QFrame *line_5;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line_6;
    QLabel *label_6;
    QFrame *line_9;
    QLabel *label2;
    QListWidget *result_lw;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(200, 461);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 70, 200, 391));
        line->setStyleSheet(QString::fromUtf8("color: rgb(47, 50, 58);"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(500);
        line->setFrameShape(QFrame::VLine);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 0, 201, 91));
        line_2->setStyleSheet(QString::fromUtf8("color: rgb(34, 36, 42);"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(500);
        line_2->setFrameShape(QFrame::HLine);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(20, 650, 1261, 51));
        line_3->setStyleSheet(QString::fromUtf8("color: rgb(34, 36, 42);"));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(500);
        line_3->setFrameShape(QFrame::HLine);
        search_btn = new QPushButton(centralwidget);
        search_btn->setObjectName(QString::fromUtf8("search_btn"));
        search_btn->setGeometry(QRect(20, 140, 161, 21));
        search_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"      background-color: rgb(66, 135, 245);\n"
"      border-radius: 10px;\n"
"      font: bold 14px Calibri;\n"
"color:white;\n"
"  }\n"
"\n"
"QPushButton:hover{\n"
" background-color: rgb(47, 96, 173);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: rgb(21, 43, 79);\n"
"}"));
        input_txt = new QLineEdit(centralwidget);
        input_txt->setObjectName(QString::fromUtf8("input_txt"));
        input_txt->setGeometry(QRect(90, 100, 101, 20));
        label1 = new QLabel(centralwidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(10, 100, 71, 16));
        label1->setStyleSheet(QString::fromUtf8("background-color: rgb(47,50,58);\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;"));
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 170, 181, 20));
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 50, 58);\n"
""));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 10, 111, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 36, 42);\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;\n"
"font-size: 20px;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 40, 91, 20));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 36, 42);\n"
"color: rgb(66, 135, 245);\n"
"font: bold Calibri;\n"
"font-size: 20px;"));
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(10, 80, 181, 20));
        line_6->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 50, 58);\n"
""));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(450, 660, 531, 81));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 36, 42);\n"
"color: white;\n"
"font: bold 8px Calibri"));
        label_6->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(10, 410, 181, 20));
        line_9->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 50, 58);\n"
""));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(40, 430, 121, 16));
        label2->setStyleSheet(QString::fromUtf8("background-color: rgb(47,50,58);\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;"));
        result_lw = new QListWidget(centralwidget);
        result_lw->setObjectName(QString::fromUtf8("result_lw"));
        result_lw->setGeometry(QRect(10, 190, 181, 221));
        result_lw->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 50, 58);\n"
"color: white;\n"
"border: none;"));
        MainWindow->setCentralWidget(centralwidget);
        line_2->raise();
        line_3->raise();
        line->raise();
        search_btn->raise();
        input_txt->raise();
        label1->raise();
        line_5->raise();
        label_2->raise();
        label_3->raise();
        line_6->raise();
        label_6->raise();
        line_9->raise();
        label2->raise();
        result_lw->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(statustip)
        centralwidget->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        search_btn->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "Model Naam: ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Car Dealer", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Founder", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\302\251 Copyrights Denis Yusuf & Menua Hovhannisyan. All Rights Reserved\n"
"\n"
"Vaccin Distributie Simulatie", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "Menua Hovhannisyan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
