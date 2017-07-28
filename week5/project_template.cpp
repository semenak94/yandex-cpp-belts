// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

class Date {
public:
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        return (lhs.GetMonth() == rhs.GetMonth() ?
                lhs.GetDay() < rhs.GetDay() :
                lhs.GetMonth() < rhs.GetMonth());
    }
    return (lhs.GetYear() < rhs.GetYear());
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        eventStorage[date].push_back(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        map<Date, vector<string> >::iterator it = eventStorage.find(date);
        if (it != eventStorage.end()) {
            for (auto v : it->second) {
                if (v == event) {
                    //(it->second).erase(v);
                }
            }
        }
    }
    int  DeleteDate(const Date& date) {
    }

    void Find(const Date& date) const {
        if (eventStorage.find(date) != eventStorage.end()) {

        }
    }

    void Print() const {
        for (const auto& m : eventStorage) {
            for (int i = 0; i < m.second.size(); ++i) {
                cout << setw(4) << m.first.GetYear() << "-"
                    << setw(2) << m.first.GetMonth() << "-"
                    << setw(2) << m.first.GetDay() << " " << m.second[i] << endl;
            }
        }
    }
private:
    map<Date, vector<string> > eventStorage;
};

int DBTask () {
    Database db;

    string request;
    while (getline(cin, request)) {
      // Считайте команды с потока ввода и обработайте каждую
        std::string delimiter = " ";
        size_t pos = 0;
        std::string command = request.substr(0, request.find(delimiter));
        request.erase(0, pos + delimiter.length());
        std::string date = request.substr(0, request.find(delimiter));
        request.erase(0, pos + delimiter.length());
        std::cout << command;
    }

    return 0;
}
