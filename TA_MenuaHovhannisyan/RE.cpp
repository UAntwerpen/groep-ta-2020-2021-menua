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

tuple<vector<Node *>, vector<Edge *>> RE::intersecFunc(const vector<string> &p_input) {
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

map<vector<string>,bool> RE::splitUnion(const string &p_input) {
    string re;
    vector<string> tmpvec;
    stack<char> bracketstack;
    int uni = 0;
    bool found = false;

    for(auto i: p_input){
        if(i == '+'){
            if(bracketstack.empty()){
                uni += 1;
                tmpvec.push_back(re);
                re = i;
                tmpvec.push_back(re);
                re = "";
            }
            else{
                re += i;
            }

        }
        else if(i == '('){
            bracketstack.push(i);
            re += i;
        }
        else if(i==')'){
            if(!bracketstack.empty()){
                bracketstack.pop();
                re += i;
            }
            else{
                re += i;
            }

        }
        else{
            re +=i;
        }

    }
    tmpvec.push_back(re);

    for(auto k : tmpvec){
        cout << k << endl;
    }

    if(uni>=1){
        found = true;
    }

    map<vector<string>, bool> result;

    result.insert(pair<vector<string>, bool>(tmpvec, found));

    return result;
}

map<vector<string>, bool> RE::splitIntersec(const string &p_input) {
    string re;
    bool star = false;
    vector<string> tmpvec;
    stack<char> bracketstack;
    bool found = false;

    for (int i = 0; i < p_input.size(); ++i) {
        if(star){
            star = false;
            continue;
        }
        if(p_input.at(i) == '('){

            bracketstack.push(p_input.at(i));
            re += p_input.at(i);
        }
        else if(p_input.at(i) ==')'){
            bracketstack.pop();
            re += p_input.at(i);
            if(bracketstack.empty()){
                if(i != p_input.size()-1){
                    if(p_input.at(i+1) == '*'){
                        star = true;
                        re += p_input.at(i+1);
                    }
                }
                tmpvec.push_back(re);
                re = "";
            }
        }
        else{
            if(!bracketstack.empty()){
                re += p_input.at(i);
            }
            else{
                re += p_input.at(i);
                tmpvec.push_back(re);
            }
        }
    }
    if(tmpvec.size()>1){
        found = true;
    }

    for(auto k : tmpvec){
        cout << k << endl;
    }

    map<vector<string>, bool> result;

    result.insert(pair<vector<string>, bool>(tmpvec, found));

    return result;
}

map<vector<string>, bool> RE::splitClosure(const string &p_input) {
    string re;
    vector<string> tmpvec;
    bool found = false;

    for (auto i : p_input) {
        if(i == '*'){
            found = true;
            break;
        }
        else{
            re += i;
        }

    }

    tmpvec.push_back(re);
    map<vector<string>, bool> result;
    result.insert(pair<vector<string>, bool>(tmpvec, found));

    cout << re << endl;

    return result;
}

map<vector<string>, bool> RE::splitBrackets(const string &p_input) {
    string re;
    vector<string> tmpvec;
    stack<char> bracketstack;
    bool found = false;

    for (auto i: p_input) {
        if(i == '('){
            if(bracketstack.empty()){
                bracketstack.push(i);
            }
            else{
                bracketstack.push(i);
                re += i;
            }
        }
        else if(i == ')'){
            if(!bracketstack.empty()){
                bracketstack.pop();
                if(bracketstack.empty()){
                    found = true;
                }
                else{
                    re += i;
                }
            }
        }
        else{
            re += i;
        }
    }
    tmpvec.push_back(re);

    for(auto k : tmpvec){
        cout << k << endl;
    }

    map<vector<string>, bool> result;
    result.insert(pair<vector<string>, bool>(tmpvec, found));

    return result;
}

tuple<vector<Node *>, vector<Edge *>> RE::toENFA(const string &p_input) {
    if(foundFunc(splitUnion(p_input))){
         edges = get<1>(unionFunc(inputFunc(splitUnion(p_input))));
         for(auto i: edges){
             if(i->symbol.size()>1){

                 return toENFA(i->symbol);
             }
         }

    }


    return tuple<vector<Node *>, vector<Edge *>>();
}

bool RE::foundFunc(const map<vector<string>, bool> &p_input) {
    bool found = false;
    for (auto item: p_input){
        found = item.second;
    }
    return found;
}

vector<string> RE::inputFunc(const map<vector<string>, bool> &p_input) {
    vector<string> result;
    for (auto item: p_input){
        result = item.first;
    }
    return result;
}

