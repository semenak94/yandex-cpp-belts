#pragma once

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        // �������� ������ s � �����
        sortedStorage.push_back(s);
        sort(begin(sortedStorage), end(sortedStorage));
    }
    vector<string> GetSortedStrings() {
        // �������� ����� �� ���� ����������� ����� � ��������������� �������
        return sortedStorage;
    }
private:
    // ��������� ����
    vector<string> sortedStorage;
};

void SortedStringsTask();