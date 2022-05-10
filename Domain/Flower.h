//
// Created by user on 01.05.2022.
//

#include <string>
#include <ostream>
#include <istream>
#include <vector>
#include <sstream>

#ifndef FLOWER_SHOP_FLOWER_H
#define FLOWER_SHOP_FLOWER_H


class Flower {
private:
    unsigned int id;
    std::string color;
    std::string species;
    std::string season;
    double price;

public:
    Flower();

    Flower(unsigned id, std::string color, std::string species, std::string season, double price);

    Flower(const Flower &rhs);

    explicit Flower(std::vector<std::string> &data);

    ~Flower();

    bool operator==(const Flower &rhs) const;

    bool operator!=(const Flower &rhs) const;

    unsigned int getId() const;

    void setId(unsigned int id);

    const std::string &getColor() const;

    void setColor(const std::string &color);

    const std::string &getSpecies() const;

    void setSpecies(const std::string &species);

    const std::string &getSeason() const;

    void setSeason(const std::string &season);

    double getPrice() const;

    void setPrice(double price);

    friend std::ostream &operator<<(std::ostream &os, const Flower &flower);

    std::string toCSV() const;
};


#endif //FLOWER_SHOP_FLOWER_H

