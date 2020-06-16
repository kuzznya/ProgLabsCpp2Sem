#pragma once

#include "../model/Cube.h"
#include "CubeSolver.h"
#include <string>
#include <deque>
#include <algorithm>
#include <exception>
#include <iostream>
#include <fstream>

class CubeService {
public:
    CubeService() = delete;
    CubeService(Cube& cube);
    std::pair<RotationDirection, RotationSign> lastAction();
    void rotate(RotationDirection rd, RotationSign sign);

    void findSolution();
    void solutionStep();

    void loadFromFile(const std::string& fileName);
    void writeToFile(const std::string& fileName);

private:
    Cube& cube;
    RotationDirection lastRD = RD_NONE;
    RotationSign lastSign = PLUS;
    std::deque<std::pair<RotationDirection, RotationSign>> solution;
};

class FileIOException : std::exception {
    const char* what() const noexcept override {
        return "File interaction error\n";
    }
};
