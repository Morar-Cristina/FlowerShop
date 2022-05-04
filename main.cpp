#include "Tests/AllTests.h"
#include "Repository/RepoInMemory.h"
#include "Controller/FlowerController.h"
#include "UI/Console.h"

int main() {
    AllTests::run_tests();

    RepoInMemory<Flower> repo;
    FlowerController controller(repo);
    Console console(controller);

    console.runMenu();

    return 0;
}
