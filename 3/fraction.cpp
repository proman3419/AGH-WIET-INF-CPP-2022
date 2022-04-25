#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric> // std::gcd

#include "fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
    setNumerator(numerator);
    setDenominator(denominator);
}

void Fraction::setDenominator(int denominator)
{
    if (denominator == 0)
        throw std::invalid_argument("Denominator can't be equal to 0.");
    else
        denominator_ = denominator;
}

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    int n = f1.numerator() * f2.denominator() + f2.numerator() * f1.denominator();
    int d = f1.denominator() * f2.denominator();
    return Fraction(n, d).simplify();
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    int n = f1.numerator() * f2.numerator();
    int d = f1.denominator() * f2.denominator();
    return Fraction(n, d).simplify();
}

Fraction& Fraction::simplify()
{
    int gcd = std::gcd(numerator(), denominator());
    setNumerator(numerator() / gcd);
    setDenominator(denominator() / gcd);
    return *this;
}
