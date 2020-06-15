#pragma once

#include <string>
#include "../model/Cube.h"
#include "../service/CubeService.h"
#include "../view/CubeView.h"
#include <SFML/Window.hpp>

class CubeController {
public:
    CubeController();
    void start();
private:
    Cube cube;
    CubeService service;
    CubeView view;
};
