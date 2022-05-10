//
// Created by user on 01.05.2022.
//

#include "IRepo.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>

#ifndef FLOWER_SHOP_REPOINCSV_H
#define FLOWER_SHOP_REPOINCSV_H

template<class T>
class RepoInCsv : public IRepo<T> {
private:
    std::string fileName;
    std::vector<T> elements;

    std::stack<std::vector<T>> undoStack;
    std::stack<std::vector<T>> redoStack;

    void readFromFile() {
        std::ifstream file(fileName);
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string item;
            std::vector<std::string> lineVector;
            while (std::getline(ss, item, ',')) {
                lineVector.push_back(item);
            }
            elements.push_back(T(lineVector));
        }
    }

    void writeToFile() {
        std::ofstream file(fileName);
        for (auto& element : elements) {
            file << element.toCSV() << std::endl;
        }
    }

public:
    explicit RepoInCsv(const std::string& fileName) {
        this->fileName = fileName;
        this->elements = std::vector<T>();
        this->readFromFile();
    }

    ~RepoInCsv() = default;

    void create(T element) override {
        elements.push_back(element);
        writeToFile();
    }

    std::vector<T> getAll() override {
        undoStack.push(elements);
        redoStack = std::stack<std::vector<T>>();
        return this->elements;
    }

    T get(int index) override {
        return this->elements[index];
    }

    void update(T old_elem, T new_elem) override {
        undoStack.push(elements);
        redoStack = std::stack<std::vector<T>>();
        for (auto& element : elements) {
            if (element == old_elem) {
                element = new_elem;
                writeToFile();
                return;
            }
        }
    }

    void remove(T element) override {
        undoStack.push(elements);
        redoStack = std::stack<std::vector<T>>();
        for (auto it = elements.begin(); it != elements.end(); it++) {
            if (*it == element) {
                elements.erase(it);
                writeToFile();
                return;
            }
        }
    }

    void undo() override {
        if (undoStack.empty())
            throw std::invalid_argument("Cannot undo anymore.");
        std::vector<T> temp = this->undoStack.top();
        this->undoStack.pop();
        this->redoStack.push(this->elements);

        this->elements = temp;
        writeToFile();
    }

    void redo() override {
        if (redoStack.empty())
            throw std::invalid_argument("Cannot redo anymore.");
        std::vector<T> temp = this->redoStack.top();
        this->redoStack.pop();
        this->undoStack.push(this->elements);

        this->elements = temp;
        writeToFile();
    }
};


#endif //FLOWER_SHOP_REPOINCSV_H
