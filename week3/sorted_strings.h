#pragma once

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        // добавить строку s в набор
        sortedStorage.push_back(s);
        sort(begin(sortedStorage), end(sortedStorage));
    }
    vector<string> GetSortedStrings() {
        // получить набор из всех добавленных строк в отсортированном порядке
        return sortedStorage;
    }
private:
    // приватные поля
    vector<string> sortedStorage;
};

void SortedStringsTask();