cmake_minimum_required(VERSION 3.21)
project(Flower_Shop)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flower_Shop main.cpp Domain/Flower.cpp Domain/Flower.h Tests/DomainTest.cpp Tests/DomainTest.h Tests/AllTests.cpp Tests/AllTests.h Repository/IRepo.h Repository/RepoInFile.h Repository/RepoInCsv.h Repository/RepoInMemory.h Controller/FlowerController.cpp Controller/FlowerController.h Tests/TestController.cpp Tests/TestController.h UI/Console.cpp UI/Console.h)
