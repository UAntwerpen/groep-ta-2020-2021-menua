#include <iostream>
#include "TA_MenuaHovhannisyan/DFA.h"
#include "TA_MenuaHovhannisyan/NFA.h"
#include "TA_MenuaHovhannisyan/RE.h"


using namespace std;

int main() {
    RE re("(m+y)*+(e+y+m+i)s");
    vector<string> tmp;
    string k1 = "(m+y)*";
    string k2 = "(e+y+m+i)s";
    tmp.push_back(k1);
    tmp.push_back(k2);
    re.unionFunc(tmp);
    return 0;
}