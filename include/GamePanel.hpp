#pragma once

#include "vexes.hpp"

class GamePanel : public Panel {

private:
    // TODO: Remove the Hello World rendering
    void drawHelloWorld();
    std::string truncateStringByLength(std::string str, int length);

public:
    GamePanel(Box globalDimensions, std::string title = "");

    void drawPanel() override;

};
