//
// Naam: Hovhannisyan
// Voornaam: Menua
// Studentennummer: 20201918
//
#include <string>
#include <fstream>
#include <tuple>
#include "json.hpp"
#include <iostream>
#include <iomanip>
#include <utility>
#include "State.h"
#include "Transition.h"
using namespace std;

using json = nlohmann::json;
#ifndef DFA_C___DFA_H
#define DFA_C___DFA_H

//Onze klasse DFA
class DFA{
private:

    State* ptr{};
    vector<string>alphabet;

    vector<State*>states;

    State* startstate;

    map<string, int> state_map;
    vector<Transition*> trans;

    vector<State*>states_dfa1;
    vector<State*>states_dfa2;
    vector<Transition*>transitions_dfa1;
    vector<Transition*>transitions_dfa2;


//We maken hier onze DFA aan, Deze kan veranderd worden naar de gewneste DFA
public:

    bool checkalphabet(const string& input);

    explicit DFA(const string& inp);

    explicit DFA(vector<State*> &p_states, vector<Transition*> p_transitions, vector<string> p_alphabet) {
        states = p_states;
        for (int i = 0; i < states.size(); ++i) {
            state_map.insert(pair<string, int>(states[i]->get_title(), i));
        }
        trans = std::move(p_transitions);
        alphabet = std::move(p_alphabet);
    }

    void print();

    int distance(const string& titel);

    void set_alphabet(const vector<string>&new_alphabet);

    static string get_type(){return "DFA";}

    vector<string> get_alphabet();

//De functie accepts return een boolean waarden als ze de DFA de input toelaat, hij zal false weergeven als hij deze niet toelaat
    bool accepts(const string& input);

    explicit DFA(const DFA& dfa1, const DFA& dfa2, bool doruni);

    void product_automaton(const string &name);

    vector<string> vectNormalize(const string &set);

    string vectToSet(const vector<string> &input);

    bool existState(const string &input);

    void doorsneden();

    void unie();

    string searchstartstate(DFA dfa1, DFA dfa2);


};
#endif //DFA_C___DFA_H
