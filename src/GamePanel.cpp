#include "GamePanel.hpp"

GamePanel::GamePanel(Box globalDimensions, std::string title) : Panel(globalDimensions, title) {}

void GamePanel::drawPanel() {
    clearScreen();
    drawBorder();
    drawTitle();
    refreshWindow();
}

std::string GamePanel::truncateStringByLength(std::string str, int length) {
    int stringLength = str.size();
    if(stringLength >= length) {
        std::string truncStr = str.substr(0, length - 4);
        return truncStr + "...";
    }

    return str;
}
