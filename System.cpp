//
// Created by Menua on 26/05/2021.
//

#include "System.h"

System::System(const string &file_name) {
    file = file_name;
}

int System::start(int p_argc, char *p_argv[]) {
    parserJson(file);

    QApplication a(p_argc, p_argv);
    MainWindow w(this);
    w.show();

    return a.exec();
}

void System::parserJson(const string &file_name) {
    //maakt klassen Car en Shop aan, met hulp van de json file.

    //input omzetten in capitals
    string tmp;
    // inlezen uit file
    ifstream input(file_name);
    json j;
    input >> j;

    for (auto i: j["Cars"]){
        string carbrand;
        string carregex;
        vector<int> carshops;

        //carbrand
        carbrand = i["CarBrand"];

        //carregex
        carregex = i["CarRegex"];

        //Carshops
        string tmp = i["CarShops"];
        for(auto t: tmp){
            if(t!= '-'){
                int tmpshop;
                string strinshop;
                strinshop.push_back(t);
                stringstream tt;
                tt << strinshop;
                tt >> tmpshop;
                carshops.push_back(tmpshop);
            }
        }

        Car* car = new Car;
        car->init(carbrand,carregex,carshops);
        cars.push_back(car);
        cout << car->getCarRegex();
    }
    for(auto o:j["Shops"]){
        int shopid;
        string shopname;
        string shopaddress;
        vector<string> shopbrands;


        //shopid
        string strinshopid = o["ShopId"];
        stringstream ll;
        ll << strinshopid;
        ll >> shopid;

        //shopname
        shopname = o["ShopName"];

        //shopaddress
        shopaddress = o["ShopAddress"];

        //shopbrands
        string tvm = o["ShopBrands"];
        string r;
        for (int i = 0; i < tvm.size(); ++i) {
            if(i == tvm.size()-1){
                r += tvm[i];
                shopbrands.push_back(r);
                r ="";
            }
            else{
                if(tvm[i] == '-'){
                    shopbrands.push_back(r);
                    r="";
                }
                else{
                    r+=tvm[i];
                }
            }
        }

        Shop* shop = new Shop;
        shop->init(shopid,shopname,shopbrands,shopaddress);
        shops.push_back(shop);
    }

}

vector<Car*> System::getCars() {
    return cars;
}

vector<Shop*> System::getShops() {
    return shops;
}

Car* System::checkinput(const string &p_input) {
    for(auto car: cars){

        bool accept = false;
        RE reg;
        pair<vector<Node *>, vector<Edge *>> pp;
        pp = reg.toENFA(car->getCarRegex());
        accept = reg.ENFAtoNFA(pp.first,pp.second).toDFA().accepts(p_input);

        if(accept){
            return car;
        }
    }

    return nullptr;
}

vector<Shop *> System::getCarShop(Car* p_car,vector<Shop*> p_shop) {
    vector<Shop*> result;
    for(auto i:p_car->getCarShops()){
        for(auto sho:p_shop){
            if(i == sho->getShopId()){
                result.push_back(sho);
            }
        }

    }
    return result;
}

string System::getShopBrand(vector<string> shopbrands) {
    string result;
    for (int i = 0; i < shopbrands.size(); ++i) {
        if(i==shopbrands.size()-1){
            result += shopbrands[i];
        }
        else{
            result += shopbrands[i] + ", ";
        }
    }
    return result;
}
