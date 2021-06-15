//
// Created by Menua on 26/05/2021.
//

#include "RE.h"

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
            node1->incoming.push_back(edge1);
            edges.push_back(edge1);

            //edge 2
            node1->outgoing.push_back(edge2);
            node2->incoming.push_back(edge2);
            edges.push_back(edge2);

            //edge 3
            node2->outgoing.push_back(edge3);
            nfinal->incoming.push_back(edge3);
            edges.push_back(edge3);

            nodes.push_back(node1);
            nodes.push_back(node2);
        }
        /* << i << endl;*/

    }

    nodes.push_back(nstart);
    nodes.push_back(nfinal);


    /*for(auto k : nodes){
        cout << "[INCOMMING]" << endl;
        for(auto in: k->incoming){
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
    Node* start;

    for (auto i : p_input) {
        if(nodes.empty()){
            Node* node1 = new Node();
            Node* node2 = new Node();

            Edge* edge = new Edge();
            edge->start = node1;
            edge->end = node2;
            edge->symbol = i;

            node1->outgoing.push_back(edge);
            node2->incoming.push_back(edge);

            start = node1;
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
            node2->incoming.push_back(edge);

            nodes.push_back(nodes.back());
            nodes.push_back(start);
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
    node2->incoming.push_back(edge1);

    Edge* edge2 = new Edge();
    edge2->start = node2;
    edge2->end = node3;
    edge2->symbol = p_input;

    node2->outgoing.push_back(edge2);
    node3->incoming.push_back(edge2);

    Edge* edge3 = new Edge();
    edge3->start = node3;
    edge3->end = node4;
    edge3->symbol = "^";

    node3->outgoing.push_back(edge3);
    node4->incoming.push_back(edge3);

    Edge* edge4 = new Edge();
    edge4->start = node1;
    edge4->end = node4;
    edge4->symbol = "^";

    node1->outgoing.push_back(edge4);
    node4->incoming.push_back(edge4);

    Edge* edge5 = new Edge();
    edge5->start = node3;
    edge5->end = node2;
    edge5->symbol = "^";

    node3->outgoing.push_back(edge5);
    node2->incoming.push_back(edge5);

    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node1);
    nodes.push_back(node4);

    edges.push_back(edge1);
    edges.push_back(edge2);
    edges.push_back(edge3);
    edges.push_back(edge4);
    edges.push_back(edge5);

    tuple<vector<Node *>, vector<Edge *>> result;
    result = make_tuple(nodes,edges);
    return result;
}

map<vector<string>,bool> RE::splitUnion(const string &p_input){
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

    /*for(auto k : tmpvec){
        cout << k << endl;
    }*/

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
                if(p_input.at(i) =='*'){
                    tmpvec.back() += p_input.at(i);
                }else{
                    re += p_input.at(i);
                    tmpvec.push_back(re);
                    re = "";
                }
            }
        }
    }
    if(tmpvec.size()>1){
        found = true;
    }

    /*for(auto k : tmpvec){
        cout << k << endl;
    }*/

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

    /*cout << re << endl;*/

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

    /*for(auto k : tmpvec){
        cout << k << endl;
    }*/

    map<vector<string>, bool> result;
    result.insert(pair<vector<string>, bool>(tmpvec, found));

    return result;
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

pair<vector<Node *>, vector<Edge *>> RE::toENFA(const string& p_inputstring) {
    vector<int> edgesToRemove;
    vector<string> input;
    tuple<vector<Node*>,vector<Edge*>> tuple;
    vector<Node*> p_nodes;
    vector<Edge*> p_edges;

    if(foundFunc(splitUnion(p_inputstring))){
        input = inputFunc(splitUnion(p_inputstring));
        tuple = unionFunc(input);
        p_nodes = get<0>(tuple);
        p_edges = get<1>(tuple);

    }else if(foundFunc(splitIntersec(p_inputstring))){
        input = inputFunc(splitIntersec(p_inputstring));
        tuple = intersecFunc(input);
        p_nodes = get<0>(tuple);
        p_edges = get<1>(tuple);

    }else if(foundFunc(splitClosure(p_inputstring))){
        input = inputFunc(splitClosure(p_inputstring));
        string tmp;
        for(auto k: input){
            tmp += k;
        }
        tuple = closureFunc(tmp);
        p_nodes = get<0>(tuple);
        p_edges = get<1>(tuple);

    }else if(foundFunc(splitBrackets(p_inputstring))){
        input = inputFunc(splitBrackets(p_inputstring));
        string tmp;
        for(auto k: input){
            tmp += k;
        }
        return toENFA(tmp);
    }

    for (int i = 0; i < p_edges.size(); ++i) {
        Edge* edge = p_edges[i];
        if (edge->symbol.size()>1){
            vector<Node*> new_nodes;
            vector<Edge*> new_edges;

            pair<vector<Node*>,vector<Edge*>> ndedg;
            ndedg = toENFA(edge->symbol);
            new_nodes = ndedg.first;
            new_edges = ndedg.second;
            Node* start = p_nodes[p_nodes.size()-2];
            Node* final = p_nodes[p_nodes.size()-1];

            p_nodes.erase(p_nodes.begin()+p_nodes.size()-2);
            p_nodes.erase(p_nodes.begin()+p_nodes.size()-1);

            for(auto nd: new_nodes){
                p_nodes.push_back(nd);
            }

            p_nodes.push_back(start);
            p_nodes.push_back(final);

            for(auto ed: new_edges){
                p_edges.push_back(ed);
            }

            replaceIncoming(new_nodes[new_nodes.size()-2], edge);
            replaceOutgoing(new_nodes[new_nodes.size()-1], edge);

            auto endnd = p_nodes.end();
            for(auto it = p_nodes.begin(); it != endnd; ++it){
                endnd = remove(it + 1, endnd, *it);
            }
            p_nodes.erase(endnd,p_nodes.end());


            int indexst = find(edge->start,p_nodes);
            delete p_nodes[indexst];
            p_nodes.erase(p_nodes.begin() + indexst);

            int indexen = find(edge->end,p_nodes);
            delete p_nodes[indexen];
            p_nodes.erase(p_nodes.begin() + indexen);

            edgesToRemove.push_back(i);

        }
    }

    for(auto ed: edgesToRemove){
        p_edges.erase(p_edges.begin()+ed);
    }

    return pair<vector<Node*>, vector<Edge*>>(p_nodes,p_edges);
}

