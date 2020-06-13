#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <exception>
#include <iomanip>

const std::vector<int> DayInMonth {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
    int y, m, d;
public:
    int GetYear() const {
        return y;
    }
    int GetMonth() const {
        return m;
    }
    int GetDay() const {
        return d;
    }
    void ReadDate(std::istream &stream) {
        std::string date_new;
        stream >> date_new;
        std::istringstream new_stream(date_new);
        if((new_stream.peek() < '0' || new_stream.peek() >  '9') && new_stream.peek() != '-' && new_stream.peek() != '+') {
            throw std::invalid_argument("Wrong date format: " + date_new);
        }
        if (!(new_stream >> this->y)) {
            throw std::invalid_argument("Wrong date format: " + date_new);
        }
        if(new_stream.peek() != '-') {
            throw std::invalid_argument("Wrong date format: " + date_new);
        }
        new_stream.ignore(1);
        if((new_stream.peek() < '0' || new_stream.peek() >  '9') && new_stream.peek() != '-' && new_stream.peek() != '+') {
            throw std::invalid_argument("Wrong date format: " + date_new);
        }
        if (!(new_stream >> this->m)) {
            throw std::invalid_argument("Wrong date format: " + date_new);
        }
        if(new_stream.peek() != '-') {
            throw std::invalid_argument("Wrong date format: " + date_new);
        }
        new_stream.ignore(1);
        if((new_stream.peek() < '0' || new_stream.peek() >  '9') && new_stream.peek() != '-' && new_stream.peek() != '+') {
            throw std::invalid_argument("Wrong date format: " + date_new);
        }
        if (!(new_stream >> this->d)) {
            throw std::invalid_argument("Wrong date format: " + date_new);
        }
        char c = new_stream.peek();
        if(c != -1) {
            throw std::invalid_argument("Wrong date format: " + date_new);
        }
        if (this->GetMonth() > 12 || this->GetMonth() < 1) {
            throw std::invalid_argument("Month value is invalid: " + std::to_string(this->GetMonth()));
        }
        if (this->GetDay() > DayInMonth[this->GetMonth() - 1] || this->GetDay() < 1) {
            throw std::invalid_argument("Day value is invalid: " + std::to_string(this->GetDay()));
        }
    }
};

bool operator<(const Date& lhs, const Date& rhs) {
    if(lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    } else if(lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

class Database {

    std::map<Date, std::set<std::string>> v;

public:

    void AddEvent(const Date &date, const std::string &s) {
        v[date].insert(s);
    }

    int DeleteDate(const Date &date) {
        int size = v[date].size();
        v.erase(date);
        return size;
    }

    bool DeleteEvent(const Date &date, const std::string &s) {
        for(auto i : v[date]) {
            if(i == s) {
                v[date].erase(s);
                return true;
            }
        }
        return false;
    }

    void print() const {
        for(auto i : v) {
            for(auto j : i.second) {
                std::cout << std::setfill('0');
                std::cout << std::setw(4) << i.first.GetYear() << "-" << std::setw(2) <<
                i.first.GetMonth() << "-" << std::setw(2) << i.first.GetDay() << " " << j << std::endl;
            }
        }
    }

    void Find(const Date& date) const {
        if(v.find(date) != v.end()) {
            for (auto i : v.at(date)) {
                std::cout << i << std::endl;
            }
        }
    }

};

std::string GetEvent(std::istream &stream) {
    std::string s;
    stream.ignore(1);
    getline(stream, s);
    return s;
}

int main() {
    Database db;

    std::string command;
    try {
        while (std::cin >> command) {
            if (command == "Add") {
                Date d;
                d.ReadDate(std::cin);
                std::string s = GetEvent(std::cin);
                db.AddEvent(d, s);
            } else if (command == "Del") {
                Date d;
                d.ReadDate(std::cin);
                if(std::cin.peek() == '\n') {
                    int count = db.DeleteDate(d);
                    std::cout << "Deleted " << count << " events\n";
                } else  {
                    std::string s = GetEvent(std::cin);
                    bool t = db.DeleteEvent(d, s);
                     if(t) {
                         std::cout << "Deleted successfully\n";
                     } else {
                         std::cout << "Event not found\n";
                     }
                }
            } else if (command == "Print") {
                db.print();
            } else if (command == "Find") {
                Date d;
                d.ReadDate(std::cin);
                db.Find(d);
                getline(std::cin, command);
            } else {
                throw std::invalid_argument("Unknown command: " + command);
            }
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}