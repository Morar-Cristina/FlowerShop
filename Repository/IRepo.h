//
// Created by user on 01.05.2022.
//

#include <vector>

#ifndef FLOWER_SHOP_IREPO_H
#define FLOWER_SHOP_IREPO_H


template<class T>
class IRepo {
public:
    virtual void create(T elem) = 0;

    virtual T get(int index) = 0;

    virtual std::vector<T> getAll() = 0;

    virtual void update(T old_elem, T new_elem) = 0;

    virtual void remove(T elem) = 0;

    virtual void undo() = 0;

    virtual void redo() = 0;
};


#endif //FLOWER_SHOP_IREPO_H
