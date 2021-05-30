#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(const string &file, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    filename = file;
    ui->setupUi(this);
    connect(ui->search_btn, SIGNAL(released()),this,SLOT(search()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search() {
    /*ui->result_lw->clear();
    ui->result_lw->addItem("Winkel1: BMW");
    ui->result_lw->addItem("Winkel1: MERCEDES");
    ui->result_lw->addItem("Winkel1: AUDI");
    ui->result_lw->addItem(ui->input_txt->text());*/



    //input omzetten in capitals
    string tmp;
    tmp = ui->input_txt->text().toStdString();
    // inlezen uit file
    ifstream input(filename);
    json j;
    input >> j;
    int it = 0;

    for (auto i: j["Cars"]){
        if(tmp == i["CarBrand"]){
            it += 1;
            break;
        }
    }

    if(it > 0){
        cout << "[FOUND]" << endl;
        ui->result_lw->addItem("Winkel1: BMW");
        ui->result_lw->addItem("Winkel1: MERCEDES");
        ui->result_lw->addItem("Winkel1: AUDI");
    }
    else{
        cout << "[NOT FOUND]" << endl;
    }

}