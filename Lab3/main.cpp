#include <iostream>
#include <string>
#include "datatypes.h"

using namespace std;

int main() {
    cout << "=== Task 1 ===" << endl;
    Complex a(1, 2);
    Complex b(3, 4);
    cout << "Complex A = " << (string) a << ", complex B = " << (string) b << endl;

    cout << "Test 1. Multiply complex by real (A * 3):\t";
    cout << (string) (a * 3) << endl;

    cout << "Test 2. Sum two complex (A + B):\t\t\t";
    cout << (string) (a + b) << endl;

    cout << "Test 3. Multiply two complex (A * B):\t\t";
    cout << (string) (a * b) << endl;

    cout << "Test 4. Length of a complex ((double) A):\t";
    cout << (double) a << endl;
}