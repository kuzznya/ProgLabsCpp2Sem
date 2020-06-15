#pragma once

#include <exception>
#include <memory>

using uchar = unsigned char;
using uint = unsigned int;

enum Color {
    WHITE,
    RED,
    ORANGE,
    BLUE,
    GREEN,
    YELLOW,
    BLACK
};

class InvalidColorException : std::exception {
    const char* what() const noexcept override {
        return "Invalid color char\n";
    }
};

uint getColorValue(Color color);

std::shared_ptr<uchar> getColorRGB(Color color);

Color getColorByLetter(uchar letter);

char getColorLetter(Color color);
