#include "GamePanel.hpp"

GamePanel::GamePanel(Box globalDimensions, std::string title) : Panel(globalDimensions, title) {}

void GamePanel::drawPanel() {
    clearScreen();
    drawBorder();
    drawTitle();
    // TODO: Remove the Hello World rendering
    drawHelloWorld();
    refreshWindow();
}

void GamePanel::drawHelloWorld() {
    int x, y;
    CENTER(win, x, y);
    std::string str = "Hello, world!";
    Point p(x, y);
    drawCenteredStringAtPoint(str, p, win);
}

std::string GamePanel::truncateStringByLength(std::string str, int length) {
    int stringLength = str.size();
    if(stringLength >= length) {
        std::string truncStr = str.substr(0, length - 4);
        return truncStr + "...";
    }

    return str;
}
