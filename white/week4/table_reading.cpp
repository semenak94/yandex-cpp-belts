#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void TableWorkTask() {
    ifstream input("week4/table-reading/input.txt");
    string string_N, string_M;
    string line;
    if (input) {
        getline(input, string_N, ' ');
        getline(input, string_M);
        int N = stoi(string_N), M = stoi(string_M);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (j < M - 1) {
                    getline(input, line, ',');
                }
                else {
                    getline(input, line);
                }
                cout << setw(10) << line;
            }
            cout << endl;
        }
    }

}
