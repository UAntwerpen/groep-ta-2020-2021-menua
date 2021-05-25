#include <iostream>
#include "DFA.h"
#include "NFA.h"

using namespace std;

int main() {
    DFA dfa1("../TA_json/DFA1.json");
    DFA dfa2("../TA_json/DFA2.json");
    DFA product(dfa1,dfa2,true); // true betekent doorsnede, false betekent unie
    product.print();
    return 0;
}