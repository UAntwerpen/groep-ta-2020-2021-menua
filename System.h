//
// Created by Menua on 26/05/2021.
//

#include <string>
#include "json.hpp"
#include <iostream>
#include <fstream>


using namespace std;
using namespace nlohmann;

#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_SYSTEM_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_SYSTEM_H

class gui;

class System {
private:
    string file;
public:
    System(const string &file_name);

    int start(int p_argc, char *p_argv[]);
};

#include "Interface/gui.h"
#endif //TAPROJECT2021_MENUAHOVHANNISYAN_SYSTEM_H
