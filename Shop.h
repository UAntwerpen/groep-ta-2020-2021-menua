//
// Created by Menua on 26/05/2021.
//
#include <string>
#include <vector>
using namespace std;

#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_SHOP_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_SHOP_H


class Shop {
    int shop_id;
    string shop_name;
    vector<string> shop_brands;
    string shop_address;

public:
    void init(int p_shopid, string p_shopname, vector<string> p_shopbrands,string p_shopaddress);
    vector<string> getShopBrands();
    string getShopName();
    int getShopId();
    void setShopId(const int &p_shopid);
    void setShopName(const string &p_shopname);
    void setShopBrands(const vector<string> &p_shopbrands);

    void setShopAddress(const string& p_shopaddress);
    string getShopAddress();

};


#endif //TAPROJECT2021_MENUAHOVHANNISYAN_SHOP_H
