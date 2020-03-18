#pragma once

#include <map>
#include <string>

using namespace std;

class Menu {
private:

    map<string, string> options;
    bool firstStart = true;

public:

    Menu() = default;

    Menu(map<string, string> options);

    void show();

    void show(string message);

    void show(map<string, string> options);

    void show(map<string, string> options, string message);

    vector<string> ask();

    vector<string> ask(map<string, string> options);
};



