#include "rational_interface.h"
#include <iostream>
#include <math.h>
using namespace std;

Rational operator + (const Rational& a, const Rational& b) {
    int num_ = a.Numerator();
    if (a.Denominator() == b.Denominator()) {
        num_ += b.Numerator();
    }
    else {
        num_ = num_ * b.Denominator() + b.Numerator() * a.Denominator();
    }
    int denom_ = abs(a.Denominator() * b.Denominator()) / greatest_common_divisor(a.Denominator(), b.Denominator());
    return Rational{ num_, denom_ };
}

Rational operator - (const Rational& a, const Rational& b) {
    int num_ = a.Numerator();
    if (a.Denominator() == b.Denominator()) {
        num_ -= b.Numerator();
    }
    else {
        num_ = num_ * b.Denominator() - b.Numerator() * a.Denominator();
    }
    int denom_ = abs(a.Denominator() * b.Denominator()) / greatest_common_divisor(a.Denominator(), b.Denominator());
    return Rational{ num_, denom_ };
}

bool operator == (const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() &&
        lhs.Denominator() == rhs.Denominator()) {
        return true;
    }
    return false;
}

Rational operator * (const Rational& a, const Rational& b) {
    return Rational{ a.Numerator() * b.Numerator(), a.Denominator() * b.Denominator() };
}
Rational operator / (const Rational& a, const Rational& b) {
    if (b.Numerator() == 0) {
        stringstream ss;
        ss << "Division by zero";
        throw domain_error(ss.str());
    }
    return Rational{ a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator() };
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() != rhs.Denominator()) {
        return (rhs.Denominator() * lhs.Numerator() < rhs.Numerator()* lhs.Denominator());
    }
    return lhs.Numerator() < rhs.Numerator();
}

istream& operator >> (istream& stream, Rational& rat) {
    int num;
    stream >> num;
    stream.ignore(1);
    int denom;
    stream >> denom;
    rat = Rational{num, denom};
    return stream;
}

ostream& operator << (ostream& stream, const Rational& rat) {
    stream << rat.Numerator()  << "/" << rat.Denominator();
    return stream;
}
