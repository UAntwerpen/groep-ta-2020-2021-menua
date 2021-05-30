#include <iostream>
#include "TA_MenuaHovhannisyan/DFA.h"
#include "TA_MenuaHovhannisyan/NFA.h"
#include "TA_MenuaHovhannisyan/RE.h"
#include "Interface/gui.h"
#include "System.h"

using namespace std;

int main(int argc, char *argv[]) {
    System s("../data.json");
    s.start(argc, argv);

    return 0;
}