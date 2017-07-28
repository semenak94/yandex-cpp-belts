#include "ensure_equal.h"
#include <string>
#include <exception>
#include <iostream>
#include <sstream>
using namespace std;

void EnsureEqual(const string& left, const string& right) {
    try {
        if (left != right) {
            stringstream ss;
            ss << left << " != " << right;
            throw runtime_error(ss.str());
        }
        cout << "OK" << endl;
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
}

void EnsureEqualTask() {
    EnsureEqual("string", "string");
    EnsureEqual("left", "right");
    EnsureEqual("AAAA","AAAa");
}
