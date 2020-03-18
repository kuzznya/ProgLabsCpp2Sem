#include "figures.h"

#include <cmath>
#include <iostream>

Disk::Disk() {
    mass_ = 0;
    R_ = 0;
}

Disk::Disk(Vector2D position, double radius, double mass)
    :position_(position), R_(radius), mass_(mass) {}

Disk::~Disk() = default;

double Disk::square() const {
    return M_PI * R_ * R_;
}

double Disk::perimeter() const {
    return 2 * M_PI * R_;
}

double Disk::mass() const {
    return mass_;
}

Vector2D Disk::position() const {
    return position_;
}

double Disk::radius() const {
    return R_;
}

bool Disk::operator==(const IPhysObject &other) const {
    return mass_ == other.mass();
}

bool Disk::operator<(const IPhysObject &other) const {
    return mass_ < other.mass();
}

void Disk::draw() const {
    std::cout << "=== " << classname_ << " ===" << std::endl;
    std::cout << "Center position: (" << position_.x << ", " << position_.y << ")" << std::endl;
    std::cout << "Radius: " << R_ << std::endl;
    std::cout << "Mass: " << mass_ << std::endl;
}

void Disk::initFromDialog() {
    std::cout << "Initialization of the " << classname_ << " started" << std::endl;
    std::cout << "Enter position of the center of the disk (x, y): ";
    std::cin >> position_.x >> position_.y;
    std::cout << "Enter radius: ";
    std::cin >> R_;
    std::cout << "Enter mass: ";
    std::cin >> mass_;
    std::cout << "Initialization completed" << std::endl;
}

const char *Disk::classname() const {
    return classname_;
}

unsigned int Disk::size() const {
    return sizeof(*this);
}

IsoscelesTrapezoid::IsoscelesTrapezoid() = default;

IsoscelesTrapezoid::IsoscelesTrapezoid(Vector2D A, Vector2D B, Vector2D C, Vector2D D)
    :A_(A), B_(B), C_(C), D_(D) {}

IsoscelesTrapezoid::~IsoscelesTrapezoid() = default;

double IsoscelesTrapezoid::square() const {
    return (largerParallelEdge() + smallerParallelEdge()) / 2.0 * height();
}

double IsoscelesTrapezoid::height() const {
    return sqrt(pow(nonParallelEdge(), 2) + pow(largerParallelEdge() - smallerParallelEdge(), 2));
}

double IsoscelesTrapezoid::perimeter() const {
    return largerParallelEdge() + smallerParallelEdge() + nonParallelEdge() * 2;
}

double IsoscelesTrapezoid::mass() const {
    return mass_;
}

Vector2D IsoscelesTrapezoid::position() const {
    return {(A_.x + B_.x + C_.x + D_.x) / 4.0, (A_.y + B_.y + C_.y + D_.y) / 4.0};
}

double IsoscelesTrapezoid::largerParallelEdge() const {
    return sqrt(pow(B_.x - A_.x, 2) + pow(B_.y - A_.y, 2));
}

double IsoscelesTrapezoid::smallerParallelEdge() const {
    return sqrt(pow(D_.x - C_.x, 2) + pow(D_.y - C_.y, 2));;
}

double IsoscelesTrapezoid::nonParallelEdge() const {
    return sqrt(pow(B_.x - A_.x, 2) + pow(B_.y - A_.y, 2));
}

bool IsoscelesTrapezoid::operator==(const IPhysObject &other) const {
    return mass_ == other.mass();
}

bool IsoscelesTrapezoid::operator<(const IPhysObject &other) const {
    return mass_ < other.mass();
}

void IsoscelesTrapezoid::draw() const {
    std::cout << "=== " << classname_ << " ===" << std::endl;
    std::cout << "Left lower corner position (x, y): (" << A_.x << ", " << A_.y << ")" << std::endl;
    std::cout << "Mass is: " << mass_ << std::endl;
}

void IsoscelesTrapezoid::initFromDialog() {
    std::cout << "Initialization of the " << classname_ << " started" << std::endl;
    std::cout << "Enter left lower point (x, y): ";
    std::cin >> A_.x >> A_.y;
    std::cout << "Enter right lower point (x, y): ";
    std::cin >> B_.x >> B_.y;
    std::cout << "Enter left upper point (x, y): ";
    std::cin >> C_.x >> C_.y;
    std::cout << "Enter right upper point (x, y): ";
    std::cin >> D_.x >> D_.y;
    std::cout << "Initialization completed" << std::endl;
}

const char *IsoscelesTrapezoid::classname() const {
    return classname_;
}

unsigned int IsoscelesTrapezoid::size() const {
    return sizeof(*this);
}

IFigure *FigureFactory::createFigure(FigureFactory::Figures fig) {
    if (fig == DiskFigure) {
        Disk* disk = new Disk();
        disk->initFromDialog();
        return disk;
    } else if (fig == IsoscelesTrapezoidFigure) {
        IsoscelesTrapezoid* trap = new IsoscelesTrapezoid();
        trap->initFromDialog();
        return trap;
    }
    return nullptr;
}
