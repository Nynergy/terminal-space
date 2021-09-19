#include "Command.hpp"

Command::Command(State * state) : state(state) {}

NOPCommand::NOPCommand(State * state) : Command(state) {}

void NOPCommand::execute() {
    // Absolutely nothing
}

ResizeWindowCommand::ResizeWindowCommand(State * state) : Command(state) {}

void ResizeWindowCommand::execute() {
    // TODO: ScreenConstructor will generate new vector of Boxes for each screen
    // Pass each new layout to appropriate screen via screen->resizePanels(newLayout)
    // Screen will then pass the appropriate Box to each panel and delegate via panel->resizePanel(newDimensions)
    // The Panel base class already implements this resizePanel() method, hooray!
}

QuitApplicationCommand::QuitApplicationCommand(State * state) : Command(state) {}

void QuitApplicationCommand::execute() {
    state->setExitFlag(true);
}
