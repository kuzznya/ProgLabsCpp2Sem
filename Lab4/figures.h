#pragma once

#include <string>

#include "base.h"

class IFigure :
        public BaseCObject, public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable {};

class Disk : public IFigure {
public:
    Disk();
    Disk(Vector2D, double, double);
    ~Disk();

    double square() const override;
    double perimeter() const override;
    double mass() const override;
    Vector2D position() const override;
    double radius() const;

    bool operator==(const IPhysObject& other) const override;
    bool operator<(const IPhysObject& other) const override;

    void draw() const override;
    void initFromDialog() override;

    const char* classname() const override;
    unsigned int size() const override;

private:
    Vector2D position_ {};
    double R_;
    double mass_;
    const char* classname_ = "Disk";
};

class IsoscelesTrapezoid : public IFigure {
public:
    IsoscelesTrapezoid();
    IsoscelesTrapezoid(Vector2D, Vector2D, Vector2D);
    ~IsoscelesTrapezoid();

    double square() const override;
    double perimeter() const override;
    double mass() const override;
    Vector2D position() const override;

    double largerParallelEdge() const;
    double smallerParallelEdge() const;
    double nonParallelEdge() const;
    double height() const;

    bool operator==(const IPhysObject& other) const override;
    bool operator<(const IPhysObject& other) const override;

    void draw() const override;
    void initFromDialog() override;

    const char* classname() const override;
    unsigned int size() const override;

private:
    Vector2D A_ {}, B_ {}, C_ {};
    double mass_ {};
    const char* classname_ = "Isosceles trapezoid";
};