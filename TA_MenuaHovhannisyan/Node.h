//
// Created by Menua on 28/05/2021.
//

#include <vector>
using namespace std;

#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_NODE_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_NODE_H

class Edge;

class Node {
public:
    vector<Edge*> outgoing;
    vector<Edge*> incomming;

};

#include "Edge.h"

#endif //TAPROJECT2021_MENUAHOVHANNISYAN_NODE_H
