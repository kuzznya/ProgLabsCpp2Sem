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
    YELLOW
};

class InvalidColorException : std::exception {
    const char* what() const noexcept override {
        return "Invalid color char\n";
    }
};

uint getColorValue(Color color) {
    switch (color) {
        case WHITE:
            return 0xFFFFFF;
        case RED:
            return 0xFF0000;
        case ORANGE:
            return 0xFF8000;
        case BLUE:
            return 0x0000FF;
        case GREEN:
            return 0x00FF00;
        case YELLOW:
            return 0xFFFF00;
    }
}

std::shared_ptr<uchar> getColorRGB(Color color) {
    uint value = getColorValue(color);
    return std::shared_ptr<uchar>(new uchar[3]
    {
        static_cast<uchar>(value >> 16),
        static_cast<uchar>(value >> 8),
        static_cast<uchar>(value)
    });
}

Color getColorByLetter(uchar letter) {
    switch (letter) {
        case 'w':
            return Color::WHITE;
        case 'r':
            return Color::RED;
        case 'o':
            return Color::ORANGE;
        case 'b':
            return Color::BLUE;
        case 'g':
            return Color::GREEN;
        case 'y':
            return Color::YELLOW;
        default:
            throw InvalidColorException();
    }
}

char getColorLetter(Color color) {
    switch (color) {
        case WHITE:
            return 'w';
        case RED:
            return 'r';
        case ORANGE:
            return 'o';
        case BLUE:
            return 'b';
        case GREEN:
            return 'g';
        case YELLOW:
            return 'y';
    }
}
