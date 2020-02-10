#include <iostream>
#include <map>
#include <vector>
#include "FileStream.h"
#include "Menu.h"

using namespace std;

int main() {
    map<string, string> options{make_pair("open", "<file name> - open specific file"),
                                make_pair("exit", "Exit the program"),
                                make_pair("menu", "Show menu")};
    Menu menu(options);
    FileStream fs;
    while (true) {
        vector<string> answer = menu.ask();
        if (answer[0] == "exit") {
            fs.close();
            cout << "Hasta la vista, baby" << endl;
            return 0;
        }
        else if (answer[0] == "open") {
            if (answer.size() <= 1) {
                cout << "No <file name> argument" << endl;
                continue;
            }
            if (fs.open(answer[1])) {
                options = {make_pair("close", "Close file, opened previously"),
                           make_pair("read_str", "Read string from an opened file"),
                           make_pair("read_word", "Read word from an opened file"),
                           make_pair("exit", "Exit the program"),
                           make_pair("menu", "Show menu")};
                menu.show(options);
            }
            else {
                menu.show("Error while trying to open");
            }
        }
        else if (answer[0] == "close") {
            fs.close();
            options = {make_pair("open", "<file name> - open specific file"),
                    make_pair("exit", "Exit the program"),
                    make_pair("menu", "Show menu")};
            menu.show(options);
        }
        else if (answer[0] == "read_str") {
            cout << fs.readString() << endl;
        }
        else if (answer[0] == "read_word") {
            cout << fs.readWord() << endl;
        }
        else if (answer[0] == "menu") {
            menu.show();
        }
    }
    return 0;
}