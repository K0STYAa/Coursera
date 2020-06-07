#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

std::map<std::string, int> v;
// v : stops -> number

int main() {
    int n, number = 0;
    std::string s;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        std::string res, s_new;
        std::cin >> k;
        for(int j = 0; j < k; j++) {
            std::cin >> s_new;
            res += " ";
            res += s_new;
        }
        if (!v[res]) {
            std::cout << "New bus " << (v[res] = ++number) << std::endl;
        } else {
            std::cout << "Already exists for " << v[res] << std::endl;
        }
    }
    return 0;
}
