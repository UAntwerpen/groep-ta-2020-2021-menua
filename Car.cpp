//
// Created by Menua on 26/05/2021.
//

#include "Car.h"

void Car::setCarBrand(const string& p_carbrand) {
    car_brand = p_carbrand;
}

string Car::getCarbrand() {
    return car_brand;
}

void Car::setCarregex(const string &p_carregex) {
    car_regex = p_carregex;
}

string Car::getCarRegex() {
    return car_regex;
}

void Car::setCarShops(const vector<int> &p_carshops) {
    car_shops = p_carshops;
}

vector<int> Car::getCarShops() {
    return car_shops;
}

void Car::init(const string& p_carbrand, const string& p_carregex, const vector<int>& p_carshops) {
    setCarBrand(p_carbrand);
    setCarregex(p_carregex);
    setCarShops(p_carshops);
}

Car::Car() {
    car_brand = "";
    car_regex = "";
    car_shops = {};
}


