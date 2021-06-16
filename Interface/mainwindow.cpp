#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(System* p_system,QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    system = p_system;
    ui->setupUi(this);
    connect(ui->search_btn, SIGNAL(released()),this,SLOT(search()));
    connect(ui->add_btn, SIGNAL(released()),this,SLOT(add()));
    for(auto car: system->getCars()){
        ui->shopbrands_combo->addItem(QString::fromStdString(car->getCarbrand()));
    }
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

void MainWindow::add() {
    if(!ui->shopname_txt->text().isEmpty() and !ui->shopaddress_txt->text().isEmpty()){
        system->addShop(ui->shopname_txt->text().toStdString(),ui->shopbrands_combo->currentText().toStdString(),ui->shopaddress_txt->text().toStdString());
        system->updateShops();
        system->updateCarShops();
        ui->error_lbl_3->setText("Successfully Shop added!");
    }
    else{
        ui->error_lbl_2->setText("*Please fill in all the fields!");
    }
}
