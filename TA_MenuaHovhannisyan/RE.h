//
// Created by Menua on 26/05/2021.
//
#include <string>
#include <iostream>
#include "NFA.h"
#include "State.h"
#include "Transition.h"
using namespace std;


#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_RE_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_RE_H


class RE {
private:
    string regex;

public:
    RE(const string &regex);
    NFA toNFA();
    void setRegex(const string &p_regex);
    string getRegex();
    vector<string> splitRegex();



};


#endif //TAPROJECT2021_MENUAHOVHANNISYAN_RE_H
