#include <iostream>
#include <string>
#include "datatypes.h"

using namespace std;

int main() {
    cout << "=== Task 1 ===" << endl;
    Complex a(1, 2);
    Complex b(3, 4);
    cout << "Complex A = " << (string) a << "\nComplex B = " << (string) b << endl;

    cout << "Test 1. Multiply complex by real (A * 3):\t";
    cout << (string) (a * 3) << endl;

    cout << "Test 2. Sum two complex (A + B):\t\t\t";
    cout << (string) (a + b) << endl;

    cout << "Test 3. Multiply two complex (A * B):\t\t";
    cout << (string) (a * b) << endl;

    cout << "Test 4. Length of a complex ((double) A):\t";
    cout << (double) a << endl;

    cout << endl << "=== Task 6 ===" << endl;
    IntArray array1(5);
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;
    array1[3] = 4;
    array1[4] = 5;
    IntArray array2(5);
    array2[0] = 6;
    array2[1] = 7;
    array2[2] = 8;
    array2[3] = 9;

    cout << "Array 1 is " << (string) array1 << ", array 2 is " << (string) array2 << endl;

    IntArray result = array1 + array2;

    cout << "Array 1 + array 2 is " << (string) result << endl;

    result.push_back(45);

    cout << "Push back 45: " << (string) result << endl;

    cout << "Array 1 == array 2? ";
    if (array1 == array2)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "Array 1 < result? ";
    if (array1 < result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    result.resize(5);
    cout << "Resized array: " << (string) result << endl;

    cout << "Array 1 < result? ";
    if (array1 < result)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}