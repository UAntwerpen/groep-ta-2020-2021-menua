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
