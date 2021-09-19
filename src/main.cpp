#include <iostream>

#include "GameEngine.hpp"

int main() {

    GameEngine * engine = new GameEngine();

    try {
        engine->init();
        engine->run();
    } catch(std::exception& e) {
        delete engine;
        std::cerr << "*** ERROR IN ENGINE ***" << std::endl;
        std::cerr << "Exception: " << e.what() << std::endl;

        return 1;
    }

    delete engine;

    return 0;

}
