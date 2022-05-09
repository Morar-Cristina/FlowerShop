//
// Created by user on 01.05.2022.
//

#include "IRepo.h"
#include <stack>
#include <stdexcept>

#ifndef FLOWER_SHOP_REPOINMEMORY_H
#define FLOWER_SHOP_REPOINMEMORY_H


template<class T>
class RepoInMemory : public IRepo<T> {
private:
    std::vector<T> elements;
    std::stack<std::vector<T>> undoStack;
    std::stack<std::vector<T>> redoStack;

public:
    RepoInMemory() = default;

    ~RepoInMemory() = default;

    void create(T elem) override {
        undoStack.push(elements);
        redoStack = std::stack<std::vector<T>>();
        this->elements.push_back(elem);
    }

    T get(int index) override {
        return this->elements[index];
    }

    std::vector<T> getAll() override {
        return this->elements;
    }

    void update(T old_elem, T new_elem) override {
        undoStack.push(elements);
        redoStack = std::stack<std::vector<T>>();
        for (auto it = elements.begin(); it != elements.end(); ++it)
            if (*it == old_elem)
                *it = new_elem;
    }

    void remove(T elem) override {
        undoStack.push(elements);
        redoStack = std::stack<std::vector<T>>();
        for (auto it = elements.begin(); it != elements.end();) {
            if (*it == elem) {
                it = elements.erase(it);
            } else {
                ++it;
            }
        }
    }

    void undo() {
        if (undoStack.empty())
            throw std::invalid_argument("Cannot undo anymore.");
        std::vector<T> temp = this->undoStack.top();
        this->undoStack.pop();
        this->redoStack.push(this->elements);

        this->elements = temp;
    }

    void redo() {
        if (redoStack.empty())
            throw std::invalid_argument("Cannot redo anymore.");
        std::vector<T> temp = this->redoStack.top();
        this->redoStack.pop();
        this->undoStack.push(this->elements);

        this->elements = temp;
    }

};


#endif //FLOWER_SHOP_REPOINMEMORY_H
