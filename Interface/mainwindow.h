#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QtCore>
#include <QtGui>
#include <qmessagebox.h>
#include <QPushButton>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void search();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
