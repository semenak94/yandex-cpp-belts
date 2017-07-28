#pragma once

#include <string>
#include <algorithm>

using namespace std;

void ReversibleStringTask();

class ReversibleString {
public:
    ReversibleString() { reverse_string = ""; };
    ReversibleString(const string& s) {
        reverse_string = s;
    }
    void Reverse() {
        reverse(begin(reverse_string), end(reverse_string));
    }
    string ToString() const {
        return reverse_string;
    }
private:
    string reverse_string;
};