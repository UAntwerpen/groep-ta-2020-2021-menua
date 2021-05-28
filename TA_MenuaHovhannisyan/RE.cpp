//
// Created by Menua on 26/05/2021.
//

#include "RE.h"

RE::RE(const string &p_regex) {
    setRegex(p_regex);
}

void RE::setRegex(const string &p_regex) {
    regex = p_regex;
}

string RE::getRegex() {
    return regex;
}

NFA RE::toNFA() {
    vector<State*> states;
    vector<Transition*> transitions;
    vector<string> alphabet;


    




    NFA nfa(states,transitions,alphabet);
    nfa.print();
    return nfa;
}

vector<string> RE::splitRegex() {
    string re;
    vector<string> tmpvec;
    bool bracket = false;
    for(auto i: regex){
        if(i == '('){
            bracket = true;
            re += i;
        }
        else if(i == '+'){
            if(!bracket){
                tmpvec.push_back(re);
                re = i;
                tmpvec.push_back(re);
                re = "";
            }
            else{
                re += i;
            }
        }
        else if(i == ')'){
            bracket = false;
            re += i;
        }
        else {
            re += i;
        }
    }
    tmpvec.push_back(re);

    for(auto k: tmpvec){
        cout << k << endl;
        cout << "---" << endl;
    }

    return tmpvec;
}
