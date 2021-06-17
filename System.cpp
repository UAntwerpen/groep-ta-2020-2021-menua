//
// Created by Menua on 26/05/2021.
//

#include "System.h"

System::System(const string &file_name,int p_argc,char *p_argv[]) {
    file = file_name;
    argc = p_argc;
    argv = p_argv;
}

int System::start() {
    parserJson(file);
    QApplication a(argc, argv);
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

void System::addShop(string p_shopname, string p_shopbrand, string p_shopaddress) {
    ifstream input(file);
    json j;
    input >> j;

    string jsondoc;
    string newitem;
    bool found = false;
    string fndid;

    int id;
    string sid;
    string shopname = p_shopname;
    string shopbrand = p_shopbrand;
    string shopaddress = p_shopaddress;

    for (int i = 0; i < j["Shops"].size(); ++i) {
        if(i==j["Shops"].size()-1){
            string tmp;
            tmp = j["Shops"][i]["ShopId"];
            stringstream ss;
            ss << tmp;
            ss >> id;
            id += 1;
        }
    }
    stringstream ss;
    ss << id;
    ss >> sid;



    jsondoc = "{\n\t\"Shops\":[\n\t";

    for (int i = 0; i < j["Shops"].size(); ++i) {
        string tmpdoc;
        string nme = j["Shops"][i]["ShopName"];
        string rid = j["Shops"][i]["ShopId"];
        string brand =j["Shops"][i]["ShopBrands"];
        string address = j["Shops"][i]["ShopAddress"];

        if(j["Shops"][i]["ShopName"] == p_shopname and j["Shops"][i]["ShopAddress"] == p_shopaddress){
            brand += "-" + p_shopbrand;
            found = true;
            fndid = j["Shops"][i]["ShopId"];
        }
        if(i == j["Shops"].size()-1){
            tmpdoc = "{\n\t\t\"ShopId\":\"" + rid + "\",\n\t\t\"ShopName\":\"" + nme + "\",\n\t\t\"ShopBrands\":\"" + brand + "\",\n\t\t\"ShopAddress\":\"" + address + "\"\n\t}";
        }
        else{
            tmpdoc = "{\n\t\t\"ShopId\":\"" + rid + "\",\n\t\t\"ShopName\":\"" + nme + "\",\n\t\t\"ShopBrands\":\"" + brand + "\",\n\t\t\"ShopAddress\":\"" + address + "\"\n\t},\n\t";
        }
        jsondoc += tmpdoc;
    }

    if(!found){
        newitem = ",\n\t{\n\t\t\"ShopId\":\"" + sid + "\",\n\t\t\"ShopName\":\"" + shopname + "\",\n\t\t\"ShopBrands\":\"" + shopbrand + "\",\n\t\t\"ShopAddress\":\"" + shopaddress + "\"\n\t}";
        jsondoc += newitem;
    }

    jsondoc +="\n\t],\n\n\t\"Cars\":[\n\t";

    for (int i = 0; i < j["Cars"].size(); ++i) {
        string tmpdoc;
        string brnd = j["Cars"][i]["CarBrand"];
        string reg = j["Cars"][i]["CarRegex"];
        string cshops = j["Cars"][i]["CarShops"];

        if(p_shopbrand == brnd){
            if(found){
                if(j["Cars"][i]["CarShops"] == ""){
                    cshops += fndid;
                }else{
                    cshops += "-" + fndid;
                }
            }
            else{
                for(auto cr:cars){
                    if(cr->getCarbrand() == brnd){
                        cr->getCarShops().push_back(id);
                    }
                }
                cshops += "-" + sid;
            }
        }

        if(i == j["Cars"].size()-1){
            tmpdoc = "{\n\t\t\"CarBrand\":\"" + brnd + "\",\n\t\t\"CarRegex\":\"" + reg + "\",\n\t\t\"CarShops\":\"" + cshops + "\"\n\t}";
        }
        else{
            tmpdoc = "{\n\t\t\"CarBrand\":\"" + brnd + "\",\n\t\t\"CarRegex\":\"" + reg + "\",\n\t\t\"CarShops\":\"" + cshops + "\"\n\t},\n\t";
        }
        jsondoc += tmpdoc;
    }

    jsondoc += "]\n}";

    ofstream infile;
    infile.open(file);
    infile << jsondoc;
    infile.close();

}

void System::updateShops() {
    ifstream input(file);
    json j;
    input >> j;

    for(auto k:j["Shops"]){
        bool found = false;
        for(auto i:shops){
            string tmp = k["ShopId"];
            int id;
            stringstream ss;
            ss << tmp;
            ss >> id;
            if(i->getShopId() == id){
                found = true;
                break;
            }

        }
        if(!found){
            int id;
            string shopname = k["ShopName"];
            vector<string> shopbrands;
            string shopaddress = k["ShopAddress"];

            string tmpid = k["ShopId"];
            stringstream ss;
            ss << tmpid;
            ss >> id;

            string tmpbrand = k["ShopBrands"];
            shopbrands.push_back(tmpbrand);

            Shop* shop = new Shop;
            shop->init(id,shopname,shopbrands,shopaddress);
            shops.push_back(shop);
        }
    }


}

void System::updateCarShops() {
    ifstream input(file);
    json j;
    input >> j;

    for(auto car:j["Cars"]){
        vector<int> shopsvec;
        string carname = car["CarBrand"];

        string tmp = car["CarShops"];
        for(auto t: tmp){
            if(t!= '-'){
                int tmpshop;
                string strinshop;
                strinshop.push_back(t);
                stringstream tt;
                tt << strinshop;
                tt >> tmpshop;

                shopsvec.push_back(tmpshop);
            }
        }

        for(auto cr:cars){
            if(cr->getCarShops() != shopsvec and cr->getCarbrand() == carname){
                cr->setCarShops(shopsvec);
            }
        }
    }

}

void System::updateBrands() {
    ifstream input(file);
    json j;
    input >> j;

    for(auto shop:j["Shops"]){
        int shopid;
        string spid = shop["ShopId"];
        stringstream ss;
        ss << spid;
        ss >> shopid;

        for(auto k: shops){

            string vecbrands;
            for (int i = 0; i < k->getShopBrands().size(); ++i) {
                if(i == k->getShopBrands().size()-1){
                    vecbrands += k->getShopBrands()[i];
                }else{
                    vecbrands += k->getShopBrands()[i] + "-";
                }
            }

            if(shop["ShopBrands"] != vecbrands and k->getShopId() == shopid){
                string tmp;
                vector<string> vect;
                string nwbrands = shop["ShopBrands"];
                for (int i = 0; i < nwbrands.size(); ++i) {
                    if(i == nwbrands.size()-1){
                        tmp += nwbrands[i];
                        vect.push_back(tmp);
                        tmp ="";
                    }
                    if(nwbrands[i] != '-'){
                        tmp += nwbrands[i];
                    }
                    else{
                        vect.push_back(tmp);
                        tmp = "";
                    }
                }

                k->setShopBrands(vect);

            }
        }
    }
}
