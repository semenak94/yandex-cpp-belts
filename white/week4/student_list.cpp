#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    string name;
    string surname;
    Date date;
    string GetDate() {
        return to_string(date.day) + "." + to_string(date.month) + "." + to_string(date.year);
    }
};

void ReadStudent(Student& student) {
    string name;
    cin >> name;
    string surname;
    cin >> surname;
    string day;
    cin >> day;
    string month;
    cin >> month;
    string year;
    cin >> year;
    student = { name, surname, {stoi(day), stoi(month), stoi(year)} };
}

void StudentListTask() {
    vector<Student> studentList;
    vector<string> log;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        Student student;
        ReadStudent(student);
        studentList.push_back(student);
    }

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string request;
        cin >> request;

        if (request == "name") {
            int value;
            cin >> value;
            if (value > 0 && value <= N) {
                log.push_back(studentList[value - 1].name + " " + studentList[value - 1].surname);
            }
        }
        else if (request == "date") {
            int value;
            cin >> value;
            if (value > 0 && value <= N) {
                log.push_back(studentList[value - 1].GetDate());
            }
        }
        else {
            log.push_back("bad request");
        }
    }

    for (auto s : log) {
        cout << s << endl;
    }
}
