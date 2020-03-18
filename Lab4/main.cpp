#include <iostream>
#include <map>
#include <vector>
#include "figures.h"
#include "figure_system.h"
#include "Menu.h"

int main() {
    FigureSystem system;
    map<std::string, std::string> options {
        make_pair("add", "Add new figure. Parameter: disk|trap"),
        make_pair("draw", "Draw the system"),
        make_pair("S", "Get total square of the system"),
        make_pair("P", "Get total perimeter of the system"),
        make_pair("CoM", "Get center of the mass"),
        make_pair("sort", "Sort figures by their mass"),
        make_pair("menu", "Show menu"),
        make_pair("exit", "Exit the program")
    };
    Menu menu(options);
    while (true) {
        std::vector<string> answer = menu.ask();
        if (answer[0] == "exit") {
            std::cout << "Hasta la vista, baby" << std::endl;
            return 0;
        }
        else if (answer[0] == "add") {
            if (answer[1] == "disk")
                system.add(FigureFactory::createFigure(FigureFactory::DiskFigure));
            else if (answer[1] == "trap")
                system.add(FigureFactory::createFigure(FigureFactory::IsoscelesTrapezoidFigure));
            else
                std::cout << "Incorrect parameter" << std::endl;
        }
        else if (answer[0] == "draw")
            system.draw();
        else if (answer[0] == "S")
            std::cout << system.totalSquare() << std::endl;
        else if (answer[0] == "P")
            std::cout << system.totalPerimeter() << std::endl;
        else if (answer[0] == "CoM") {
            Vector2D CoM = system.centerOfMass();
            std::cout << "(" << CoM.x << ", " << CoM.y << ")" << std::endl;
        }
        else if (answer[0] == "sort") {
            vector<IFigure*> sorted = system.sortByMass();
            for (IFigure* el : sorted) {
                std::cout << el->classname() << std::endl;
            }
        }
        else if (answer[0] == "menu") {
            menu.show();
        }
    }
}