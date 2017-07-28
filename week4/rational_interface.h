#pragma once

#include "../week1/gcd.h"
#include <istream>
#include <ostream>
#include <sstream>
#include <exception>

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            std::stringstream ss;
            ss << "Invalid argument";
            throw std::invalid_argument(ss.str());
        }
        int gcd = greatest_common_divisor(numerator, denominator);
        if (gcd != 0) {
            num = numerator / gcd;
            denom = denominator / gcd;
            if (denom < 0) {
                denom *= -1;
                num *= -1;
            }
        }
        else {
            num = 0;
            denom = 1;
        }
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return denom;
    }

    friend Rational operator + (const Rational& a, const Rational& b);
    friend Rational operator - (const Rational& a, const Rational& b);
    friend Rational operator * (const Rational& a, const Rational& b);
    friend Rational operator / (const Rational& a, const Rational& b);
    friend bool operator == (const Rational& lhs, const Rational& rhs);
    friend bool operator < (const Rational& lhs, const Rational& rhs);

    friend std::istream& operator >> (std::istream& stream, Rational& rata);
    friend std::ostream& operator << (std::ostream& stream, const Rational& rat);

private:
    int num;
    int denom;
};
