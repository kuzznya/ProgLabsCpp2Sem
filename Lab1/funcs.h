#pragma once
#include <complex>
#include <vector>

using namespace std;

//task #2
void increase(float* num, float val);
void increase(float& num, float val);

//task #7
void inverse(float* num);
void inverse(int* num);
void inverse(float& num);
void inverse(int& num);

//task #10
void setComplexConjugate(complex<float>* num);
void setComplexConjugate(complex<float>& num);

//task #15
void matrixMultiplyBy3(vector<vector<float>>* matrix);
void matrixMultiplyBy3(vector<vector<float>>& matrix);
