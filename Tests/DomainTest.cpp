//
// Created by user on 01.05.2022.
//

#include "DomainTest.h"

void DomainTest::test_flower() {
    Flower flower1;
    assert(flower1.getId() == 0);
    assert(flower1.getPrice() == 0);
    assert(flower1.getColor().empty());
    assert(flower1.getSeason().empty());
    assert(flower1.getSpecies().empty());

    flower1.setId(1);
    flower1.setColor("white");
    flower1.setSeason("spring");
    flower1.setSpecies("rose");
    flower1.setPrice(4.20);
    assert(flower1.getId() == 1);
    assert(flower1.getColor() == "white");
    assert(flower1.getSeason() == "spring");
    assert(flower1.getSpecies() == "rose");
    assert(flower1.getPrice() == 4.20);

    Flower flower2(2, "black", "tulip", "summer", 35.21);
    assert(flower2.getId() == 2);
    assert(flower2.getColor() == "black");
    assert(flower2.getSpecies() == "tulip");
    assert(flower2.getSeason() == "summer");
    assert(flower2.getPrice() == 35.21);

    Flower flower3(flower1);
    assert(flower3 == flower1);
}

void DomainTest::run_tests() {
    test_flower();
}
