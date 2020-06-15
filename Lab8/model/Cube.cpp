#include "Cube.h"

std::array<Color, 6> defaultColors =
        {Color::WHITE, Color::YELLOW,  // UP, DOWN
         Color::GREEN,Color::BLUE,     // FRONT, DOWN
         Color::ORANGE, Color::RED
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
        }
    }
}

void Cube::reset() {
    // верх
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            cubes[i][j][2].setColor(Side::UP, defaultColors[Side::UP]);

    // низ
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            cubes[i][j][0].setColor(Side::DOWN, defaultColors[Side::DOWN]);

    // спереди
    for (size_t k = 0; k < 3; k++)
        for (size_t j = 0; j < 3; j++)
            cubes[j][0][k].setColor(Side::FRONT, defaultColors[Side::FRONT]);

    // сзади
    for (size_t k = 0; k < 3; k++)
        for (size_t j = 0; j < 3; j++)
            cubes[j][2][k].setColor(Side::BACK, defaultColors[Side::BACK]);

    // слева
    for (size_t i = 0; i < 3; i++)
        for (size_t k = 0; k < 3; k++)
            cubes[0][k][i].setColor(Side::LEFT, defaultColors[Side::LEFT]);

    // справа
    for (size_t i = 0; i < 3; i++)
        for (size_t k = 0; k < 3; k++)
            cubes[2][k][i].setColor(Side::RIGHT, defaultColors[Side::RIGHT]);
}

void Cube::shuffle() {
    srand(std::time(nullptr));
    for (auto i = 0; i < 15; i++)
        rotate(static_cast<RotationDirection>(rand() % 6), RotationSign::PLUS);
}

std::array<std::array<Color, 9>, 6> Cube::sidesColors() {
    std::array<std::array<Color, 9>, 6> sides {};
    
    //верх
    for (int j = 2; j >= 0; j--)
        for (int i = 0; i < 3; i++)
            sides[0][(2 - j) * 3 + i] = cubes[i][j][2].getColor(Side::UP);

    // слева
    for (int i = 2; i >= 0; i--)
        for (int k = 2; k >= 0; k--)
            sides[1][(2 - i) * 3 + (2 - k)] = cubes[0][k][i].getColor(Side::LEFT);

    // спереди
    for (int k = 2; k >= 0; k--)
        for (int j = 0; j < 3; j++)
            sides[2][(2 - k) * 3 + j] = cubes[j][0][k].getColor(Side::FRONT);

    // справа
    for (int i = 2; i >= 0; i--)
        for (int k = 0; k < 3; k++)
            sides[3][(2 - i) * 3 + k] = cubes[2][k][i].getColor(Side::RIGHT);

    // сзади
    for (int k = 2; k >= 0; k--)
        for (int j = 2; j >= 0; j--)
            sides[4][(2 - k) * 3 + (2 - j)] = cubes[j][2][k].getColor(Side::BACK);

    // низ
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 3; i++)
            sides[5][j * 3 + i] = cubes[i][j][0].getColor(Side::DOWN);

    return sides;
}

std::array<std::array<char, 9>, 6> Cube::sidesColorLetters() {
    std::array<std::array<Color, 9>, 6> sides = sidesColors();

    std::array<std::array<char, 9>, 6> letters {};

    for (int i = 0; i < sides.size(); i++)
        for (int j = 0; j < sides[i].size(); j++)
            letters[i][j] = getColorLetter(sides[i][j]);

    return letters;
}
