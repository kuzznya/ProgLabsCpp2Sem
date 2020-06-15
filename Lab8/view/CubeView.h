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
    void render(RotationDirection rd, RotationSign sign);
    void onResize(unsigned w, unsigned h);

    void incCamX();
    void decCamX();
    void incCamY();
    void decCamY();

    void zoomIn();
    void zoomOut();

    bool actionFinished();
private:
    const Cube& cube;
    int xCam = 30, yCam = 30;
    int zDistance = -25;
    int cubeSize = 12;

    std::pair<RotationDirection, RotationSign> currentAction {RD_NONE, PLUS};
    int actionAngle = 0;

    void renderCube();
    static void renderSmallCube(const SmallCube& smallCube, double x, double y, double z, double size);
};
