//
// Created by Menua on 28/05/2021.
//

#include <string>
using namespace std;

#ifndef TAPROJECT2021_MENUAHOVHANNISYAN_EDGE_H
#define TAPROJECT2021_MENUAHOVHANNISYAN_EDGE_H

class Node;

class Edge {
public:
    Node* start;
    Node* end;
    string symbol;

};

#include "Node.h"

#endif //TAPROJECT2021_MENUAHOVHANNISYAN_EDGE_H
