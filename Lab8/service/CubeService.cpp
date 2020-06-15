#include <iostream>
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
