#pragma once

#include "LayoutManager.hpp"
#include "PanelConstructor.hpp"
#include "Screen.hpp"

class ScreenConstructor {

private:
    static std::vector<GamePanel *> createPanelsWithLayout(std::vector<Box> layout) {
        std::vector<GamePanel *> panels;
        for(Box dimensions : layout) {
            GamePanel * panel = PanelConstructor::constructGamePanel(dimensions);
            panels.push_back(panel);
        }

        return panels;
    }

    static Screen * constructTitleScreen() {
        std::vector<Box> layout = getTitleLayout();
        std::vector<GamePanel *> panels = createPanelsWithLayout(layout);
        Screen * screen = new Screen();
        screen->setPanels(panels);

        return screen;
    }

    static std::vector<Box> getTitleLayout() {
        Box layoutBounds = LayoutManager::generateLayoutBounds();
        std::vector<Box> layout;
        layout.push_back(layoutBounds);

        return layout;
    }

public:
    static std::vector<Screen *> constructAllScreens() {
        std::vector<Screen *> screens;
        screens.push_back(constructTitleScreen());

        return screens;
    }

};
