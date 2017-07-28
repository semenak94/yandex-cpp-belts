#pragma once

#include <map>
#include <string>

using namespace std;

void PersonsTask1();

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // �������� ���� ��������� ����� �� first_name � ��� year
        firstNameHistoryChange[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // �������� ���� ��������� ������� �� last_name � ��� year
        lastNameHistoryChange[year] = last_name;
    }
    string GetFullName(int year) {
        // �������� ��� � ������� �� ��������� �� ����� ���� year
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
    // ��������� ����
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