#include "Cube.h"

std::array<Color, 6> defaultColors =
        {Color::WHITE, Color::YELLOW,   // UP, DOWN
         Color::GREEN,Color::BLUE,      // FRONT, BACK
         Color::ORANGE, Color::RED      // LEFT, RIGHT
};   // LEFT, RIGHT

Cube::Cube() {
    reset();
}

void Cube::rotate(RotationDirection rd, RotationSign sign) {
    int i, j, k;
    std::array<std::array<SmallCube, 3>, 3> tmp {};

    int rotationCount = sign;
    int idx = rd;
    while (rotationCount--) {
        switch (rd) {
            case RD_DOWN:
            case RD_UP:
                k = (idx & 1) * 2;
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 3; j++)
                        tmp[j][2 - i] = cubes[i][j][k];
                for (i = 0; i < 3; i++)
                    for (j = 0; j < 3; j++) {
                        tmp[i][j].rotateZ();
                        cubes[i][j][k] = tmp[i][j];
                    }
                break;
            case RD_LEFT:
            case RD_RIGHT:
                j = (idx & 1) * 2;
                for (i = 0; i < 3; i++)
                    for (k = 0; k < 3; k++)
                        tmp[k][2 - i] = cubes[i][j][k];
                for (i = 0; i < 3; i++)
                    for (k = 0; k < 3; k++) {
                        tmp[i][k].rotateX();
                        cubes[i][j][k] = tmp[i][k];
                    }
                break;
            case RD_FRONT:
            case RD_BACK:
                i = (idx & 1) * 2;
                for (j = 0; j < 3; j++)
                    for (k = 0; k < 3; k++)
                        tmp[k][2 - j] = cubes[i][j][k];
                for (j = 0; j < 3; j++)
                    for (k = 0; k < 3; k++) {
                        tmp[j][k].rotateY();
                        cubes[i][j][k] = tmp[j][k];
                    }
                break;
            case RD_NONE:
                break;
        }
    }
}

void Cube::reset() {
    // UP
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            cubes[i][j][2].setColor(Side::UP, defaultColors[Side::UP]);

    // DOWN
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            cubes[i][j][0].setColor(Side::DOWN, defaultColors[Side::DOWN]);

    // FRONT
    for (size_t k = 0; k < 3; k++)
        for (size_t j = 0; j < 3; j++)
            cubes[j][0][k].setColor(Side::FRONT, defaultColors[Side::FRONT]);

    // BACK
    for (size_t k = 0; k < 3; k++)
        for (size_t j = 0; j < 3; j++)
            cubes[j][2][k].setColor(Side::BACK, defaultColors[Side::BACK]);

    // LEFT
    for (size_t i = 0; i < 3; i++)
        for (size_t k = 0; k < 3; k++)
            cubes[0][k][i].setColor(Side::LEFT, defaultColors[Side::LEFT]);

    // RIGHT
    for (size_t i = 0; i < 3; i++)
        for (size_t k = 0; k < 3; k++)
            cubes[2][k][i].setColor(Side::RIGHT, defaultColors[Side::RIGHT]);
}

void Cube::shuffle() {
    srand(std::time(nullptr));
    for (auto i = 0; i < 15; i++)
        rotate(static_cast<RotationDirection>(rand() % 6), RotationSign::PLUS);
}

const SmallCube& Cube::smallCube(unsigned i, unsigned j, unsigned k) const {
    if (i > 2 || j > 2 || k > 2)
        throw InvalidIndexException();
    return cubes[i][j][k];
}

std::array<std::array<Color, 9>, 6> Cube::sidesColors() const {
    std::array<std::array<Color, 9>, 6> sides {};
    
    // UP
    for (int j = 2; j >= 0; j--)
        for (int i = 0; i < 3; i++)
            sides[0][(2 - j) * 3 + i] = cubes[i][j][2].getColor(Side::UP);

    // LEFT
    for (int i = 2; i >= 0; i--)
        for (int k = 2; k >= 0; k--)
            sides[1][(2 - i) * 3 + (2 - k)] = cubes[0][k][i].getColor(Side::LEFT);

    // FRONT
    for (int k = 2; k >= 0; k--)
        for (int j = 0; j < 3; j++)
            sides[2][(2 - k) * 3 + j] = cubes[j][0][k].getColor(Side::FRONT);

    // RIGHT
    for (int i = 2; i >= 0; i--)
        for (int k = 0; k < 3; k++)
            sides[3][(2 - i) * 3 + k] = cubes[2][k][i].getColor(Side::RIGHT);

    // BACK
    for (int k = 2; k >= 0; k--)
        for (int j = 2; j >= 0; j--)
            sides[4][(2 - k) * 3 + (2 - j)] = cubes[j][2][k].getColor(Side::BACK);

    // DOWN
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 3; i++)
            sides[5][j * 3 + i] = cubes[i][j][0].getColor(Side::DOWN);

    return sides;
}

std::array<std::array<char, 9>, 6> Cube::sidesColorLetters() const {
    std::array<std::array<Color, 9>, 6> sides = sidesColors();

    std::array<std::array<char, 9>, 6> letters {};

    for (int i = 0; i < sides.size(); i++)
        for (int j = 0; j < sides[i].size(); j++)
            letters[i][j] = getColorLetter(sides[i][j]);

    return letters;
}

bool Cube::solved() {
    // UP
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            if (cubes[i][j][2].getColor(Side::UP) != defaultColors[Side::UP]) return false;

    // DOWN
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            if (cubes[i][j][0].getColor(Side::DOWN) != defaultColors[Side::DOWN]) return false;

    // FRONT
    for (size_t k = 0; k < 3; k++)
        for (size_t j = 0; j < 3; j++)
            if (cubes[j][0][k].getColor(Side::FRONT) != defaultColors[Side::FRONT]) return false;

    // BACK
    for (size_t k = 0; k < 3; k++)
        for (size_t j = 0; j < 3; j++)
            if (cubes[j][2][k].getColor(Side::BACK) != defaultColors[Side::BACK]) return false;

    // LEFT
    for (size_t i = 0; i < 3; i++)
        for (size_t k = 0; k < 3; k++)
            if (cubes[0][k][i].getColor(Side::LEFT) != defaultColors[Side::LEFT]) return false;

    // RIGHT
    for (size_t i = 0; i < 3; i++)
        for (size_t k = 0; k < 3; k++)
            if (cubes[2][k][i].getColor(Side::RIGHT) != defaultColors[Side::RIGHT]) return false;

    return true;
}
