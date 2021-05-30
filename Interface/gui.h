//
// Created by Menua on 30/05/2021.
//

#include <string>
#include <QApplication>

using namespace std;

#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_GUI_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_GUI_H


class gui {
public:
    string filename;
    int run(int p_argc, char * argv[]);
    gui(const string &file);
};

#include "mainwindow.h"

#endif //TAPROJECT2021_MENUAHOVHANNISYAN_GUI_H
