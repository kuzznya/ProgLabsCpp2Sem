#pragma once

#include <exception>

class buffer_underflow_exception : public std::exception {
    const char* what() const _NOEXCEPT override {
        return "Buffer underflow";
    }
};

class index_out_of_bounds_exception : public std::exception {
    const char* what() const _NOEXCEPT override {
        return "Index out of bounds";
    }
};
