#pragma once

#include <string>
using namespace std;

void LectureTitleTask();

struct Specialization {
    string value;
    Specialization(const string& s) {
        value = s;
    }
};

struct Course {
    string value;
    Course(const string& s) {
        value = s;
    }
};

struct Week {
    string value;
    Week(const string& s) {
        value = s;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    explicit LectureTitle(const Specialization& s, const Course& c, const Week& w) {
        specialization = s.value;
        course = c.value;
        week = w.value;
    }
};
