#include <iostream>
#include "TA_MenuaHovhannisyan/DFA.h"
#include "TA_MenuaHovhannisyan/NFA.h"
#include "TA_MenuaHovhannisyan/RE.h"


using namespace std;

int main() {
    RE re("BMW M(1+2+3+4+5+6+8)+MERCEDES (S+E+C)(6+5+4)3 + AUDI RS(3+4+5+6+7)");
    re.splitsRegex();
    return 0;
}