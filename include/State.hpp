#pragma once

#include "Screen.hpp"

class State {

private:
    std::vector<Screen *> screens;
    int currentScreen;
    bool exitFlag;

    int wrapIndex(int index);
    void resetIndices();

public:
    State();
    ~State();
    void addScreen(Screen * screen);
    std::vector<Screen *> getScreens();
    int getNumScreens();
    void setCurrentScreen(int screenIndex);
    Screen * getCurrentScreen();
    int getCurrentScreenIndex();
    void setExitFlag(bool flag);
    bool userHasQuit();
    bool userHasNotQuit();

};
