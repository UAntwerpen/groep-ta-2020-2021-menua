//
// Created by Menua on 30/05/2021.
//

#include "gui.h"

int gui::run(int p_argc, char *p_argv[]) {
    QApplication a(p_argc, p_argv);
    MainWindow w(filename);
    w.show();

    return a.exec();
}

gui::gui(const string &file) {
    filename = file;
}
