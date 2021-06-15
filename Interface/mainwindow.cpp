#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(System* p_system, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    system = p_system;
    ui->setupUi(this);
    connect(ui->search_btn, SIGNAL(released()),this,SLOT(search()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search() {
    ui->result_lw->clear();
    ui->error_lbl->setText("");
    Car* car;
    car = system->checkinput(ui->input_txt->text().toStdString());
    if(car != nullptr){
        vector<Shop*> shops = system->getCarShop(car,system->getShops());
        for(auto shop: shops){
            QString d = QString::fromStdString("Name: " + shop->getShopName() + "\n" + "Address: " + shop->getShopAddress() + "\n" + "Brands: " +system->getShopBrand(shop->getShopBrands()) + "\n");
            ui->result_lw->addItem(d);
        }

    }
    else{
        ui->error_lbl->setText("*Vehicle not found in the database, Please try again!");
    }
}