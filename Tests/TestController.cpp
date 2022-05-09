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
    assert(controller.readFlowers().size() == 2);
    controller.removeFlower(1);
    assert(controller.readFlowers().size() == 1);
    controller.updateFlower(2, "red", "tulip", "autumn", 30);
}
