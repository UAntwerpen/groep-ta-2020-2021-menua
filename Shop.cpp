//
// Created by Menua on 26/05/2021.
//

#include "Shop.h"

void Shop::setShopId(const int &p_shopid) {
    shop_id = p_shopid;
}

int Shop::getShopId() {
    return shop_id;
}

void Shop::setShopName(const string &p_shopname) {
    shop_name = p_shopname;
}

string Shop::getShopName() {
    return shop_name;
}

void Shop::setShopBrands(const vector<string> &p_shopbrands) {
    shop_brands = p_shopbrands;
}

vector<string> Shop::getShopBrands() {
    return shop_brands;
}

void Shop::init(int p_shopid, string p_shopname, vector<string> p_shopbrands, string p_shopaddress) {
    setShopId(p_shopid);
    setShopName(p_shopname);
    setShopBrands(p_shopbrands);
    setShopAddress(p_shopaddress);
}

string Shop::getShopAddress() {
    return shop_address;
}

void Shop::setShopAddress(const string& p_shopaddress) {
    shop_address = p_shopaddress;
}
