//
// Created by user on 01.05.2022.
//

#include "Flower.h"
#include <utility>
#include <cstring>

Flower::Flower() {
    this->id = 0;
    this->color = "";
    this->species = "";
    this->season = "";
    this->price = 0;
}

Flower::Flower(unsigned int id, std::string color, std::string species, std::string season, double price) {
    this->id = id;
    this->color = std::move(color);
    this->species = std::move(species);
    this->season = std::move(season);
    this->price = price;
}

unsigned int Flower::getId() const {
    return id;
}

void Flower::setId(unsigned int id) {
    Flower::id = id;
}

const std::string &Flower::getColor() const {
    return color;
}

void Flower::setColor(const std::string &color) {
    Flower::color = color;
}

const std::string &Flower::getSpecies() const {
    return species;
}

void Flower::setSpecies(const std::string &species) {
    Flower::species = species;
}

const std::string &Flower::getSeason() const {
    return season;
}

void Flower::setSeason(const std::string &season) {
    Flower::season = season;
}

double Flower::getPrice() const {
    return price;
}

void Flower::setPrice(double price) {
    Flower::price = price;
}

bool Flower::operator==(const Flower &rhs) const {
    return color == rhs.color &&
           species == rhs.species &&
           season == rhs.season &&
           price == rhs.price &&
           id == rhs.id;
}

bool Flower::operator!=(const Flower &rhs) const {
    return !(rhs == *this);
}



Flower::Flower(const Flower &rhs) {
   if (*this != rhs) {
        this->id = rhs.id;
        this->color = rhs.color;
        this->species = rhs.species;
        this->season = rhs.season;
        this->price = rhs.price;
   }
}

std::ostream &operator<<(std::ostream &os, const Flower &flower) {
    os << "Flower{" << '\n' << "id: " << flower.id << '\n' <<
       " color: " << flower.color << '\n'
       << " species: " << flower.species << '\n' <<
       " season: " << flower.season << '\n' <<
       " price: " << flower.price << '\n'
       << '}' << '\n';
    return os;
}

Flower::Flower(std::vector<std::string> &data) {
    this->id = std::stoi(data[0]);
    this->color = data[1];
    this->species = data[2];
    this->season = data[3];
    this->price = std::stod(data[4]);
}

std::string Flower::toCSV() const {
    std::stringstream ss;
    ss << id << "," << color << "," << species << "," << season << "," << price;
    return ss.str();
}

Flower::~Flower() = default;
