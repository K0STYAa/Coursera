#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

int main() {
    std::map<std::set<std::string>, int> v; // v : stops -> number
    int n, number = 0;
    std::string s;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        std::set<std::string> m;
        std::cin >> k;
        for(int j = 0; j < k; j++) {
            std::cin >> s;
            m.insert(s);
        }
        if (!v[m]) {
            std::cout << "New bus " << (v[m] = ++number) << std::endl;
        } else {
            std::cout << "Already exists for " << v[m] << std::endl;
        }
        m.empty();
    }
    return 0;
}
