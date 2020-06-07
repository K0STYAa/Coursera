#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

bool foo(int a, int b) { return abs(a) < abs(b); }

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), foo);
    for (auto i : v) {
        std::cout << i << " ";
    }
}
