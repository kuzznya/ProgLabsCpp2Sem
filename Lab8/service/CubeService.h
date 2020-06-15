#pragma once

#include "../model/Cube.h"
#include "CubeSolver.h"
#include <string>

class CubeService {
public:
    CubeService() = delete;
    CubeService(Cube& cube);
    std::pair<RotationDirection, RotationSign> lastAction();
    void rotate(RotationDirection rd, RotationSign sign);

//    void findSolution();
//    void solution_step();
//    void solved();

private:
    Cube& cube;
    RotationDirection lastRD = RD_NONE;
    RotationSign lastSign = PLUS;
    std::string solution;
};
