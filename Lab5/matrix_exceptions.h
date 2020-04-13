#pragma once

#include <exception>

class MatrixException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Matrix exception\n";
    }
};

class IndexOutOfBoundsException : public MatrixException {
public:
    const char* what() const noexcept override {
        return "Index is out of bounds\n";
    }
};