#include "figure_system.h"

#include <algorithm>

void FigureSystem::add(IFigure* fig) {
    figures.push_back(fig);
}

void FigureSystem::draw() {
    for (IFigure* fig : figures)
        fig->draw();
}

double FigureSystem::totalSquare() {
    double S = 0;
    for (IFigure* fig : figures)
        S += fig->square();
    return S;
}

double FigureSystem::totalPerimeter() {
    double P = 0;
    for (IFigure* fig : figures)
        P += fig->perimeter();
    return P;
}

Vector2D FigureSystem::centerOfMass() {
    Vector2D result = {0, 0};
    double totalMass = 0;

    for (IFigure* fig : figures) {
        double figMass = fig->mass();
        Vector2D figPos = fig->position();
        result.x += figPos.x * figMass;
        result.y += figPos.y * figMass;
        totalMass += figMass;
    }

    result.x /= totalMass;
    result.y /= totalMass;
    return result;
}

const std::vector<IFigure*>& FigureSystem::sortByMass() {
    std::sort(figures.begin(), figures.end());
    return figures;
}
