#pragma once

#include "matrix_exceptions.h"
#include <algorithm>
#include <ostream>

template <class T>
class Matrix {

private:
    T* data;
    unsigned n, m;

public:
    Matrix() : n(0), m(0), data(nullptr) {}

    Matrix(unsigned n, unsigned m) : n(n), m(m) {
        data = new T[n * m];
    }

    Matrix(const Matrix<T>& other) : n(other.n), m(other.m) {
        data = new T[n * m];
        for (int i = 0; i < n * m; i++)
            data[i] = other.data[i];
    }

    ~Matrix() {
        if (data != nullptr)
            delete[] data;
    }

    const bool operator == (const Matrix& other) const {
        if (n != other.n || m != other.m)
            return false;
        for (int i = 0; i < n * m; i++)
            if (data[i] != other.data[i])
                return false;
        return true;
    }

    const bool operator != (const Matrix& other) const {
        return !(*this == other);
    }

    T& get(int i, int j) {
        if (i >= n || j >= m || i < 0 || j < 0)
            throw IndexOutOfBoundsException();
        return data[i * n + j];
    }

    void set(int i, int j, T value) {
        if (i >= n || j >= m || i < 0 || j < 0)
            throw IndexOutOfBoundsException();
        data[i * n + j] = value;
    }

    void resize(unsigned newN, unsigned newM) {
        T* newData = new T[newN * newM];
        for (int i = 0; i < std::min(n, newN); i++) {
            for (int j = 0; j < std::min(m, newM); j++)
                newData[i * newN + j] = data[i * n + j];
        }
        delete[] data;
        data = newData;
        n = newN;
        m = newM;
    }

    unsigned getHeight() {
        return n;
    }

    unsigned getWidth() {
        return m;
    }
};