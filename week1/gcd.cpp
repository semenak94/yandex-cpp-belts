#include "gcd.h"
#include <math.h>

int greatest_common_divisor(int a, int b)
{
    while (a != 0 && b != 0) {
        if (abs(a) > abs(b)) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    return a + b;
}