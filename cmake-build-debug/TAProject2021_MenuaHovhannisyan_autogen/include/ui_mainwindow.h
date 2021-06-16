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
#include <QtWidgets/QComboBox>
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
    QPushButton *search_btn;
    QLineEdit *input_txt;
    QLabel *label1;
    QFrame *line_5;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line_6;
    QLabel *label2;
    QListWidget *result_lw;
    QFrame *line_7;
    QLabel *error_lbl;
    QFrame *line_8;
    QComboBox *shopbrands_combo;
    QLabel *label1_3;
    QPushButton *add_btn;
    QLabel *label1_2;
    QLineEdit *shopname_txt;
    QLineEdit *shopaddress_txt;
    QLabel *label1_4;
    QLabel *error_lbl_2;
    QLabel *error_lbl_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(448, 627);
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
        line->setGeometry(QRect(0, 60, 451, 581));
        line->setStyleSheet(QString::fromUtf8("color: rgb(47, 50, 58);"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(500);
        line->setFrameShape(QFrame::VLine);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 0, 451, 61));
        line_2->setStyleSheet(QString::fromUtf8("color: rgb(34, 36, 42);"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(500);
        line_2->setFrameShape(QFrame::HLine);
        search_btn = new QPushButton(centralwidget);
        search_btn->setObjectName(QString::fromUtf8("search_btn"));
        search_btn->setGeometry(QRect(280, 80, 141, 21));
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
        input_txt->setGeometry(QRect(100, 80, 131, 21));
        label1 = new QLabel(centralwidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(20, 80, 71, 16));
        label1->setStyleSheet(QString::fromUtf8("background-color: rgb(47,50,58);\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;"));
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 580, 421, 20));
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 50, 58);\n"
""));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 10, 111, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;\n"
"font-size: 20px;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 10, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(66, 135, 245);\n"
"font: bold Calibri;\n"
"font-size: 20px;"));
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(10, 110, 421, 20));
        line_6->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 50, 58);\n"
""));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(170, 600, 121, 16));
        label2->setStyleSheet(QString::fromUtf8("background-color: rgb(47,50,58);\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;"));
        result_lw = new QListWidget(centralwidget);
        result_lw->setObjectName(QString::fromUtf8("result_lw"));
        result_lw->setGeometry(QRect(10, 130, 421, 261));
        result_lw->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 50, 58);\n"
"color: white;\n"
"border: none;"));
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(0, 50, 451, 20));
        line_7->setStyleSheet(QString::fromUtf8("background-color: none;\n"
""));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        error_lbl = new QLabel(centralwidget);
        error_lbl->setObjectName(QString::fromUtf8("error_lbl"));
        error_lbl->setGeometry(QRect(10, 130, 311, 16));
        error_lbl->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(199, 56, 56);"));
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(10, 400, 421, 20));
        line_8->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 50, 58);\n"
""));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        shopbrands_combo = new QComboBox(centralwidget);
        shopbrands_combo->setObjectName(QString::fromUtf8("shopbrands_combo"));
        shopbrands_combo->setGeometry(QRect(140, 470, 171, 21));
        shopbrands_combo->setStyleSheet(QString::fromUtf8(""));
        label1_3 = new QLabel(centralwidget);
        label1_3->setObjectName(QString::fromUtf8("label1_3"));
        label1_3->setGeometry(QRect(40, 510, 91, 16));
        label1_3->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;"));
        add_btn = new QPushButton(centralwidget);
        add_btn->setObjectName(QString::fromUtf8("add_btn"));
        add_btn->setGeometry(QRect(140, 550, 171, 21));
        add_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"      background-color: rgb(142, 209, 119);\n"
"      border-radius: 10px;\n"
"      font: bold 14px Calibri;\n"
"color:white;\n"
"  }\n"
"\n"
"QPushButton:hover{\n"
" background-color: rgb(123, 209, 94);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color: rgb(96, 163, 73);\n"
"}"));
        label1_2 = new QLabel(centralwidget);
        label1_2->setObjectName(QString::fromUtf8("label1_2"));
        label1_2->setGeometry(QRect(40, 470, 91, 16));
        label1_2->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;"));
        shopname_txt = new QLineEdit(centralwidget);
        shopname_txt->setObjectName(QString::fromUtf8("shopname_txt"));
        shopname_txt->setGeometry(QRect(140, 430, 171, 21));
        shopaddress_txt = new QLineEdit(centralwidget);
        shopaddress_txt->setObjectName(QString::fromUtf8("shopaddress_txt"));
        shopaddress_txt->setGeometry(QRect(140, 510, 171, 21));
        label1_4 = new QLabel(centralwidget);
        label1_4->setObjectName(QString::fromUtf8("label1_4"));
        label1_4->setGeometry(QRect(40, 430, 91, 16));
        label1_4->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;"));
        error_lbl_2 = new QLabel(centralwidget);
        error_lbl_2->setObjectName(QString::fromUtf8("error_lbl_2"));
        error_lbl_2->setGeometry(QRect(10, 570, 311, 16));
        error_lbl_2->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(199, 56, 56);"));
        error_lbl_3 = new QLabel(centralwidget);
        error_lbl_3->setObjectName(QString::fromUtf8("error_lbl_3"));
        error_lbl_3->setGeometry(QRect(10, 570, 311, 16));
        error_lbl_3->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(142, 209, 119);"));
        MainWindow->setCentralWidget(centralwidget);
        line_2->raise();
        line->raise();
        search_btn->raise();
        input_txt->raise();
        label1->raise();
        line_5->raise();
        label_2->raise();
        label_3->raise();
        line_6->raise();
        label2->raise();
        result_lw->raise();
        line_7->raise();
        error_lbl->raise();
        line_8->raise();
        shopbrands_combo->raise();
        label1_3->raise();
        add_btn->raise();
        label1_2->raise();
        shopname_txt->raise();
        shopaddress_txt->raise();
        label1_4->raise();
        error_lbl_2->raise();
        error_lbl_3->raise();

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
        label2->setText(QCoreApplication::translate("MainWindow", "Menua Hovhannisyan", nullptr));
        error_lbl->setText(QString());
        label1_3->setText(QCoreApplication::translate("MainWindow", "Shop Address:", nullptr));
        add_btn->setText(QCoreApplication::translate("MainWindow", "Add Shop", nullptr));
        label1_2->setText(QCoreApplication::translate("MainWindow", "Shop Brands:", nullptr));
        label1_4->setText(QCoreApplication::translate("MainWindow", "Shop Name:", nullptr));
        error_lbl_2->setText(QString());
        error_lbl_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
