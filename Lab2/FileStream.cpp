#include "FileStream.h"

FileStream::FileStream() {
    name = "";
}

FileStream::FileStream(string name) {
    this->name = name;
    inputf.open(name);
}

FileStream::~FileStream(){
    if (inputf.is_open())
        inputf.close();
}

void FileStream::open(string name) {
    if (inputf.is_open())
        inputf.close();
    inputf.open(name);
    this->name = name;
}

void FileStream::close() {
    if (inputf.is_open())
        inputf.close();
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
