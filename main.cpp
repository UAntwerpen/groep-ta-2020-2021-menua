#include <iostream>
#include "TA_MenuaHovhannisyan/DFA.h"
#include "TA_MenuaHovhannisyan/NFA.h"
#include "TA_MenuaHovhannisyan/RE.h"
#include "Interface/gui.h"


using namespace std;

int main(int argc, char *argv[]) {
    RE re("(m+y)*+(e+y+m+i)s");
    gui g;
    g.run(argc, argv);
    return 0;
}