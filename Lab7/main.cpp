#include <iostream>
#include "circular_buffer.h"

int main() {
    unsigned capacity, cur_size;
    std::cin >> capacity >> cur_size;
    circular_buffer<int> buffer(capacity);
    for (int i = 0; i < cur_size; i++) {
        int value;
        std::cin >> value;
        buffer.push_front(value);
//        std::cin >> buffer;
        buffer.print_all();
    }

    buffer.push_back(100);
    buffer.print_all();

//    buffer.pop_back();
//    buffer.print_all();
//    buffer.pop_front();
//    buffer.print_all();

    buffer.resize(20);
    buffer.print_all();

    for (int & it : buffer) {
        std::cout << it << std::endl;
    }

    std::sort(buffer.begin(), buffer.end());
    buffer.print_all();

    std::cout << *std::find(buffer.begin(), buffer.end(), 5) << std::endl;
}