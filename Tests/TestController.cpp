//
// Created by user on 02.05.2022.
//

#include "TestController.h"
#include "../Repository/RepoInMemory.h"
#include "../Domain/Flower.h"
#include "../Controller/FlowerController.h"
#include <cassert>

void TestController::test() {
    RepoInMemory<Flower> repo;
    FlowerController controller(repo);

    controller.addFlower("blue", "tulip", "summer", 12);
    controller.addFlower("green", "cactus", "winter", 25);
    std::vector<Flower> flower = controller.readFlowers();
    assert(flower.size()==2);

}