void RE::replaceIncoming(Node *p_node, Edge* p_edge) {
    for(auto st:p_edge->start->incoming){
        p_node->incoming.push_back(st);
        st->end = p_node;
    }
    p_edge->start->incoming.clear();
}

void RE::replaceOutgoing(Node *p_node, Edge *p_edge) {
    for(auto st:p_edge->end->outgoing){
        p_node->outgoing.push_back(st);
        st->start = p_node;
    }
    p_edge->end->outgoing.clear();

}

NFA RE::ENFAtoNFA(vector<Node *> p_nodes, const vector<Edge *>& p_edges) {
    vector<State*> states;
    vector<Transition*> transitions;
    vector<string> alphabet;
    vector<pair<Node*,State*>> stnd;

    //Making states
    for (int i = 0; i < p_nodes.size(); ++i) {
        if(p_nodes[i]->incoming.empty()){
            State* state1 = setStartstate(i);
            states.push_back(state1);
            stnd.push_back(pair<Node*,State*>(p_nodes[i],state1));
        }
        else if(p_nodes[i]->outgoing.empty()){
            State* state1 = setFinalstate(i);
            states.push_back(state1);
            stnd.push_back(pair<Node*,State*>(p_nodes[i],state1));
        }
        else{

            State* state1 = new State;
            state1->set_startstate(false);
            state1->set_finalstate(false);
            stringstream ss;
            ss<<i;
            state1->set_title("Q"+ ss.str());
            states.push_back(state1);
            stnd.push_back(pair<Node*,State*>(p_nodes[i],state1));
        }
    }

    //Making transitions
    for (auto & p_edge : p_edges) {
        string start;
        string end;
        string symbol = p_edge->symbol;
        for (auto & i : stnd) {
            if(p_edge->start == i.first){
                start = i.second->get_title();
            }
            if(p_edge->end == i.first){
                end = i.second->get_title();
            }
        }
        Transition* tran = new Transition(start,end,symbol);
        transitions.push_back(tran);
    }

    //Making alphabet
    for (auto & p_edge : p_edges) {
        alphabet.push_back(p_edge->symbol);
    }
    auto end = alphabet.end();

    for(auto it = alphabet.begin(); it != end; ++it){
        end = remove(it + 1, end, *it);
    }

    alphabet.erase(end,alphabet.end());



    //ENFA omzetten in NFA

/*
    //cout alphabet
    cout << "[ALPHABET]" << endl;
    for (int i = 0; i < alphabet.size(); ++i) {
        cout << alphabet[i] << endl;
    }
    cout << "------------------" << endl;

    cout << "[States]" << endl;
    for (int i = 0; i < states.size(); ++i) {
        cout << states[i]->get_title() << endl;
    }
    cout << "------------------" << endl;

    cout << "[Transitions]" << endl;
    for (int i = 0; i < transitions.size(); ++i) {
        cout << "From: " << transitions[i]->from << endl;
        cout << "To: " << transitions[i]->to << endl;
        cout << "Value: " << transitions[i]->val << endl;
    }
    cout << "------------------" << endl;
*/

    vector<Transition*> tr = enfatonfamechanic(alphabet,states,transitions).first.first;
    vector<string> alpha = enfatonfamechanic(alphabet,states,transitions).first.second;
    vector<State*> stats = enfatonfamechanic(alphabet,states,transitions).second;

    NFA nfa(stats,tr,alpha);
    return nfa;
}

State* RE::setStartstate(int index) {
    stringstream ss;
    ss<<index;
    State* state1 = new State;
    state1->set_startstate(true);
    state1->set_finalstate(false);
    state1->set_title("Q"+ss.str());
    return state1;
}

