#include "State.hpp"

State::State() : exitFlag(false) {}

State::~State() {
    for(Screen * screen : screens) {
        delete screen;
    }
}

void State::addScreen(Screen * screen) {
    screens.push_back(screen);
}

std::vector<Screen *> State::getScreens() {
    return screens;
}

int State::getNumScreens() {
    return (int)screens.size();
}

void State::setCurrentScreen(int screenIndex) {
    screenIndex = wrapIndex(screenIndex);
    currentScreen = screenIndex;
}

int State::wrapIndex(int index) {
    if(index > getNumScreens() - 1) {
        return 0;
    }

    if(index < 0) {
        return getNumScreens() - 1;
    }

    return index;
}

Screen * State::getCurrentScreen() {
    return screens[currentScreen];
}

void State::resetIndices() {
    currentScreen = 0;
}

int State::getCurrentScreenIndex() {
    return currentScreen;
}

void State::setExitFlag(bool flag) {
    exitFlag = flag;
}

bool State::userHasQuit() {
    return exitFlag;
}

bool State::userHasNotQuit() {
    return !userHasQuit();
}
