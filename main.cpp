#include "Tests/AllTests.h"
#include "Repository/RepoInCsv.h"
#include "Controller/FlowerController.h"
#include "UI/Console.h"

int main() {
    AllTests::run_tests();

    RepoInCsv<Flower> repo("flowers.csv");
    FlowerController controller(repo);
    Console console(controller);

    console.runMenu();

    return 0;
}
