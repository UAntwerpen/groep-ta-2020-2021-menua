#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QtCore>
#include <QtGui>
#include <qmessagebox.h>
#include <QPushButton>
#include "../System.h"
#include "../json.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(System* p_system,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void search();
    void add();

private:
    Ui::MainWindow *ui;
    System* system;


};

#endif // MAINWINDOW_H
