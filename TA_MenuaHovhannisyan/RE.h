//
// Created by Menua on 26/05/2021.
//
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
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
public:
    pair<vector<Node *>, vector<Edge *>> toENFA(const string &p_input);

    bool foundFunc(const map<vector<string>, bool> &p_input);

    vector<string> inputFunc(const map<vector<string>, bool> &p_input);

    map<vector<string>, bool> splitUnion(const string &p_input);
    map<vector<string>, bool> splitIntersec(const string &p_input);
    map<vector<string>, bool> splitClosure(const string &p_input);
    map<vector<string>, bool> splitBrackets(const string &p_input);

    tuple<vector<Node*>, vector<Edge*>> unionFunc(const vector<string>& p_inputs);
    tuple<vector<Node*>, vector<Edge*>> intersecFunc(const vector<string>& p_input);
    tuple<vector<Node *>, vector<Edge *>> closureFunc(const string& p_input);
    NFA ENFAtoNFA(vector<Node*>p_nodes, const vector<Edge*>&p_edges);

    void replaceIncoming(Node *p_node,Edge* p_edge);
    void replaceOutgoing(Node *p_node,Edge* p_edge);

    State* setStartstate(int index);
    State* setFinalstate(int index);

    vector<string> eclosure(State* p_state,const vector<Transition*>& p_transitions);

    pair<pair<vector<Transition*>,vector<string>>,vector<State*>> enfatonfamechanic(vector<string> p_alphabet,vector<State*> p_states, const vector<Transition*> p_transitions);

    void checkfinalstate(vector<State*> &p_states, State* p_state, vector<Transition*> p_transitions);

    Transition* getTransitionwString(const string& state,const string& p_input, const vector<Transition*>& p_transitions);
    State* getStatewString(const string& p_state, const vector<State*>& p_states);

    int find(Node* p_node, vector<Node*>p_nodes);

    void testPrint(string p_inputstring);
    void printvect(vector<string> p_vector);


};


#endif //TAPROJECT2021_MENUAHOVHANNISYAN_RE_H