State* RE::setFinalstate(int index) {
    stringstream ss;
    ss<<index;
    State* state1 = new State;
    state1->set_startstate(false);
    state1->set_finalstate(true);
    state1->set_title("Q"+ss.str());
    return state1;
}

vector<string> RE::eclosure(State* p_state, const vector<Transition *>& p_transitions) {
    vector<string> eclosures;

    eclosures.push_back(p_state->get_title());
    for (auto & p_transition : p_transitions) {
        if(p_transition->from == p_state->get_title()){
            if(p_transition->val == "^"){
                eclosures.push_back(p_transition->to);
            }
        }
    }

    auto end = eclosures.end();
    for(auto it = eclosures.begin(); it != end; ++it){
        end = remove(it + 1, end, *it);
    }
    eclosures.erase(end,eclosures.end());

    /*for(auto e: eclosures){
        cout << e << endl;
    }*/

    return eclosures;
}

pair<pair<vector<Transition*>,vector<string>>,vector<State*>> RE::enfatonfamechanic(vector<string> p_alphabet, vector<State *> p_states, const vector<Transition *> p_transitions) {
    vector<Transition*> transitions;
    //Epsilon verwijderen uit de alphabet


    int alphindex;
    bool fd = false;
    for (int i = 0; i <p_alphabet.size() ; ++i) {
        if(p_alphabet[i] == "^"){
            alphindex = i;
            fd = true;
        }
    }
    if(fd) {
        p_alphabet.erase(p_alphabet.begin() + alphindex);
    }

    for (int i = 0; i < p_states.size(); ++i) {
        State * state = p_states[i];
            for (auto a: p_alphabet) {

                vector<string> tmp = eclosure(state, p_transitions);
                vector<string> tmp2;

                for (auto eclos: tmp) {
                    Transition *tran;
                    tran = getTransitionwString(eclos, a, p_transitions);
                    if (tran != nullptr) {
                        tmp2.push_back(tran->to);
                    }

                }
                tmp.clear();

                for (auto tm2:tmp2) {
                    vector<string> closure;
                    closure = eclosure(getStatewString(tm2,p_states), p_transitions);
                    tmp.insert(tmp.end(), closure.begin(), closure.end());
                }

                auto end = tmp.end();
                for (auto it = tmp.begin(); it != end; ++it) {
                    end = remove(it + 1, end, *it);
                }
                tmp.erase(end, tmp.end());

                if(!tmp.empty()) {
                    for(auto trn: tmp){
                        Transition* tran = new Transition(state->get_title(),trn,a);
                        transitions.push_back(tran);
                    }
                }
            }

            //checkfinal
            checkfinalstate(p_states,state,p_transitions);
    }


    pair<vector<Transition*>,vector<string>> pr;
    pr.first = transitions;
    pr.second = p_alphabet;
    pair< pair<vector<Transition*>,vector<string>>,vector<State*>> result;
    result.first = pr;
    vector<State*> states;

    for(auto tr: transitions){
        for(auto st: p_states){
            if(st->get_title() == tr->to or st->get_title() == tr->from){
                states.push_back(st);
            }
        }
    }

    auto end = states.end();
    for (auto it = states.begin(); it != end; ++it) {
        end = remove(it + 1, end, *it);
    }
    states.erase(end, states.end());

    result.second = states;

    return result;
}

Transition *RE::getTransitionwString(const string& state,const string& p_input, const vector<Transition *>& p_transitions) {
    for(auto tran: p_transitions){
        if(tran->from == state and tran->val == p_input){
            return tran;
        }
    }
    return nullptr;
}

State *RE::getStatewString(const string& p_state, const vector<State *>& p_states) {
    for(auto state:p_states){
        if(state->get_title() == p_state){
            return state;
        }
    }
    return nullptr;
}

void RE::checkfinalstate(vector<State*> &p_states, State* p_state, vector<Transition*> p_transitions) {
    vector<string> tmp;
    tmp = eclosure(p_state,p_transitions);

    for(auto state: tmp){
        State* s = getStatewString(state,p_states);
        if(s->get_finalstate()){
            p_state->set_finalstate(true);
        }
    }


}

int RE::find(Node *p_node, vector<Node *> p_nodes) {
    for (int i = 0; i < p_nodes.size(); ++i) {
        if(p_node == p_nodes[i]){
            return i;
        }
    }
    return 0;
}

void RE::testPrint(string p_inputstring) {
    vector<string> input;
    if(foundFunc(splitUnion(p_inputstring))){
        input = inputFunc(splitUnion(p_inputstring));
    }else if(foundFunc(splitIntersec(p_inputstring))){
        input = inputFunc(splitIntersec(p_inputstring));
    }else if(foundFunc(splitClosure(p_inputstring))){
        input = inputFunc(splitClosure(p_inputstring));
    }else if(foundFunc(splitBrackets(p_inputstring))){
        input = inputFunc(splitBrackets(p_inputstring));
    }

    printvect(input);

}

void RE::printvect(vector<string> p_vector) {
    for(auto k:p_vector){
        cout << k << endl;
    }

}
