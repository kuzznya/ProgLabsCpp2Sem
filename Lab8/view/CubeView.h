#pragma once

#define GL_SILENCE_DEPRECATION

#include "../model/Cube.h"
#include "../model/Colors.h"
#include <SFML/Graphics.hpp>
#include <GLUT/glut.h>

class CubeView {
public:
    CubeView() = delete;
    CubeView(Cube& cube);
    void render();
    void onResize(unsigned w, unsigned h);
private:
    const Cube& cube;
    int xCam = 20, yCam = 20, zCam = 0;
    int cubeSize = 12;

    void renderCube();
    static void renderSmallCube(const SmallCube& smallCube, double x, double y, double z, double size);
};
