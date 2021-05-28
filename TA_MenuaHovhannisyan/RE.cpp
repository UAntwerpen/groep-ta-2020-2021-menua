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

NFA RE::toENFA() {
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

tuple<vector<Node *>, vector<Edge *>> RE::unionFunc(const vector<string>& p_inputs) {
    vector<Node*> nodes;
    vector<Edge*> edges;

    Node* nstart = new Node();

    Node* nfinal = new Node();

    for(auto i: p_inputs){
        if(i != "+") {
            Node *node1 = new Node();
            Node *node2 = new Node();

            Edge *edge1 = new Edge();
            edge1->start = nstart;
            edge1->end = node1;
            edge1->symbol = "^";

            Edge *edge2 = new Edge();
            edge2->start = node1;
            edge2->end = node2;
            edge2->symbol = i;

            Edge *edge3 = new Edge();
            edge3->start = node2;
            edge3->end = nfinal;
            edge3->symbol = "^";

            //edge 1
            nstart->outgoing.push_back(edge1);
            node1->incomming.push_back(edge1);
            edges.push_back(edge1);

            //edge 2
            node1->outgoing.push_back(edge2);
            node2->incomming.push_back(edge2);
            edges.push_back(edge2);

            //edge 3
            node2->outgoing.push_back(edge3);
            nfinal->incomming.push_back(edge3);
            edges.push_back(edge3);

            nodes.push_back(node1);
            nodes.push_back(node2);
        }
        cout << i << endl;

    }

    nodes.push_back(nstart);
    nodes.push_back(nfinal);


    /*for(auto k : nodes){
        cout << "[INCOMMING]" << endl;
        for(auto in: k->incomming){
            cout << "Start: " << in->start << endl;
            cout << "End: " << in->end << endl;
            cout << "Symbol: " << in->symbol << endl;
        }
        cout << "-----------------" << endl;

        cout << "[OUTGOING]" << endl;
        for(auto n: k->outgoing){
            cout << "Start: " << n->start << endl;
            cout << "End: " << n->end << endl;
            cout << "Symbol: " << n->symbol << endl;
        }
        cout << "-----------------" << endl;
    }*/

    tuple<vector<Node *>, vector<Edge *>> result;
    result = make_tuple(nodes,edges);

    return result;
}

tuple<vector<Node *>, vector<Edge *>> RE::intersecFunc(const string &p_input) {
    vector<Node*> nodes;
    vector<Edge*> edges;
    vector<vector<Node*>> epstran;
    vector<Node*> tmpvec;

    for (auto i : p_input) {
        if(nodes.empty()){
            Node* node1 = new Node();
            Node* node2 = new Node();

            Edge* edge = new Edge();
            edge->start = node1;
            edge->end = node2;
            edge->symbol = i;

            node1->outgoing.push_back(edge);
            node2->incomming.push_back(edge);

            nodes.push_back(node1);
            nodes.push_back(node2);

            edges.push_back(edge);
        }
        else{

            Node* node2 = new Node();
            Edge* edge = new Edge();
            edge->start = nodes.back();
            edge->end = node2;
            edge->symbol = i;

            nodes.back()->outgoing.push_back(edge);
            node2->incomming.push_back(edge);

            nodes.push_back(nodes.back());
            nodes.push_back(node2);

            edges.push_back(edge);
        }
    }

    /*for(auto i: edges){
        cout << "Start: " << i->start << endl;
        cout << "End: " << i->end << endl;
        cout << "Symbol: " << i->symbol << endl;
    }*/

    tuple<vector<Node *>, vector<Edge *>> result;
    result = make_tuple(nodes,edges);

    return result;
}

tuple<vector<Node *>, vector<Edge *>> RE::closureFunc(const string &p_input) {
    vector<Node*> nodes;
    vector<Edge*> edges;

    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();

    Edge* edge1 = new Edge();
    edge1->start = node1;
    edge1->end = node2;
    edge1->symbol = "^";

    node1->outgoing.push_back(edge1);
    node2->incomming.push_back(edge1);

    Edge* edge2 = new Edge();
    edge2->start = node2;
    edge2->end = node3;
    edge2->symbol = p_input;

    node2->outgoing.push_back(edge2);
    node3->incomming.push_back(edge2);

    Edge* edge3 = new Edge();
    edge3->start = node3;
    edge3->end = node4;
    edge3->symbol = "^";

    node3->outgoing.push_back(edge3);
    node4->incomming.push_back(edge3);

    Edge* edge4 = new Edge();
    edge4->start = node1;
    edge4->end = node4;
    edge4->symbol = "^";

    node1->outgoing.push_back(edge4);
    node4->incomming.push_back(edge4);

    Edge* edge5 = new Edge();
    edge5->start = node3;
    edge5->end = node2;
    edge5->symbol = "^";

    node3->outgoing.push_back(edge5);
    node2->incomming.push_back(edge5);

    nodes.push_back(node1);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);

    tuple<vector<Node *>, vector<Edge *>> result;
    result = make_tuple(nodes,edges);
    return result;
}

