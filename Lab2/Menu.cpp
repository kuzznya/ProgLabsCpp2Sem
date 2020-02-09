#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Menu::Menu(map<string, string> options) {
    this->options = options;
}

void Menu::show() {
    cout << string( 100, '\n' );
    cout << "=== MENU ===" << endl;
    cout << "Commands:" << endl;
    for (auto &el : options) {
        cout << "* " << el.first << endl;
        cout << el.second << endl;
    }
    cout << "Type command" << endl;
    cout << "Add arguments if needed (see info about each command)" << endl;
}

void Menu::show(map<string, string> options) {
    this->options = options;
    show();
}

vector<string> Menu::ask() {
    if (firstStart) {
        show();
        firstStart = false;
    }
    while (true) {
        vector<string> answer(1);
        cin >> answer[0];

        string s;
        if (options.find(answer[0]) != options.end()) {
            while (cin.peek() != '\n') {
                cin >> s;
                answer.push_back(s);
            }
            return answer;
        }
        else {
            cout << "Error: no such command\nPlease retry" << endl;
        }
    }
}

vector<string> Menu::ask(map<string, string> options) {
    this->options = options;
    show();
    return ask();
}