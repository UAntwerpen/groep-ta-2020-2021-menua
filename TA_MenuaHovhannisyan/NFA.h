//
// Created by Menua on 10/03/2021.
//
#include <string>
#include <fstream>
#include <tuple>
#include "json.hpp"
#include <iostream>
#include <iomanip>
#include "State.h"
#include "Transition.h"
#include "DFA.h"

using namespace std;
using json = nlohmann::json;
#ifndef DFA_C___NFA_H
#define DFA_C___NFA_H


class NFA {
private:

    State* ptr{};
    vector<string>alphabet;

    vector<State*>states;

    State* startstate;

    map<string, int> state_map;
    vector<Transition*> trans;

    vector<State*>states_dfa;
    vector<Transition*>transitions_dfa;

public:
    bool checkalphabet(const string& input);

    explicit NFA(const string& inp);

    explicit NFA(vector<State*> &p_states, vector<Transition*> &p_transitions, vector<string> &p_alphabet);

    void print();

    int distance(const string& titel);

    void set_alphabet(const vector<string>&new_alphabet);

    static string get_type(){return "NFA";}

    vector<string> get_alphabet();

    bool accepts(const string& input);

    DFA toDFA();

    void ssc(const string& name);

    vector<string> vectNormalize(const string& set);

    string vectToSet(const vector<string>&input);

    bool existState(const string &input);

};


#endif //DFA_C___NFA_H
