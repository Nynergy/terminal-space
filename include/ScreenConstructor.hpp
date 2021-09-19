#pragma once

#include "LayoutManager.hpp"
#include "PanelConstructor.hpp"
#include "Screen.hpp"

const std::vector<std::string> SHIP_CONSOLE_PANEL_TITLES = {
    "Weapons", "Engineering", "Life Support", "Cargo & Credits", "System Scan", "Comms"
};

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

    static Screen * constructShipConsoleScreen() {
        std::vector<Box> layout = getShipConsoleLayout();
        std::vector<GamePanel *> panels = createPanelsWithLayout(layout);
        // Command prompt gets no title, hence the minus 1 below
        for(int i = 0; i < (int)panels.size() - 1; i++) {
            panels[i]->setTitle(SHIP_CONSOLE_PANEL_TITLES[i]);
        }
        Screen * screen = new Screen();
        screen->setPanels(panels);

        return screen;
    }

    static std::vector<Box> getShipConsoleLayout() {
        Box layoutBounds = LayoutManager::generateLayoutBounds();
        std::vector<Box> layout;

        // Main horizontal layout
        std::vector<Box> outerPanels = Layouts::customHLayout("1:2:1", &(layoutBounds));

        // Sublayout for ship systems
        std::vector<Box> leftPanels = Layouts::VThirds(&(outerPanels[0]));

        // Sublayout for cargo/credits and system scan
        std::vector<Box> rightPanels = Layouts::VTwoThirdsBelow(&(outerPanels[2]));

        // Sublayout for message log and command prompt
        // Command prompt will have room for single line input
        Box rightPanel = outerPanels[1];

        Point logPanelUL = rightPanel.ul;
        Point logPanelLR(rightPanel.lr.x, rightPanel.lr.y - 3);
        Box logPanel(logPanelUL, logPanelLR);

        Point promptPanelUL(logPanel.ll.x, logPanel.ll.y + 1);
        Point promptPanelLR = rightPanel.lr;
        Box promptPanel(promptPanelUL, promptPanelLR);

        // Add all sublayout panels to the actual layout
        for(Box b : leftPanels) {
            layout.push_back(b);
        }
        for(Box b : rightPanels) {
            layout.push_back(b);
        }
        layout.push_back(logPanel);
        layout.push_back(promptPanel);

        return layout;
    }

public:
    static std::vector<Screen *> constructAllScreens() {
        std::vector<Screen *> screens;
        screens.push_back(constructShipConsoleScreen());

        return screens;
    }

};
