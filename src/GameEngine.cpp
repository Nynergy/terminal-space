#include "GameEngine.hpp"

GameEngine::GameEngine() {
    state = new State();
    commandFactory = new CommandFactory(state);
}

GameEngine::~GameEngine() {
    delete state;
    delete commandFactory;
}

void GameEngine::init() {
    createScreens();
    state->setCurrentScreen(0);
}

void GameEngine::createScreens() {
    try {
        std::vector<Screen *> screens = ScreenConstructor::constructAllScreens();
        passScreensToState(screens);
    } catch(InvalidRatioException& e) {
        throw InvalidRatioException(e.what());
    }
}

void GameEngine::passScreensToState(std::vector<Screen *> screens) {
    for(Screen * screen : screens) {
        state->addScreen(screen);
    }
}

void GameEngine::run() {
    int key;
    while(state->userHasNotQuit()) {
        // Handle input first, then render panels
        key = getch();
        handleInput(key);
        renderActiveScreen();
    }
}

void GameEngine::handleInput(int key) {
    Command * command = commandFactory->getCommandFromKey(key);
    command->execute();
    delete command;
}

void GameEngine::renderActiveScreen() {
    Screen * activeScreen = state->getCurrentScreen();
    activeScreen->renderScreen();
}
