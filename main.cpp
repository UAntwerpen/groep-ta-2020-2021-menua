#include <iostream>
#include "TA_MenuaHovhannisyan/DFA.h"
#include "TA_MenuaHovhannisyan/NFA.h"
#include "TA_MenuaHovhannisyan/RE.h"
#include "System.h"

using namespace std;

int main(int argc, char *argv[]) {
    System s("../data.json",argc,argv);
    s.start();




    /*RE re;
    pair<vector<Node *>, vector<Edge *>> pp;
    pp = re.toENFA("MERCEDES (S+E+C)(6+5+4)3");

    re.ENFAtoNFA(pp.first,pp.second).toDFA().print();
    cout << boolalpha << re.ENFAtoNFA(pp.first,pp.second).toDFA().accepts("MERCEDES S63") << endl;
    //re.testPrint("0+(01)+(0+1)*");*/
}