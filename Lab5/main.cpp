#include <iostream>
#include "swap.h"
#include "matrix.h"

template <class T>
void printMatrix(Matrix<T>& x) {
    for (int i = 0; i < x.getHeight(); i++) {
        for (int j = 0; j < x.getWidth(); j++)
            std::cout << x.get(i, j) << " ";
        std::cout << std::endl;
    }
}

int main() {
    int a = 3, b = 5;
    swap<int>(a, b);
    std::cout << a << b << std::endl;

    Matrix<int> x(3, 3);

    x.get(0, 1) = 1;
    x.get(0, 2) = 2;
    x.get(1, 0) = 3;
    x.get(1, 1) = 4;

    printMatrix(x);

    x.resize(2, 2);

    printMatrix(x);

    try {
        x.get(5, 5);
    } catch (MatrixException& ex) {
        std::cout << ex.what();
    }

}