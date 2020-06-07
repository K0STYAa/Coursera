#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

bool foo(std::string a, std::string b) {
    for (int i = 0; i < std::min(a.size(), b.size()); i++) {
        if (tolower(a[i]) > tolower(b[i])) {
            return false;
        } else if (tolower(a[i]) < tolower(b[i])) {
            return true;
        }
    }
    return a.size() < b.size();
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::string> v;
    for (int i = 0; i < n; i++) {
        std::string tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), foo);
    for (auto i : v) {
        std::cout << i << " ";
    }
}
