#pragma once

#include <vector>

using namespace std;

void IncognizableTask();

class Incognizable {
public:
    Incognizable() {
        first_value = 0;
        second_value = 0;
    };
    Incognizable(int v) {
        first_value = v;
    };
    Incognizable(int v, int w) {
        first_value = v;
        second_value = w;
    };
private:
    int first_value;
    int second_value;
};