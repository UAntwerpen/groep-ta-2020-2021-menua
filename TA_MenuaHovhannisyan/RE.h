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
#include <stack>
using namespace std;


#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_RE_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_RE_H


class RE {
private:
    string regex;
    vector<Node*> nodes;
    vector<Edge*> edges;

public:
    RE(const string &regex);
    void setRegex(const string &p_regex);
    string getRegex();

    tuple<vector<Node*>, vector<Edge*>> toENFA(const string &p_input);

    bool foundFunc(const map<vector<string>, bool> &p_input);

    vector<string> inputFunc(const map<vector<string>, bool> &p_input);

    map<vector<string>, bool> splitUnion(const string &p_input);
    map<vector<string>, bool> splitIntersec(const string &p_input);
    map<vector<string>, bool> splitClosure(const string &p_input);
    map<vector<string>, bool> splitBrackets(const string &p_input);

    tuple<vector<Node*>, vector<Edge*>> unionFunc(const vector<string>& p_inputs);
    tuple<vector<Node*>, vector<Edge*>> intersecFunc(const vector<string>& p_input);
    tuple<vector<Node *>, vector<Edge *>> closureFunc(const string& p_input);

};


#endif //TAPROJECT2021_MENUAHOVHANNISYAN_RE_H
