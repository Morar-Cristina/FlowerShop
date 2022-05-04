//
// Created by user on 02.05.2022.
//

#include "FlowerController.h"
#include "../Domain/Flower.h"

FlowerController::FlowerController(IRepo<Flower> &Irepo) : repo(Irepo) {}

void
FlowerController::addFlower(std::string color, std::string species, std::string season, double price) {
    Flower flower(this->next_id, color, species, season, price);
    repo.create(flower);
    this->next_id++;

}

std::vector<Flower> FlowerController::readFlowers() {
    return repo.getAll();
}

void FlowerController::removeFlower(int id) {
    if (id <= 0)
        throw std::invalid_argument("ID should be positive");
    Flower flower;
    std::vector<Flower> flowers = repo.getAll();
    for (Flower i: flowers)
        if (i.getId() == id)
            flower = i;
    if (flower.getId() == 0)
        throw std::invalid_argument("No flower has been found");
    repo.remove(flower);
}

void FlowerController::updateFlower(int id, std::string color, std::string species, std::string season, double price) {
    if (id <= 0)
        throw std::invalid_argument("ID should be positive");
    Flower oldFlower;
    Flower newFlower(id, color, species, season, price);
    std::vector<Flower> flowers = repo.getAll();
    for (Flower i: flowers)
        if (i.getId() == id)
            oldFlower = i;
    if (oldFlower.getId() == 0)
        throw std::invalid_argument("No flower has been found");
    repo.update(oldFlower, newFlower);

}


