#include <iostream>
#include <vector>
#include <list>
#include "generalgos.h"
#include "../Lab5/matrix.h"

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};



    std::cout << (algos::any_of(a.begin(), a.end(), [](int val) -> bool { return val == 9; }) ? "TRUE" : "FALSE") << std::endl;

    std::list<Matrix<int>> b = { Matrix<int>(2, 2), Matrix<int>(3, 3), Matrix<int>(4, 4) };



    std::cout << (algos::any_of(b.begin(), b.end(), [](auto val) -> bool { return val.getWidth() == 2; }) ? "TRUE" : "FALSE") << std::endl;

    std::cout << (algos::one_of(b.begin(), b.end(), [](auto val) -> bool { return val.getWidth() <= 2; }) ? "TRUE" : "FALSE") << std::endl;
    std::cout << (algos::one_of(b.begin(), b.end(), [](auto val) -> bool { return val.getWidth() <= 3; }) ? "TRUE" : "FALSE") << std::endl;

    std::cout << algos::find_not(b.begin(), b.end(), Matrix<int>(2, 2)).getWidth() << std::endl;

    return 0;
}