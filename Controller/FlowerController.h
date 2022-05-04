//
// Created by user on 02.05.2022.
//

#include <string>
#include "../Domain/Flower.h"
#include "../Repository/IRepo.h"

#ifndef FLOWER_SHOP_FLOWERCONTROLLER_H
#define FLOWER_SHOP_FLOWERCONTROLLER_H


class FlowerController {
private:
    IRepo<Flower> &repo;
    unsigned int next_id = 1;
public:

    FlowerController(IRepo<Flower> &Irepo);

    ~FlowerController() = default;

    void addFlower(std::string color, std::string species, std::string season, double price);

    void removeFlower(int id);

    void updateFlower(int id, std::string color, std::string species, std::string season, double price);

    std::vector<Flower> readFlowers();
};


#endif //FLOWER_SHOP_FLOWERCONTROLLER_H
