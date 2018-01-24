// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>
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
    friend std::istream& operator >> (std::istream& stream, Date& date) {
        string year;
        getline(stream, year, '-');
        if (stoi(year) > 9999 || stoi(year) < 0) {
            throw "Month value is invalid: " + year;
        }
        string month;
        getline(stream, month, '-');
        if (stoi(month) > 12 || stoi(month) < 1) {
            throw "Month value is invalid: " + month;
        }

        string day;
        getline(stream, day, ' ');
        if (stoi(day) > 31 || stoi(day) < 1) {
            throw "Month value is invalid: " + day;
        }
        date.year = std::stoi(year);
        date.month = std::stoi(month);
        date.day = std::stoi(day);
        return stream;
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
    void DeleteEvent(const Date& date, const string& event) {
        map<Date, vector<string> >::iterator it = eventStorage.find(date);
        if (it != eventStorage.end()) {
            for (auto v : it->second) {
                if (v == event) {
                    //eventStorage[date][0].erase(v);
                }
            }
        }
    }
    void DeleteDate(const Date& date) {
        eventStorage.erase(date);
    }

    vector<string> Find(const Date& date) {
        map<Date, vector<string> >::iterator it = eventStorage.find(date);
        if (it != eventStorage.end()) {
            return it->second;
        }
        return {"Date not found"};
    }

    void Print() const {
        for (const auto& m : eventStorage) {
            for (int i = 0; i < m.second.size(); ++i) {
                cout << setw(4) << setfill('0') << m.first.GetYear() << "-"
                    << setw(2) << m.first.GetMonth() << "-"
                    << setw(2) << m.first.GetDay() << " " << m.second[i] << endl;
            }
        }
    }
private:
    map<Date, vector<string> > eventStorage;
};

std::string ParseString(std::string& s, const std::string& delimiter) {
    return s.substr(0, s.find(delimiter));;
}

void Print(const std::string& s) {
    std::cout << s << std::endl;
}

int DBTask () {
    try {
        Database db;

        string request;
        // Считайте команды с потока ввода и обработайте каждую
        while (getline(cin, request)) {
            istringstream iss(request);
            std::string command;
            getline(iss, command, ' ');
            if (request.empty()) {
                continue;
            }

            if (command == "Add") {
                Date date;
                iss >> date;
                std::string event;
                iss >> event;
                db.AddEvent(date, event);

#if 0
                std::cout << command << " "
                    << date.GetYear() << "-"
                    << date.GetMonth() << "-"
                    << date.GetDay() << " " << event;
#endif
            }

            if (command == "Del") {
                Date date;
                iss >> date;
                std::string event;
                iss >> event;

                if (event.empty()) {
                    db.DeleteDate(date);
                }
                else {
                    db.DeleteEvent(date, event);
                }
            }

            if (command == "Find") {
                Date date;
                iss >> date;
                db.Find(date);
            }

            if (command == "Print") {
                db.Print();
            }
            //std::cout << command;
        }
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
