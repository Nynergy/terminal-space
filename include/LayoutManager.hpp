#pragma once

#include "vexes.hpp"

// TODO: This is a prime candidate for feature added to vexes proper
class LayoutManager {

public:
    static Box generateLayoutBounds() {
        Point ul(0, 0); Point lr(COLS - 1, LINES - 2);
        Box bounds(ul, lr);

        return bounds;
    }

};
