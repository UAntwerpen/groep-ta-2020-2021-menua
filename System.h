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
    System(const string &file_name);

    int start(int p_argc, char *p_argv[]);

    void parserJson(const string &file_name);

    vector<Car*> getCars();
    vector<Shop*> getShops();

    Car* checkinput(const string &p_input);

    vector<Shop*> getCarShop(Car* p_car,vector<Shop*> p_shop);
    string getShopBrand(vector<string> shopbrands);
};

#include "Interface/mainwindow.h"
#endif //TAPROJECT2021_MENUAHOVHANNISYAN_SYSTEM_H
