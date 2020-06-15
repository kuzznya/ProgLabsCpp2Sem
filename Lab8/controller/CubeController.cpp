#include "CubeController.h"

CubeController::CubeController()
: service(cube), view(cube) {}

void CubeController::start() {
    sf::Window window(sf::VideoMode(800, 600), "Rubik's cube");

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
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event = sf::Event();
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
                view.onResize(event.size.width, event.size.height);
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        view.render();
        window.display();
    }
}
