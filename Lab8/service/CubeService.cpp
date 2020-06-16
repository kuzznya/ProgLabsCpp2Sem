#include "CubeService.h"

CubeService::CubeService(Cube &cube)
: cube(cube) {}

std::pair<RotationDirection, RotationSign> CubeService::lastAction() {
    return std::make_pair(lastRD, lastSign);
}

void CubeService::rotate(RotationDirection rd, RotationSign sign) {
    cube.rotate(rd, sign);
    lastRD = rd;
    lastSign = sign;
}

void CubeService::findSolution() {
    Rubik rubik;
    std::array<std::array<uchar, 9>, 6> colors = cube.sidesColorLetters();
    rubik.readRubik(colors);

    std::vector<uchar> result;
    rubik.solve(result);

    for (uchar e : result)
        std::cout << e;
    std:: cout << " " << result.size() << std::endl;

    solution.clear();
    for (uchar actionLetter : result) {
        switch (actionLetter) {
            case 'u':
                solution.emplace_back(RD_UP, MINUS);
                break;
            case 'U':
                solution.emplace_back(RD_UP, PLUS);
                break;
            case 'd':
                solution.emplace_back(RD_DOWN, PLUS);
                break;
            case 'D':
                solution.emplace_back(RD_DOWN, MINUS);
                break;
            case 'f':
                solution.emplace_back(RD_LEFT, MINUS);
                break;
            case 'F':
                solution.emplace_back(RD_LEFT, PLUS);
                break;
            case 'w':
                solution.emplace_back(RD_RIGHT, PLUS);
                break;
            case 'W':
                solution.emplace_back(RD_RIGHT, MINUS);
                break;
            case 'l':
                solution.emplace_back(RD_FRONT, PLUS);
                break;
            case 'L':
                solution.emplace_back(RD_FRONT, MINUS);
                break;
            case 'r':
                solution.emplace_back(RD_BACK, MINUS);
                break;
            case 'R':
                solution.emplace_back(RD_BACK, PLUS);
                break;
        }
    }
    std::reverse(solution.begin(), solution.end());
}

void CubeService::solutionStep() {
    if (cube.solved()) {
        solution.clear();
        lastRD = RD_NONE;
        return;
    }

    if (solution.empty())
        findSolution();

    rotate(solution.back().first, solution.back().second);
    solution.pop_back();
}

void CubeService::loadFromFile(const std::string& fileName) {
    std::ifstream input(fileName);
    if (!input.is_open())
        throw FileIOException();
    std::array<std::array<uchar, 9>, 6> sides;
    // UP
    for (int j = 2; j >= 0; j--)
        for (int i = 0; i < 3; i++)
            input >> sides[0][(2 - j) * 3 + i];

    // LEFT
    for (int i = 2; i >= 0; i--)
        for (int k = 2; k >= 0; k--)
            input >> sides[1][(2 - i) * 3 + (2 - k)];

    // FRONT
    for (int k = 2; k >= 0; k--)
        for (int j = 0; j < 3; j++)
            input >> sides[2][(2 - k) * 3 + j];

    // RIGHT
    for (int i = 2; i >= 0; i--)
        for (int k = 0; k < 3; k++)
            input >> sides[3][(2 - i) * 3 + k];

    // BACK
    for (int k = 2; k >= 0; k--)
        for (int j = 2; j >= 0; j--)
            input >> sides[4][(2 - k) * 3 + (2 - j)];

    // DOWN
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 3; i++)
            input >> sides[5][j * 3 + i];
        
    input.close();
    cube.load(sides);
}

void CubeService::writeToFile(const std::string& fileName) {
    std::ofstream output(fileName);
    if (!output.is_open())
        throw FileIOException();
    std::array<std::array<uchar, 9>, 6> sides = cube.sidesColorLetters();

    // UP
    for (int j = 2; j >= 0; j--) {
        for (int i = 0; i < 3; i++)
            output << sides[0][(2 - j) * 3 + i] << " ";
        output << std::endl;
    }

    output << std::endl;

    // LEFT
    for (int i = 2; i >= 0; i--) {
        for (int k = 2; k >= 0; k--)
            output << sides[1][(2 - i) * 3 + (2 - k)] << " ";
        output << std::endl;
    }

    output << std::endl;

    // FRONT
    for (int k = 2; k >= 0; k--) {
        for (int j = 0; j < 3; j++)
            output << sides[2][(2 - k) * 3 + j] << " ";
        output << std::endl;
    }

    output << std::endl;

    // RIGHT
    for (int i = 2; i >= 0; i--) {
        for (int k = 0; k < 3; k++)
            output << sides[3][(2 - i) * 3 + k] << " ";
        output << std::endl;
    }

    output << std::endl;

    // BACK
    for (int k = 2; k >= 0; k--) {
        for (int j = 2; j >= 0; j--)
            output << sides[4][(2 - k) * 3 + (2 - j)] << " ";
        output << std::endl;
    }

    output << std::endl;

    // DOWN
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++)
            output << sides[5][j * 3 + i] << " ";
        output << std::endl;
    }

    output.close();
}
