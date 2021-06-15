//
// Created by Menua on 26/05/2021.
//

#include <string>
#include <vector>

using namespace std;

#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_CAR_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_CAR_H


class Car {
private:
    string car_brand;
    string car_regex;
    vector<int> car_shops;

public:
    Car();
    void setCarBrand(const string& p_carbrand);
    string getCarbrand();

    void setCarregex(const string &p_carregex);
    string getCarRegex();

    void setCarShops(const vector<int> &p_carshops);
    vector<int> getCarShops();
    void init(const string& p_carbrand, const string& p_carregex, const vector<int>& p_carshops);

};


#endif //TAPROJECT2021_MENUAHOVHANNISYAN_CAR_H
