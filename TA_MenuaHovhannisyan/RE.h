//
// Created by Menua on 26/05/2021.
//
#include <string>
#include <iostream>
#include "DFA.h"
using namespace std;


#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_RE_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_RE_H


class RE {
private:
    string regex;

public:
    RE(const string &regex);
    DFA toDFA();



};


#endif //TAPROJECT2021_MENUAHOVHANNISYAN_RE_H
