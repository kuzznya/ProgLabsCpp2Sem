#include "FileStream.h"

FileStream::FileStream() {
    name = "";
}

FileStream::FileStream(string name) {
    open(name);
}

FileStream::~FileStream(){
    if (inputf.is_open())
        inputf.close();
}

bool FileStream::open() {
    return open(name);
}

bool FileStream::open(string name) {
    if (inputf.is_open())
        inputf.close();
    inputf.open(name);
    this->name = name;
    return inputf.is_open();
}

bool FileStream::close() {
    if (inputf.is_open()) {
        inputf.close();
        return true;
    }
    return false;
}

string FileStream::getName() {
    return name;
}

bool FileStream::isOpened() {
    return inputf.is_open();
}

string FileStream::readString() {
    string s;
    getline(inputf, s);
    return s;
}

string FileStream::readWord() {
    string s;
    inputf >> s;
    return s;
}

bool FileStream::eof() {
    return inputf.eof();
}
