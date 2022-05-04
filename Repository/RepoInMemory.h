//
// Created by user on 01.05.2022.
//

#include "IRepo.h"

#ifndef FLOWER_SHOP_REPOINMEMORY_H
#define FLOWER_SHOP_REPOINMEMORY_H


template<class T>
class RepoInMemory : public IRepo<T> {
private:
    std::vector<T> elements;

public:
    RepoInMemory() = default;

    ~RepoInMemory() = default;

    void create(T elem) override {
        this->elements.push_back(elem);
    }

    T get(int index) override {
        return this->elements[index];
    }

    std::vector<T> getAll() override {
        return this->elements;
    }

    void update(T old_elem, T new_elem) override {
        for (auto it = elements.begin(); it != elements.end(); ++it)
            if (*it == old_elem)
                *it = new_elem;
    }

    void remove(T elem) override {
        for (auto it = elements.begin(); it != elements.end();) {
            if (*it == elem) {
                it = elements.erase(it);
            } else {
                ++it;
            }
        }
    }
};


#endif //FLOWER_SHOP_REPOINMEMORY_H
