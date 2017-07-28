#include "precision_output.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void PrecesionOutputTask() {
    ifstream input("week4/precision-output/input.txt");
    double number;
    cout << fixed << setprecision(3);
    while (input >> number) {
        cout << double(number) << endl;
    }
}
