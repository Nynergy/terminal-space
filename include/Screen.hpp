#pragma once

#include "GamePanel.hpp"

class Screen {

private:
    std::vector<GamePanel *> panels;

public:
    Screen();
    ~Screen();

    void setPanels(std::vector<GamePanel *> newPanels);
    void renderScreen();

};
