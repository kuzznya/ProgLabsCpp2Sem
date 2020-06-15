#pragma once

#include "SmallCube.h"
#include "Side.h"
#include <array>
#include <vector>
#include <ctime>
#include <exception>

enum RotationDirection {
    RD_DOWN = 0,
    RD_UP = 1,
    RD_LEFT = 2,
    RD_RIGHT = 3,
    RD_FRONT = 4,
    RD_BACK = 5,
    RD_NONE = 6
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

    const SmallCube& smallCube(unsigned i, unsigned j, unsigned k) const;

    std::array<std::array<Color, 9>, 6> sidesColors() const;
    const std::array<std::array<uchar, 9>, 6> sidesColorLetters() const;

    bool solved();

private:
    std::array<std::array<std::array<SmallCube, 3>, 3>, 3> cubes {};
};

class InvalidIndexException : std::exception {
    const char* what() const noexcept override  {
        return "Invalid index\n";
    }
};
