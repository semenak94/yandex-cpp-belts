#pragma once

#include <map>
#include <string>

using namespace std;

void PersonsTask1();

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        firstNameHistoryChange[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        lastNameHistoryChange[year] = last_name;
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        map<int, string>::iterator it_first = firstNameHistoryChange.find(year);
        map<int, string>::iterator it_last = lastNameHistoryChange.find(year);
        if (it_first == firstNameHistoryChange.end() &&
            it_last == lastNameHistoryChange.end()) {
            return "Incognito";
        }
        else if (NameHasChanged(lastNameHistoryChange, year)) {
            return it_last->second + " with unknown first name";
        }
        else if (NameHasChanged(firstNameHistoryChange, year)) {
            return it_first->second + " with unknown last name";
        }
        return it_first->second + " " + it_last->second;
    }
private:
    // приватные поля
    map<int, string> firstNameHistoryChange;
    map<int, string> lastNameHistoryChange;
    bool NameHasChanged(map<int, string>& m, int year) {
        map<int, string>::iterator it = m.find(year);
        if (it != m.end()) {
            return true;
        }

        return false;
    }

};