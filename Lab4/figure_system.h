#pragma once

#include <vector>
#include <memory>
#include "figures.h"

class FigureSystem {
public:
    void add(IFigure*);
    void draw();
    double totalSquare();
    double totalPerimeter();
    Vector2D centerOfMass();
    const std::vector<IFigure*>& sortByMass();

private:
    std::vector<IFigure*> figures;
};

