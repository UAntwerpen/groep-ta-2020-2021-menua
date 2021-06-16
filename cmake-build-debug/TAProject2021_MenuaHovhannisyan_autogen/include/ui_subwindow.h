/********************************************************************************
** Form generated from reading UI file 'subwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWINDOW_H
#define UI_SUBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QLineEdit *shopname_txt;
    QLabel *label1;
    QLabel *label_2;
    QFrame *line_6;
    QFrame *line_7;
    QLabel *error_lbl;
    QPushButton *add_btn;
    QLabel *label1_2;
    QLabel *label1_3;
    QComboBox *shopbrands_combo;
    QLineEdit *shopaddress_txt;
    QLabel *Comment_txt;

    void setupUi(QMainWindow *SubWindow)
    {
        if (SubWindow->objectName().isEmpty())
            SubWindow->setObjectName(QString::fromUtf8("SubWindow"));
        SubWindow->setEnabled(true);
        SubWindow->resize(269, 268);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SubWindow->sizePolicy().hasHeightForWidth());
        SubWindow->setSizePolicy(sizePolicy);
        SubWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        SubWindow->setAnimated(true);
        centralwidget = new QWidget(SubWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 60, 271, 221));
        line->setStyleSheet(QString::fromUtf8("color: rgb(47, 50, 58);"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(500);
        line->setFrameShape(QFrame::VLine);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 0, 271, 61));
        line_2->setStyleSheet(QString::fromUtf8("color: rgb(34, 36, 42);"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(500);
        line_2->setFrameShape(QFrame::HLine);
        shopname_txt = new QLineEdit(centralwidget);
        shopname_txt->setObjectName(QString::fromUtf8("shopname_txt"));
        shopname_txt->setGeometry(QRect(120, 80, 131, 21));
        label1 = new QLabel(centralwidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(20, 80, 91, 16));
        label1->setStyleSheet(QString::fromUtf8("background-color:none;\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 10, 101, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;\n"
"font-size: 20px;"));
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(10, 250, 251, 16));
        line_6->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 50, 58);\n"
""));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(0, 50, 271, 20));
        line_7->setStyleSheet(QString::fromUtf8("background-color: none;\n"
""));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        error_lbl = new QLabel(centralwidget);
        error_lbl->setObjectName(QString::fromUtf8("error_lbl"));
        error_lbl->setGeometry(QRect(10, 130, 311, 16));
        error_lbl->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(199, 56, 56);"));
        add_btn = new QPushButton(centralwidget);
        add_btn->setObjectName(QString::fromUtf8("add_btn"));
        add_btn->setGeometry(QRect(20, 220, 231, 21));
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
        label1_2->setGeometry(QRect(20, 120, 91, 16));
        label1_2->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;"));
        label1_3 = new QLabel(centralwidget);
        label1_3->setObjectName(QString::fromUtf8("label1_3"));
        label1_3->setGeometry(QRect(20, 160, 91, 16));
        label1_3->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(255, 255, 255);\n"
"font: bold Calibri;"));
        shopbrands_combo = new QComboBox(centralwidget);
        shopbrands_combo->setObjectName(QString::fromUtf8("shopbrands_combo"));
        shopbrands_combo->setGeometry(QRect(120, 120, 131, 21));
        shopbrands_combo->setStyleSheet(QString::fromUtf8(""));
        shopaddress_txt = new QLineEdit(centralwidget);
        shopaddress_txt->setObjectName(QString::fromUtf8("shopaddress_txt"));
        shopaddress_txt->setGeometry(QRect(120, 160, 131, 21));
        Comment_txt = new QLabel(centralwidget);
        Comment_txt->setObjectName(QString::fromUtf8("Comment_txt"));
        Comment_txt->setGeometry(QRect(20, 190, 231, 16));
        Comment_txt->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(199, 56, 56);"));
        SubWindow->setCentralWidget(centralwidget);
        line_2->raise();
        line->raise();
        shopname_txt->raise();
        label1->raise();
        label_2->raise();
        line_6->raise();
        line_7->raise();
        error_lbl->raise();
        add_btn->raise();
        label1_2->raise();
        label1_3->raise();
        shopbrands_combo->raise();
        shopaddress_txt->raise();
        Comment_txt->raise();

        retranslateUi(SubWindow);

        QMetaObject::connectSlotsByName(SubWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SubWindow)
    {
        SubWindow->setWindowTitle(QCoreApplication::translate("SubWindow", "SubWindow", nullptr));
#if QT_CONFIG(statustip)
        centralwidget->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        label1->setText(QCoreApplication::translate("SubWindow", "Shop Name:", nullptr));
        label_2->setText(QCoreApplication::translate("SubWindow", "Add Shop", nullptr));
        error_lbl->setText(QString());
        add_btn->setText(QCoreApplication::translate("SubWindow", "Add Shop", nullptr));
        label1_2->setText(QCoreApplication::translate("SubWindow", "Shop Brands:", nullptr));
        label1_3->setText(QCoreApplication::translate("SubWindow", "Shop Address:", nullptr));
        Comment_txt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SubWindow: public Ui_SubWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWINDOW_H
