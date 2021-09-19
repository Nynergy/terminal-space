#pragma once

#include "vexes.hpp"

class GamePanel : public Panel {

private:
    std::string truncateStringByLength(std::string str, int length);

public:
    GamePanel(Box globalDimensions, std::string title = "");

    void drawPanel() override;

};
