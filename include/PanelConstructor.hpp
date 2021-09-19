#pragma once

#include "GamePanel.hpp"

class PanelConstructor {

public:
    static GamePanel * constructGamePanel(Box dimensions, std::string title = "") {
        GamePanel * newPanel = new GamePanel(dimensions, title);

        return newPanel;
    }

};
