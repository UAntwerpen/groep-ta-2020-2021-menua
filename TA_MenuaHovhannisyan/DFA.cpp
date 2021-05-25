//
// Created by Menua on 28/02/2021.
//

#include "DFA.h"

DFA::DFA(const string &inp) { //We construeren een DFA vanuit een bestand
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

void DFA::print() { //We printen de structuur van een dfa in een vrom  van XML
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

int DFA::distance(const string &titel) { // we zoeken naar de index van de naam van een state
    for (int i = 0; i < states.size(); ++i) {
        if(states.at(i)->get_title()==titel){
            return i;
        }
    }
    return 0;
}

void DFA::set_alphabet(const vector<string> &new_alphabet) {
    this->alphabet = new_alphabet;
}

bool DFA::accepts(const string &input) {//checken of de dfa de taal accepteert
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

vector<string> DFA::get_alphabet() {
    return this->alphabet;
}

bool DFA::checkalphabet(const string& input) {
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

DFA::DFA(const DFA& dfa1, const DFA& dfa2, bool finalstates) {
    //we stellen alphabet
    for(auto i: dfa1.alphabet){
        alphabet.push_back(i);
    }

    //we zetten de states en transisties van de dfas in vectors
    states_dfa1 = dfa1.states;
    states_dfa2 = dfa2.states;
    transitions_dfa1 = dfa1.trans;
    transitions_dfa2 = dfa2.trans;

    //we passen de recursieve functie om de states en de transities te maken
    product_automaton(searchstartstate(dfa1,dfa2));

    //we kijken na of we een doorsnede moeten pakken of een unie
    if(finalstates){
        doorsneden();
    }
    else{
        unie();
    }

    //we construeren de dfa hier
    DFA dfa(states,trans, alphabet);
}

void DFA::product_automaton(const string &name) {//(q0,r0) //Onze mechanisme om dfa1 en dfa2 samen te zetten
    State *state = new State;
    state->set_title(name);
    states.push_back(state);

    vector<string>items = vectNormalize(name);//["q0","r0"]
    vector<pair<string, string>>transitionToState;
    bool dfa1 = true;//we kijken eerst naar de eerste dfa dan de 2de

    //alphabet afgaan en nadien de items in de set
    for(auto a: alphabet){//0
        vector<string> strstate;
        for(auto it: items){//q0
            if(dfa1){
                dfa1 = false;
                for(auto tdf1: transitions_dfa1){
                    if(tdf1->from == it and tdf1->val == a){
                        strstate.push_back(tdf1->to);//q0

                    }
                }
            }
            else{
                dfa1 = true;
                for(auto tdf2: transitions_dfa2){
                    if(tdf2->from == it and tdf2->val == a){
                        strstate.push_back(tdf2->to);//r1
                    }
                }
            }
        }
        transitionToState.push_back(pair<string, string>(a,vectToSet(strstate)));
    }

    for(auto trns : transitionToState){ // we loopen over transitie en maken de transitie aan
        Transition *trn = new Transition(name, trns.second, trns.first);
        trans.push_back(trn);
    }

    //we kijken na of de state al bestaat zo niet, dan voeren we deze functie recursief opnieuw
    for(auto i: transitionToState){
        if(!existState(i.second)){
            product_automaton(i.second);
        }
    }


}

vector<string> DFA::vectNormalize(const string& set) { // van {"A,B,C"} -> ["A","B","C"]
    string tmp;
    vector<string>rtn;
    for(auto c : set){
        if(c == '(' || c == ',' || c == ')'){
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

string DFA::vectToSet(const vector<string> &input) {// van ["A","B","C"] -> {"A,B,C"}
    string rtn = "(";
    for(const auto& i : input){
        if(rtn == "("){
            rtn+= i;
        }
        else{
            rtn+= "," + i;
        }
    }
    rtn += ")";
    return rtn;
}

bool DFA::existState(const string &input) {//kijken of de state bestaat of niet
    for(auto i: states){
        if(i->get_title() == input){
            return true;
        }
    }
    return false;
}

void DFA::doorsneden() {//doorsnede berekenen
    for(auto st: states){

        vector<string> tmp_vect = vectNormalize(st->get_title());
        bool dfa1 = true;
        int final = 0;
        int start = 0;
        for(auto items: tmp_vect){//loopen over items van de set dus bv (0,0) -> 0 state
            if(dfa1){
                dfa1 = false;
                for(auto df1: states_dfa1){//we kijken na of het in de states_dfa1
                    if(items == df1->get_title()){
                        if(df1->get_finalstate()){
                            final += 1;
                        }
                        if(df1->get_startstate()){
                            start +=1;
                        }
                    }
                }
            }
            else{
                dfa1 = true;
                for(auto df2: states_dfa2){//we kijken na of het in de states_dfa2
                    if(items == df2->get_title()){
                        if(df2->get_finalstate()){
                            final += 1;
                        }
                        if(df2->get_startstate()){
                            start +=1;
                        }
                    }
                }
            }

        }
        if(final == 2){//als final 2 is dan zijn beide states finalstates true
            st->set_finalstate(true);
        }
        else{
            st->set_finalstate(false);
        }
        if(start == 2){//als start 2 is dan zijn beide states startstates true
            st->set_startstate(true);
        }
        else{
            st->set_startstate(false);
        }
    }

}

void DFA::unie() {//unie berekenen
    for(auto st: states){

        vector<string> tmp_vect = vectNormalize(st->get_title());
        bool dfa1 = true;
        bool final = false;
        int start = 0;
        for(auto items: tmp_vect){//over de items loopen van in de vector
            if(dfa1){
                dfa1 = false;
                for(auto df1: states_dfa1){//states dfa1
                    if(items == df1->get_title()){
                        if(df1->get_finalstate()){
                            if(!final){
                                final = true;
                            }
                        }
                        if(df1->get_startstate()){
                            start +=1;
                        }
                    }
                }
            }
            else{
                dfa1 = true;
                for(auto df2: states_dfa2){ //states dfa2
                    if(items == df2->get_title()){
                        if(df2->get_finalstate()){
                            if(!final){
                                final = true;
                            }
                        }
                        if(df2->get_startstate()){
                            start +=1;
                        }
                    }
                }
            }

        }
        if(final){//we checken of de 2 dfa een finalstate zijn
            st->set_finalstate(true);
        }
        else{
            st->set_finalstate(false);
        }
        if(start == 2){//we kijken of de 2 dfa startstates zijn
            st->set_startstate(true);
        }
        else{
            st->set_startstate(false);
        }
    }
}

string DFA::searchstartstate(DFA dfa1, DFA dfa2) {
    string tmp;
    State* start1;//dfa1
    State* start2;//dfa2

    for(auto df1: dfa1.states){//loopen over dfa1 states
        if(df1->get_startstate()){
            start1 = df1;
        }
    }
    for(auto df2: dfa2.states){//loopen over dfa2 states
        if(df2->get_startstate()){
            start2 = df2;
        }
    }

    tmp +=  "(" + start1->get_title() + "," + start2->get_title() + ")";
    return tmp;
}


