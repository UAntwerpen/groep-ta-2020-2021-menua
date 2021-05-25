//
// Created by Menua on 28/02/2021.
//


#include <string>
#include <fstream>
#include <tuple>
#include "json.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

#ifndef DFA_C___STATE_H
#define DFA_C___STATE_H
//Onze klasse State
class State{
//Enkele variabelen die worden meegegeven met de klassen
private:
    string state_title;
    bool final_state = false;
    bool start_state = false;
//We maken setters en getters voor de variabelen
public:
    void set_title(string new_title);

    string get_title();

    void set_finalstate(bool value);

    bool get_finalstate() const;

    void set_startstate(bool value);

    bool get_startstate() const;

};
#endif //DFA_C___STATE_H
