//
// Created by user on 02.05.2022.
//

#ifndef MAIN_CPP_CONSOLE_H
#define MAIN_CPP_CONSOLE_H


#include "../Controller/FlowerController.h"

class Console {
private:
    FlowerController controller;
public:
    Console(FlowerController &controller);

    ~Console() = default;

    void showMenu();

    void runMenu();

};


#endif //MAIN_CPP_CONSOLE_H
