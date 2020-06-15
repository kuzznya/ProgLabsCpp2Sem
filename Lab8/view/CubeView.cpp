#include "CubeView.h"

#include <iostream>
#include <unistd.h>

CubeView::CubeView(Cube& cube)
: cube(cube) {}

void CubeView::render() {
    if (actionAngle > 90)
        currentAction.first = RD_NONE;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);

    glTranslated(0, 0, zDistance);

    glRotatef(xCam, 1, 0, 0);
    glRotatef(yCam, 0, 1, 0);

    glRotatef(90.f, 1, 0, 0);
    glRotatef(180.f, 0, 1, 0);
    glRotatef(180.f, 0, 0, 1);

    glTranslated(cubeSize / -2.0, cubeSize / -2.0, cubeSize / -2.0);

    renderCube();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();

    if (!actionFinished())
        usleep(turnDelay);
}

void CubeView::render(RotationDirection rd, RotationSign sign) {
    actionAngle = 0;
    currentAction = std::make_pair(rd, sign);
    render();
}

void CubeView::onResize(unsigned w, unsigned h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat fAspect = (GLfloat) w / (float) h;
    gluPerspective(60, fAspect, 1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void CubeView::incCamX() {
    if (xCam < 87 || xCam > 267)
        xCam += 3;
    if (xCam >= 360)
        xCam -= 360;
}

void CubeView::decCamX() {
    if (xCam < 93 || xCam > 273)
        xCam -= 3;
    if (xCam < 0)
        xCam += 360;
}

void CubeView::incCamY() {
    yCam += 3;
    if (yCam >= 360)
        yCam -= 360;
}

void CubeView::decCamY() {
    yCam -= 3;
    if (yCam < 0)
        yCam += 360;
}

void CubeView::zoomIn() {
    if (zDistance < -15)
        zDistance += 3;
}

void CubeView::zoomOut() {
    if (zDistance > -70)
        zDistance -= 3;
}

void CubeView::incSpeed() {
    if (turnDelay >= 500)
        turnDelay -= 500;
}

void CubeView::decSpeed() {
    if (turnDelay <= 19500)
        turnDelay += 500;
}

bool CubeView::actionFinished() {
    return currentAction.first == RD_NONE;
}

void CubeView::renderCube() {
    std::vector<std::vector<std::vector<bool>>> rendered(3, std::vector(3, std::vector(3, false)));

    int i, j, k;
    glPushMatrix();
    switch (currentAction.first) {
        case RD_DOWN:
        case RD_UP:
            k = (currentAction.first & 1) * 2;
            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    rendered[i][j][k] = true;

            glTranslated(cubeSize / 2.0, cubeSize / 2.0, 0);

            glRotatef(90 * (currentAction.second == MINUS ? -1 : 1), 0, 0, 1);
            glRotatef((actionAngle + 5) * (currentAction.second == MINUS ? 1 : -1), 0, 0, 1);
            actionAngle += 5;

            glTranslated(-cubeSize / 2.0, -cubeSize / 2.0, 0);
            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    renderSmallCube(cube.smallCube(i, j, k), cubeSize / 3.0 * i, cubeSize / 3.0 * j, cubeSize / 3.0 * k, cubeSize / 3.0 * 0.97);
            break;
        case RD_LEFT:
        case RD_RIGHT:
            j = (currentAction.first & 1) * 2;
            for (i = 0; i < 3; i++)
                for (k = 0; k < 3; k++)
                    rendered[i][j][k] = true;

            glTranslated(cubeSize / 2.0, 0, cubeSize / 2.0);

            glRotatef(90 * (currentAction.second == MINUS ? 1 : -1), 0, 1, 0);
            glRotatef((actionAngle + 5) * (currentAction.second == MINUS ? -1 : 1), 0, 1, 0);
            actionAngle += 5;

            glTranslated(-cubeSize / 2.0, 0, -cubeSize / 2.0);
            for (i = 0; i < 3; i++)
                for (k = 0; k < 3; k++)
                    renderSmallCube(cube.smallCube(i, j, k), cubeSize / 3.0 * i, cubeSize / 3.0 * j, cubeSize / 3.0 * k, cubeSize / 3.0 * 0.97);
            break;
        case RD_FRONT:
        case RD_BACK:
            i = (currentAction.first & 1) * 2;
            for (j = 0; j < 3; j++)
                for (k = 0; k < 3; k++)
                    rendered[i][j][k] = true;

            glTranslated(0, cubeSize / 2.0, cubeSize / 2.0);

            glRotatef(90 * (currentAction.second == MINUS ? -1 : 1), 1, 0, 0);
            glRotatef((actionAngle + 5) * (currentAction.second == MINUS ? 1 : -1), 1, 0, 0);
            actionAngle += 5;

            glTranslated(0, -cubeSize / 2.0, -cubeSize / 2.0);
            for (j = 0; j < 3; j++)
                for (k = 0; k < 3; k++)
                    renderSmallCube(cube.smallCube(i, j, k), cubeSize / 3.0 * i, cubeSize / 3.0 * j, cubeSize / 3.0 * k, cubeSize / 3.0 * 0.97);
        case RD_NONE:
            break;
    }
    glPopMatrix();

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if(!rendered[i][j][k])
                    renderSmallCube(cube.smallCube(i, j, k), cubeSize / 3.0 * i, cubeSize / 3.0 * j, cubeSize / 3.0 * k, cubeSize / 3.0 * 0.97);
}

void CubeView::renderSmallCube(const SmallCube& smallCube, double x, double y, double z, double size) {
    glPushMatrix();
    glTranslated(x, y, z);

    glPushMatrix();
    glBegin(GL_QUADS);

    // UP
    std::shared_ptr<uchar> rgb = getColorRGB(smallCube.getColor(Side::UP));
    glColor3ubv(rgb.get());
    glVertex3f(size, size, size);
    glVertex3f(0, size, size);
    glVertex3f(0, 0, size);
    glVertex3f(size, 0, size);

    // DOWN
    rgb = getColorRGB(smallCube.getColor(Side::DOWN));
    glColor3ubv(rgb.get());
    glVertex3f(size, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, size, 0);
    glVertex3f(size, size, 0);

    // FRONT
    rgb = getColorRGB(smallCube.getColor(Side::FRONT));
    glColor3ubv(rgb.get());
    glVertex3f(size, 0, size);
    glVertex3f(0, 0, size);
    glVertex3f(0, 0, 0);
    glVertex3f(size, 0, 0);

    // BACK
    rgb = getColorRGB(smallCube.getColor(Side::BACK));
    glColor3ubv(rgb.get());
    glVertex3f(size, size, 0);
    glVertex3f(0, size, 0);
    glVertex3f(0, size, size);
    glVertex3f(size, size, size);

    // LEFT
    rgb = getColorRGB(smallCube.getColor(Side::LEFT));
    glColor3ubv(rgb.get());
    glVertex3f(0, size, size);
    glVertex3f(0, size, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, size);

    // RIGHT
    rgb = getColorRGB(smallCube.getColor(Side::RIGHT));
    glColor3ubv(rgb.get());
    glVertex3f(size, size, 0);
    glVertex3f(size, size, size);
    glVertex3f(size, 0, size);
    glVertex3f(size, 0, 0);

    glEnd();
    glPopMatrix();

    glPopMatrix();
}
