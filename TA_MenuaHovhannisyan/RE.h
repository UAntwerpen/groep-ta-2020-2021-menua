//
// Created by Menua on 26/05/2021.
//
#include <string>
#include <iostream>
#include "NFA.h"
#include "State.h"
#include "Transition.h"
#include "Node.h"
#include "Edge.h"
using namespace std;


#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_RE_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_RE_H


class RE {
private:
    string regex;

public:
    RE(const string &regex);
    NFA toENFA();
    void setRegex(const string &p_regex);
    string getRegex();
    vector<string> splitRegex();

    tuple<vector<Node*>, vector<Edge*>> unionFunc(const vector<string>& p_inputs);
    tuple<vector<Node*>, vector<Edge*>> intersecFunc(const string& p_input);
    tuple<vector<Node *>, vector<Edge *>> closureFunc(const string& p_input);




};


#endif //TAPROJECT2021_MENUAHOVHANNISYAN_RE_H
