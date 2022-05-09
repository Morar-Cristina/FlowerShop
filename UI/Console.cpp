//
// Created by user on 02.05.2022.
//

#include <iostream>
#include "Console.h"

Console::Console(FlowerController &controller) : controller(controller) {}

void Console::showMenu() {
    std::cout << "1. Add flower" << '\n';
    std::cout << "2. Show flowers" << '\n';
    std::cout << "3. Remove flower" << '\n';
    std::cout << "4. Update flower" << '\n';
    std::cout << "u. Undo" << '\n';
    std::cout << "r. Redo" << '\n';
    std::cout << "x. Exit" << '\n';
    std::cout << "Option: ";
}

void Console::runMenu() {
    char option;
    bool shouldRun = true;

    while (shouldRun) {
        this->showMenu();
        std::cin >> option;
        switch (option) {
            case '1': {
                std::string color, species, season;
                double price;
                std::cout << "Give color: ";
                std::cin >> color;
                std::cout << "Give species: ";
                std::cin >> species;
                std::cout << "Give season: ";
                std::cin >> season;
                std::cout << "Give price: ";
                std::cin >> price;
                controller.addFlower(color, species, season, price);
                break;
            }
            case '2': {
                std::vector<Flower> flowers = controller.readFlowers();
                for (int i = 0; i < flowers.size(); i++) {
                    std::cout << flowers[i];
                }
                break;
            }
            case '3': {
                int id;
                std::cout << "Id: ";
                std::cin >> id;
                try {
                    controller.removeFlower(id);
                }
                catch (std::invalid_argument &e) {
                    std::cout << e.what();
                }
                break;
            }
            case '4': {
                std::string color, species, season;
                int id;
                double price;
                std::cout << "Give ID: ";
                std::cin >> id;
                std::cout << "Give color: ";
                std::cin >> color;
                std::cout << "Give species: ";
                std::cin >> species;
                std::cout << "Give season: ";
                std::cin >> season;
                std::cout << "Give price: ";
                std::cin >> price;
                try {
                    controller.updateFlower(id, color, species, season, price);
                }
                catch (std::invalid_argument &e) {
                    std::cout << e.what();
                }
                break;
            }
            case 'u': {
                try {
                    controller.undo();
                }
                catch (std::invalid_argument &e) {
                    std::cout << e.what();
                }
                break;
            }
            case 'r': {
                try {
                    controller.redo();
                }
                catch (std::invalid_argument &e) {
                    std::cout << e.what();
                }
                break;
            }
            case 'x': {
                shouldRun = false;
                break;
            }
            default: {
                std::cout << "Invalid option! Try again!" << '\n';
            }
        }
    }

}

