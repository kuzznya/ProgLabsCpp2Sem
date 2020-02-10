#pragma once
#include <fstream>
#include <string>
#include <memory>

using namespace std;

class FileStream {
private:
    string name;
    ifstream inputf;
public:
    FileStream();

    explicit FileStream(string name);

    ~FileStream();

    bool open();

    bool open(string name);

    bool close();

    string getName();

    bool isOpened();

    string readString();

    string readWord();

    bool eof();

};



