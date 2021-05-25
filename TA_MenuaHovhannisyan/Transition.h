//
// Created by Menua on 28/02/2021.
//

#include <string>

#ifndef DFA_C___TRANSITIONS_H
#define DFA_C___TRANSITIONS_H

using namespace std;

class Transition {
public:
    string from;
    string to;
    string val;
    Transition(const string& n_from, const string& n_to, const string& n_val){
        from = n_from;
        to = n_to;
        val = n_val;
    }
};


#endif //DFA_C___TRANSITIONS_H
