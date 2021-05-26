#include <iostream>
#include "TA_MenuaHovhannisyan/DFA.h"
#include "TA_MenuaHovhannisyan/NFA.h"

using namespace std;

int main() {
    NFA nfa("../TA_MenuaHovhannisyan/TA_json/NFA.json");
    nfa.toDFA().print();
    return 0;
}