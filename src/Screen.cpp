#include "Screen.hpp"

Screen::Screen() {}

Screen::~Screen() {
    for(GamePanel * panel : panels) {
        delete panel;
    }
}

void Screen::setPanels(std::vector<GamePanel *> newPanels) {
    panels = newPanels;
}

void Screen::renderScreen() {
    for(GamePanel * panel : panels) {
        panel->drawPanel();
    }
}
