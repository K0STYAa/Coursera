#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>

struct Week {
    explicit Week(std::string new_value) {value = new_value;}
    std::string value;
};

struct Course {
    explicit Course(std::string new_value) {value = new_value;}
    std::string value;
};

struct  Specialization {
    explicit Specialization(std::string new_value) {value = new_value;}
    std::string value;
};

struct LectureTitle {
    LectureTitle (Specialization s, Course c, Week w) {specialization = s.value; course = c.value; week = w.value;}
    std::string specialization;
    std::string course;
    std::string week;
};