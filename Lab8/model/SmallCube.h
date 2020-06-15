#pragma once

#include <array>
#include <exception>
#include "Colors.h"
#include "Side.h"

class SmallCube {
public:
    SmallCube() = default;
    ~SmallCube() = default;

    void rotateX() noexcept;
    void rotateY() noexcept;
    void rotateZ() noexcept;

    void setColor(Side side, char color);
    void setColor(Side side, Color color);
    Color getColor(Side side) const;

private:
    // UP, DOWN, FRONT, BACK, LEFT, RIGHT
    std::array<Color, 6> sidesColors;
};
