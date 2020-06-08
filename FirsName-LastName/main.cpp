#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

std::string FindNameByYear(const std::map<int, std::string>& names, int year) {
    std::string name;
    for (const auto& item : names) {
        if (item.first <= year) {
            name = item.second;
        } else {
            break;
        }
    }
    return name;
}

std::vector<std::string> HistoryNameByYear(const std::map<int, std::string>& names, int year) {
    std::vector<std::string> res;
    for (const auto& item : names) {
        if (item.first <= year) {
            if(res.size() == 0 || *res.rbegin() != item.second) {
                res.push_back(item.second);
            }
        } else {
            break;
        }
    }
    return res;
}

std::string modif(std::vector<std::string> v) {
    std::string res;
    if (v.size() == 1) {
        res = v[0];
    } else {
        auto iter = v.rbegin();
        res = *iter++ + " (";
        res += *iter;
        while (++iter != v.rend()) {
            res += ", " + *iter;
        }
        res += ")";
    }
    return res;
}

class Person {

public:

    Person(const std::string &s1, const std::string &s2, const int &n) {birthday = n; first_names[n] = s1; last_names[n] = s2;}

    void ChangeFirstName(int year, const std::string& first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const std::string& last_name) {
        last_names[year] = last_name;
    }

    std::string GetFullName(int year) const {
        if(year < birthday) {
            return "No person";
        }
        const std::string first_name = FindNameByYear(first_names, year);
        const std::string last_name = FindNameByYear(last_names, year);
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";
        } else {
            return first_name + " " + last_name;
        }
    }

    std::string GetFullNameWithHistory(int year) const {
        if(year < birthday) {
            return "No person";
        }
        const std::vector<std::string> first_name_history = HistoryNameByYear(first_names, year);
        const std::vector<std::string> last_name_history = HistoryNameByYear(last_names, year);
        if (first_name_history.empty() && last_name_history.empty()) {
            return "Incognito";
        } else if (first_name_history.empty()) {
            return modif(last_name_history) + " with unknown first name";
        } else if (last_name_history.empty()) {
            return modif(first_name_history) + " with unknown last name";
        } else {
            return modif(first_name_history) + " " + modif(last_name_history);
        }
    }

private:

    std::map<int, std::string> first_names;
    std::map<int, std::string> last_names;
    int birthday;
};