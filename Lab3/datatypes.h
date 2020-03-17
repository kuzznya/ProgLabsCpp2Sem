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

    Complex operator * (double x) const;

    Complex operator + (Complex x) const;

    Complex operator - (Complex x) const;

    Complex operator * (Complex x) const;

    explicit operator double() const;

    explicit operator std::string() const;

    std::string toString() const;
};

//Task 6
class IntArray {
private:
    int* array;
    int size;

public:
    IntArray();

    explicit IntArray(int size);

    IntArray(IntArray const &prevArray);

    ~IntArray();

    int getSize() const;

    void push_back(int value);

    void resize(int newSize);

    int& operator [] (int idx);

    IntArray operator + (IntArray array2);

    bool operator == (const IntArray& array2);

    bool operator > (const IntArray& array2);

    bool operator < (const IntArray& array2);

    bool operator != (const IntArray& array2);

    explicit operator std::string();
};

