#include <iostream>
#include "funcs.h"
#include <complex>
#include <vector>
#include <string>

using namespace std;

int main() {
    float num, val;
    cout << "=== Task 2 ===" << endl;
    cout << "Enter num to increase: ";
    cin >> num;
    cout << "Enter increasing value: ";
    cin >> val;
    increase(&num, val);
    cout << "Result 1 = " << num << endl;
    increase(num, val);
    cout << "Result 2 = " << num << endl;

    cout << "=== Task 7 ===" << endl;
    cout << "Enter num to inverse: ";
    cin >> num;
    inverse(&num);
    cout << "Result 1 = " << num << endl;
    inverse(num);
    cout << "Result 2 = " << num << endl;

    cout << "=== Task 10 ===" << endl;
    float real, imagine;
    cout << "Enter real part of complex num: ";
    cin >> real;
    cout << "Enter imagine part: ";
    cin >> imagine;
    complex<float> complexNum(real, imagine);
    cout << "Number: " << complexNum.real() << " + " << complexNum.imag() << "i" << endl;
    setComplexConjugate(&complexNum);
    cout << "Result 1 = " << complexNum.real() << " + " << complexNum.imag() << "i" << endl;
    setComplexConjugate(complexNum);
    cout << "Result 1 = " << complexNum.real() << " + " << complexNum.imag() << "i" << endl;

    cout << "=== Task 15 ===" << endl;
    vector<vector<float>> matrix(3, vector<float>(3));
    cout << "Enter matrix:" << endl;
    string s;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            cout << "[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    matrixMultiplyBy3(&matrix);

    cout << "Result 1:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    matrixMultiplyBy3(matrix);

    cout << "Result 2:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}