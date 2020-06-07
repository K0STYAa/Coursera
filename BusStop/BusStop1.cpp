#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

std::map<std::string, std::vector<std::string>> v1, v2;
// v1 : stop -> bus
// v2 : bus -> stop

int main() {
    int n;
    std::string s;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> s;
        if(s == "NEW_BUS") {
            int k;
            std::string s_bus, s_stop;
            std::cin >> s_bus >> k;
            for(int j = 0; j < k; j++) {
                std::cin >> s_stop;
                v1[s_stop].push_back(s_bus);
                v2[s_bus].push_back(s_stop);
            }
        } else if (s == "BUSES_FOR_STOP") {
            std::string s_stop;
            std::cin >> s_stop;
            if(v1[s_stop].empty()) {
                std::cout << "No stop" << std::endl;
                v1.erase(s_stop);
            } else {
                for(auto j : v1[s_stop]){
                    std::cout << j << " ";
                }
                std::cout << std::endl;
            }
        } else if (s == "STOPS_FOR_BUS") {
            std::string s_bus;
            std::cin >> s_bus;
            if (v2[s_bus].empty()) {
                std::cout << "No bus" << std::endl;
                v2.erase(s_bus);
            } else {
                for (auto j : v2[s_bus]) {
                    std::cout << "Stop " << j << ":";
                    if (v1[j].size() == 1) {
                        std::cout << " no interchange";
                    } else {
                        for (auto k : v1[j]) {
                            if (k != s_bus) {
                                std::cout << " " << k;
                            }
                        }
                    }
                    std::cout << std::endl;
                }
            }
        } else {
            if(v2.empty()) {
                std::cout << "No buses" << std::endl;
            } else {
                for (auto j : v2) {
                    std::cout << "Bus " << j.first << ":";
                    for (auto k : j.second) {
                        std::cout << " " << k;
                    }
                    std::cout << std::endl;
                }
            }
        }
    }
    return 0;
}
