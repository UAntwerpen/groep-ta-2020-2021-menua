//
// Created by Menua on 10/03/2021.
//

#include "NFA.h"


bool NFA::checkalphabet(const string &input) {
    int bf = 0;
    int size = input.size();
    for (auto & i : input) {
        string s;
        s += i;
        for (auto & k : get_alphabet()){
            if (s == k){
                bf += 1;
            }
        }
    }
    if(bf == size){
        return true;
    }
    return false;
}

NFA::NFA(const string &inp) {//We construeren een NFA vanuit een bestand
    // inlezen uit file
    ifstream input(inp);
    json j;
    input >> j;
    _input = inp;
    set_alphabet(j["alphabet"]);
    //states
    for(auto & i: j["states"]){
        State* state = new State;
        state->set_finalstate(i["accepting"]);
        state->set_title(i["name"]);
        state->set_startstate(i["starting"]);
        state_map.insert(pair<string,int>(state->get_title(), states.size()));
        states.push_back(state);

        if(state->get_startstate()){
            startstate = state;
        }

    }
    //Transisitions
    for (auto & k : j["transitions"]){
        Transition* trns = new Transition(k["from"], k["to"], k["input"]);
        trans.push_back(trns);
    }
}

void NFA::print() { // We printer de structuur van onze NFA in XML vorm
    string type = get_type();
    vector<json>_states;
    vector<json>_transitions;
    for(auto & i : states){
        json s;
        s["name"] = i->get_title();
        s["starting"] = i->get_startstate();
        s["accepting"] = i->get_finalstate();
        _states.push_back(s);
    }

    for (auto& k: trans){
        json tn;
        tn["from"] = k->from;
        tn["to"] = k->to;
        tn["input"] = k->val;
        _transitions.push_back(tn);
    }

    vector<string> _alphabet = get_alphabet();
    json j;
    j["type"] = type;
    j["alphabet"] = _alphabet;
    j["states"] = _states;
    j["transitions"] = _transitions;
    cout << setw(4) << j << endl;
}

int NFA::distance(const string &titel) {
    for (int i = 0; i < states.size(); ++i) {
        if(states.at(i)->get_title()==titel){
            return i;
        }
    }
    return 0;
}

void NFA::set_alphabet(const vector<string> &new_alphabet) {
    this->alphabet = new_alphabet;
}

vector<string> NFA::get_alphabet() {
    return this->alphabet;
}

bool NFA::accepts(const string &input) {
    if(checkalphabet(input)){

        for (auto & i: states) {
            if(i->get_startstate()){
                ptr = i;
                break;
            }
        }

        for (char i : input) {
            string tmp;
            bool found = false;
            tmp.push_back(i);
            for(auto & k : trans){
                if(k->from == ptr->get_title() and k->val == tmp){
                    State* nxt = states[state_map.at(k->to)];
                    ptr = nxt;
                    found = true;
                    break;
                }
            }

            if(!found){
                return false;
            }

        }

        if (ptr->get_finalstate()){
            return true;
        }
    }


    else{
        cout << "[FAILED] - Input komt niet overeen met alphabet." << endl;
    }
    return false;
}

DFA NFA::toDFA() { //NFA omzetten in DFA
    ssc("{" + startstate->get_title() +"}"); // we verwijzen naar onze recursieve functie SSC

    //set_start & set final
    for(auto i: states_dfa){
        if(i->get_title() == "{" + startstate->get_title() +"}"){
            i->set_startstate(true);
        }
        vector<string>v_tmp = vectNormalize(i->get_title());
        for(auto j: v_tmp){
            State* state = states.at(state_map.at(j));
            if(state->get_finalstate()){
                i->set_finalstate(true);
            }
        }
    }

    DFA dfa(states_dfa,transitions_dfa,alphabet);
    return dfa;
}

void NFA::ssc(const string& name) {//Onze mechanisme om NFA om te zetten in DFA
    State *state = new State;
    state->set_title(name);
    states_dfa.push_back(state);
    vector<string>items = vectNormalize(name);
    vector<pair<string, string>>transitionToState;

    //alphabet afgaan en nadien de items in de set
    for(auto a : alphabet){
        vector<string>strstate;
        for(auto it: items){
            for(auto k: trans){
                if(k->from == it and k->val == a){
                    strstate.push_back(k->to);
                }
            }
        }
        //sorteert vector
        sort(strstate.begin(), strstate.end());
        //verwijderd duplicaten
        strstate.erase(unique( strstate.begin(), strstate.end() ), strstate.end());
        transitionToState.push_back(pair<string, string>(a,vectToSet(strstate)));
    }

    for(auto trns : transitionToState){ // we loopen over transitie en maken de transitie aan
        Transition *trans = new Transition(name, trns.second, trns.first);
        transitions_dfa.push_back(trans);
    }

    //we kijken na of de state al bestaat zo niet, dan voeren we deze functie recursief opnieuw
    for(auto i: transitionToState){
        if(!existState(i.second)){
            ssc(i.second);
        }
    }
}

vector<string> NFA::vectNormalize(const string& set) { // van {"A,B,C"} -> ["A","B","C"]
    string tmp;
    vector<string>rtn;
    for(auto c : set){
        if(c == '{' || c == ',' || c == '}'){
            if(!tmp.empty()){
                rtn.push_back(tmp);
                tmp = "";
            }
            continue;
        }
        tmp += c;
    }
    return rtn;
}

string NFA::vectToSet(const vector<string> &input) {// van ["A","B","C"] -> {"A,B,C"}
    string rtn = "{";
    for(const auto& i : input){
        if(rtn == "{"){
            rtn+= i;
        }
        else{
            rtn+= "," + i;
        }
    }
    rtn += "}";
    return rtn;
}

bool NFA::existState(const string &input) {//kijken of de state bestaat of niet
    for(auto i: states_dfa){
        if(i->get_title() == input){
            return true;
        }
    }
    return false;
}

