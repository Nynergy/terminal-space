#pragma once

#include "CommandFactory.hpp"
#include "ScreenConstructor.hpp"

class GameEngine : public Engine {

private:
    State * state;
    CommandFactory * commandFactory;

    void createScreens();
    void passScreensToState(std::vector<Screen *> screens);
    void handleInput(int key);
    void renderActiveScreen();

public:
    GameEngine();
    ~GameEngine();

    void init() override;
    void run() override;

};
