#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

std::map<std::string, std::vector<std::string>> v;

int main() {
    int n;
    std::string s;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::string s1, s2;
        std::cin >> s;
        if (s == "ADD") {
            std::cin >> s1 >> s2;
            bool tmp = false;
            for(auto j : v[s1]){
                if(j == s2){
                    tmp = true;
                    break;
                }
            }
            if (!tmp){
                v[s1].push_back(s2);
                v[s2].push_back(s1);
            }
        } else if (s == "COUNT") {
            std::cin >> s1;
            std::cout << v[s1].size() << std::endl;
        } else if (s == "CHECK") {
            std::cin >> s1 >> s2;
            bool tmp = false;
            for(auto j : v[s1]){
                if(j == s2){
                    tmp = true;
                    break;
                }
            }
            if (tmp) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}