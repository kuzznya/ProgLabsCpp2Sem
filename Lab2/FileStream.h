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

    void open();

    void open(string name);

    void close();

    string getName();

    bool isOpened();

    string readString();

    string readWord();

    bool eof();

};



