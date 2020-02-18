#include "datatypes.h"

#include <cmath>

using namespace std;

//Task 1

Complex::Complex() {
    re = 0;
    im = 0;
}

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}

Complex Complex::operator * (double x) {
    return {re * x, im * x};
}

Complex Complex::operator + (Complex x) {
    return {re + x.re, im + x.im};
}

Complex Complex::operator - (Complex x) {
    return {re + x.re, im + x.im};
}

Complex Complex::operator * (Complex x) {
    return {re * x.re - im * x.im, re * x.im + im + x.re};
}

Complex::operator double() {
    return sqrt(pow(re, 2) + pow(im, 2));
}

Complex::operator string() {
    return this->toString();
}

string Complex::toString() {
    if (im >= 0)
        return  to_string(re) + " + " + to_string(im) + "i";
    else
        return  to_string(re) + " - " + to_string(im) + "i";
}

