#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

class Person {
public:
    void ChangeFirstName(int year, const std::string& first_name) {
        first_name_history[year] = first_name;
    }
    void ChangeLastName(int year, const std::string& last_name) {
        last_name_history[year] = last_name;
    }
    std::string GetFullName(int year) {
        if (first_name_history.empty() && last_name_history.empty()) {
            return "Incognito";
        } else if (first_name_history.empty()) {
            auto last_history = last_name_history.upper_bound(year);
            if(last_history != last_name_history.begin()) {
                last_history--;
            }
            if (last_history->first > year) {
                return "Incognito";
            } else {
                return last_history->second + " with unknown first name";
            }
        } else if (last_name_history.empty()) {
            auto first_history = first_name_history.upper_bound(year);
            if(first_history != first_name_history.begin()) {
                first_history--;
            }
            if (first_history->first > year) {
                return "Incognito";
            } else {
                return first_history->second + " with unknown last name";
            }
        } else {
            auto first_history = first_name_history.upper_bound(year);
            auto last_history = last_name_history.upper_bound(year);
            if(first_history != first_name_history.begin()) {
                first_history--;
            }
            if(last_history != last_name_history.begin()) {
                last_history--;
            }
            if (first_history->first > year && last_history->first > year) {
                return "Incognito";
            } else if (first_history->first > year) {
                return last_history->second + " with unknown first name";
            } else if (last_history->first > year) {
                return first_history->second + " with unknown last name";
            } else {
                return first_history->second + " " + last_history->second;
            }
        }
    }
private:
    std::map<int, std::string> first_name_history;
    std::map<int, std::string> last_name_history;
};

using namespace std;

int main(){
    Person person;

    person.ChangeFirstName(3, "3_first");
    person.ChangeFirstName(2, "2_first");

    for (int year : {1, 2, 3, 4}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
