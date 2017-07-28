#include "file_works.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void FileWorksTask() {
    ifstream input("week4/file-works/input.txt");
    ofstream output("week4/file-works/output.txt");
    string line;
    while (getline(input, line)) {
        cout << line << endl;
        output << line << endl;
    }
}
