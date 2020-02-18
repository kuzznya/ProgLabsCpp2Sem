#pragma once

#include <string>

using namespace std;

//Task 1
class Complex {
private:
    double re;
    double im;
public:
    Complex();

    Complex(double re, double im);

    Complex operator * (double x);

    Complex operator + (Complex x);

    Complex operator - (Complex x);

    Complex operator * (Complex x);

    explicit operator double();

    explicit operator string();

    std::string toString();
};

