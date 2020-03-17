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

Complex Complex::operator * (double x) const {
    return {re * x, im * x};
}

Complex Complex::operator + (Complex x) const {
    return {re + x.re, im + x.im};
}

Complex Complex::operator - (Complex x) const {
    return {re + x.re, im + x.im};
}

Complex Complex::operator * (Complex x) const {
    return {re * x.re - im * x.im, re * x.im + im + x.re};
}

Complex::operator double() const {
    return sqrt(pow(re, 2) + pow(im, 2));
}

Complex::operator std::string() const {
    return this->toString();
}

string Complex::toString() const {
    if (im >= 0)
        return  to_string(re) + " + " + to_string(im) + "i";
    else
        return  to_string(re) + " - " + to_string(im) + "i";
}


//Task 6

IntArray::IntArray() {
    size = 0;
}

IntArray::IntArray(int size) {
    this->size = size;
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

IntArray::IntArray(IntArray const &prevArray) {
    size = prevArray.getSize();
    array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = prevArray.array[i];
    }
}

IntArray::~IntArray() {
    delete[] array;
}

int IntArray::getSize() const {
    return size;
}

void IntArray::push_back(int value) {
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    newArray[size] = value;
    delete[] array;
    array = newArray;
    size++;
}

void IntArray::resize(int newSize) {
    int* newArray = new int[newSize];
    int minSize = newSize > size ? size : newSize;
    for (int i = 0; i < minSize; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    size = newSize;
}

int& IntArray::operator [] (int idx) {
    if (idx < size && idx >= 0)
        return array[idx];
    else
        throw out_of_range("Out of range");
}

IntArray IntArray::operator + (IntArray array2) {
    if (size + array2.getSize() > 100)
        throw out_of_range("Array length cannot be more than 100");
    IntArray newArray(size + array2.getSize());
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    for (int i = 0; i < array2.getSize(); i++) {
        newArray[i + size] = array2[i];
    }
    return IntArray(newArray);
}

bool IntArray::operator==(const IntArray &array2) {
    return size == array2.getSize();
}

bool IntArray::operator>(const IntArray &array2) {
    return size > array2.getSize();
}

bool IntArray::operator<(const IntArray &array2) {
    return size < array2.getSize();
}

bool IntArray::operator!=(const IntArray &array2) {
    return size != array2.getSize();
}

IntArray::operator std::string() {
    string result = "[";
    for (int i = 0; i < size - 1; i++) {
        result += to_string(array[i]) + ", ";
    }
    result += to_string(array[size - 1]) + "]";
    return result;
}
