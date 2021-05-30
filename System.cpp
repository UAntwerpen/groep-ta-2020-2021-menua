//
// Created by Menua on 26/05/2021.
//

#include "System.h"

System::System(const string &file_name) {
    file = file_name;
}

int System::start(int p_argc, char *p_argv[]) {
    gui g(file);
    g.run(p_argc,p_argv);
}
