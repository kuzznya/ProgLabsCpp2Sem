#include "CubeController.h"

CubeController::CubeController()
: service(cube), view(cube) {}

void CubeController::start() {
    sf::Window window(sf::VideoMode(800, 600), "Rubik's cube", sf::Style::Default, sf::ContextSettings(GLUT_DEPTH));

    // Set color and depth clear value
    glClearDepth(1.f);
//    glClearColor(0.f, 0.f, 0.f, 0.f);

    glClearColor(0.07, 0.07, 0.07, 0.0);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 500.f);

    while (window.isOpen())
    {
        sf::Event event = sf::Event();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized)
                view.onResize(event.size.width, event.size.height);
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                view.decCamY();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                view.incCamY();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                view.incCamX();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                view.decCamX();
            else if (event.type == sf::Event::MouseWheelScrolled && event.mouseWheelScroll.delta > 0)
                view.zoomIn();
            else if (event.type == sf::Event::MouseWheelScrolled && event.mouseWheelScroll.delta < 0)
                view.zoomOut();
        }
        view.render();
        window.display();
    }
}

