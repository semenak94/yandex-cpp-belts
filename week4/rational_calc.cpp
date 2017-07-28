#include "rational_interface.h"
#include <iostream>
#include <exception>
using namespace std;

int RationalCalc() {
    try {
        Rational r1, r2;
        char operation;
        cin >> r1 >> operation >> r2;

        if (operation == '+') {
            cout << r1 + r2 << endl;
        }
        else if (operation == '-') {
            cout << r1 - r2 << endl;
        }
        else if (operation == '*') {
            cout << r1 * r2 << endl;
        }
        else if (operation == '/') {
            cout << r1 / r2 << endl;
        }
    }
    catch (exception& ex) {
        cout << "exception happened: " << ex.what() << endl;
    }
    return 0;
}
