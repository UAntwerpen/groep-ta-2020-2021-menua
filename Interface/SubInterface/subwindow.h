#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QtCore>
#include <QtGui>
#include <qmessagebox.h>
#include <QPushButton>
#include <QMainWindow>
#include <QPixmap>
#include <QtCore>
#include <QtGui>
#include <qmessagebox.h>
#include <QPushButton>
#include "../../System.h"
#include "../../json.hpp"
#include <iostream>
#include <fstream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class SubWindow; }
QT_END_NAMESPACE

class SubWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit SubWindow(QWidget *parent = nullptr);
    ~SubWindow();

private:
    Ui::SubWindow *ui;
};
#endif // SUBWINDOW_H
