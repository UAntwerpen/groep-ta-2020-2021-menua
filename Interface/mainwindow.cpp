#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->search_btn, SIGNAL(released()),this,SLOT(search()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search() {
    ui->result_lw->clear();
    ui->result_lw->addItem("Winkel1: BMW");
    ui->result_lw->addItem("Winkel1: MERCEDES");
    ui->result_lw->addItem("Winkel1: AUDI");
    ui->result_lw->addItem(ui->input_txt->text());
}
