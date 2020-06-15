#include "CubeView.h"

#include <iostream>

CubeView::CubeView(Cube& cube)
: cube(cube) {}

void CubeView::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);

    glTranslated(0, 0, zDistance);

    glRotatef(xCam, 1, 0, 0);
    glRotatef(yCam, 0, 1, 0);

    glTranslated(cubeSize / -2.0, cubeSize / -2.0, cubeSize / -2.0);

    renderCube();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
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
    xCam += 3;
    if (xCam >= 360)
        xCam -= 360;
    glutPostRedisplay();
}

void CubeView::decCamX() {
    xCam -= 3;
    if (xCam < 0)
        xCam += 360;
    glutPostRedisplay();
}

void CubeView::incCamY() {
    yCam += 3;
    if (yCam >= 360)
        yCam -= 360;
    glutPostRedisplay();
}

void CubeView::decCamY() {
    yCam -= 3;
    if (yCam < 0)
        yCam += 360;
    glutPostRedisplay();
}

void CubeView::zoomIn() {
    zDistance += 3;
    glutPostRedisplay();
}

void CubeView::zoomOut() {
    zDistance -= 3;
    glutPostRedisplay();
}

void CubeView::renderCube() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                    renderSmallCube(cube.getSmallCube(i, j, k), cubeSize / 3.0 * i, cubeSize / 3.0 * j, cubeSize / 3.0 * k, cubeSize / 3.0 * 0.95);
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
