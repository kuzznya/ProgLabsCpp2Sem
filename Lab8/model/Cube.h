#pragma once

#include "SmallCube.h"
#include "Side.h"
#include <array>
#include <vector>
#include <ctime>

enum RotationDirection {
    RD_DOWN = 0,
    RD_UP = 1,
    RD_LEFT = 2,
    RD_RIGHT = 3,
    RD_FRONT = 4,
    RD_BACK = 5
};

enum RotationSign {
    PLUS = 1,
    MINUS = 3
};

class Cube {
public:
    Cube();
    ~Cube() = default;

    void rotate(RotationDirection rd, RotationSign sign);
    void reset();
    void shuffle();

    std::array<std::array<Color, 9>, 6> sidesColors();
    std::array<std::array<char, 9>, 6> sidesColorLetters();

private:
    std::array<std::array<std::array<SmallCube, 3>, 3>, 3> cubes {};

//    std::array<int, 6> angles;

    int currentSide = -1;

//    std::array<std::array<std::array<bool, 3>, 3>, 3> isCorrect;
//    std::array<std::array<SmallCube, 3>, 3> tmp;
};
