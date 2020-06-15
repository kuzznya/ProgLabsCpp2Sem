#pragma once

#include "../model/Cube.h"
#include "CubeSolver.h"
#include <string>
#include <deque>
#include <algorithm>

class CubeService {
public:
    CubeService() = delete;
    CubeService(Cube& cube);
    std::pair<RotationDirection, RotationSign> lastAction();
    void rotate(RotationDirection rd, RotationSign sign);

    void findSolution();
    void solutionStep();

private:
    Cube& cube;
    RotationDirection lastRD = RD_NONE;
    RotationSign lastSign = PLUS;
    std::deque<std::pair<RotationDirection, RotationSign>> solution;
};
