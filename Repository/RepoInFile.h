//
// Created by user on 01.05.2022.
//

#include "IRepo.h"
#include <string>

#ifndef FLOWER_SHOP_REPOINFILE_H
#define FLOWER_SHOP_REPOINFILE_H

template<class T>
class RepoInFile : public IRepo<T> {
private:
    std::vector<T> elements;
    std::string file_name;
public:
    RepoInFile(std::string file_name){
        this->file_name=file_name;
    }

    ~RepoInFile() = default;

    void create(T elem) override{

    }
};


#endif //FLOWER_SHOP_REPOINFILE_H
