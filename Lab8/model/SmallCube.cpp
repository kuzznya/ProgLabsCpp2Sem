#include "SmallCube.h"

void SmallCube::rotateX() noexcept {
    Color tmp = sidesColors[Side::UP];
    sidesColors[Side::UP] = sidesColors[Side::LEFT];
    sidesColors[Side::LEFT] = sidesColors[Side::DOWN];
    sidesColors[Side::DOWN] = sidesColors[Side::RIGHT];
    sidesColors[Side::RIGHT] = tmp;
}

void SmallCube::rotateY() noexcept {
    Color tmp = sidesColors[Side::FRONT];
    sidesColors[Side::FRONT] = sidesColors[Side::DOWN];
    sidesColors[Side::DOWN] = sidesColors[Side::BACK];
    sidesColors[Side::BACK] = sidesColors[Side::UP];
    sidesColors[Side::UP] = tmp;
}

void SmallCube::rotateZ() noexcept {
    Color tmp = sidesColors[Side::RIGHT];
    sidesColors[Side::RIGHT] = sidesColors[Side::BACK];
    sidesColors[Side::BACK] = sidesColors[Side::LEFT];
    sidesColors[Side::LEFT] = sidesColors[Side::FRONT];
    sidesColors[Side::FRONT] = tmp;
}

void SmallCube::setColor(Side side, char color) {
    sidesColors[side] = getColorByLetter(color);
}

void SmallCube::setColor(Side side, Color color) {
    sidesColors[side] = color;
}

Color SmallCube::getColor(Side side) {
    return sidesColors[side];
}
