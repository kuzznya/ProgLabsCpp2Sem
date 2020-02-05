#include "funcs.h"

//task #2

void increase(float* num, float val) {
    *num += val;
}

void increase(float& num, float val) {
    num += val;
}

//task #7

void inverse(float* num) {
    *num = - *num;
}

void inverse(int* num) {
    *num = - *num;
}

void inverse(float& num) {
    num = -num;
}

void inverse(int& num) {
    num = -num;
}

//task #10

void setComplexConjugate(complex<float>* num) {
    num->imag(-num->imag());
}

void setComplexConjugate(complex<float>& num) {
    num.imag(-num.imag());
}

//task #15

void matrixMultiplyBy3(vector<vector<float>>* matrix) {
    for (vector<float>& line : *matrix) {
        for (float& element : line)
            element *= 3;
    }
}

void matrixMultiplyBy3(vector<vector<float>>& matrix) {
    for (vector<float>& line : matrix) {
        for (float& element : line)
            element *= 3;
    }
}
