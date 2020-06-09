#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
#include <exception>
#include <stdexcept>

void foo2(std::ifstream &input) {
    int number;
    input >> number;
    input.ignore(1);
    std::cout << std::setw(10) << number;
}

void foo1(std::ifstream &input, int &m) {
    for (int j = 0; j < m - 1; j++) {
        foo2(input);
        std::cout << " ";
    }
    foo2(input);
}

int main() {
    std::ifstream input("input.txt");
    int n, m;
    input >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        foo1(input, m);
        std::cout << std::endl;
    }
    foo1(input, m);
    return 0;
}