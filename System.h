//
// Created by Menua on 26/05/2021.
//

#include <string>
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <QApplication>
#include "Shop.h"
#include "Car.h"
#include <sstream>
#include "TA_MenuaHovhannisyan/RE.h"


using namespace std;
using namespace nlohmann;

#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_SYSTEM_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_SYSTEM_H

class gui;

class System {
private:
    string file;
    vector<Car*> cars;
    vector<Shop*> shops;
public:
    int argc;
    char **argv;

    System(const string &file_name,int p_argc,char *argv[]);

    int start();

    void parserJson(const string &file_name);

    vector<Car*> getCars();
    vector<Shop*> getShops();

    Car* checkinput(const string &p_input);

    vector<Shop*> getCarShop(Car* p_car,vector<Shop*> p_shop);
    string getShopBrand(vector<string> shopbrands);

    void addShop(string p_shopname, string p_shopbrand, string p_shopaddress);
    void updateShops();
};

#include "Interface/mainwindow.h"
#endif //TAPROJECT2021_MENUAHOVHANNISYAN_SYSTEM_H
