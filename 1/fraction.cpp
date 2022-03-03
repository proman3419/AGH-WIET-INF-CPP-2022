#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "fraction.h"

#if IMPLEMENTED_classFractionExists
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // IMPLEMENTED_classFractionExists

int Fraction::removedFractions_ = 0;

Fraction::Fraction() : Fraction{0, 1} {}

Fraction::Fraction(int numerator, int denominator) 
{
    setNumerator(numerator);
    setDenominator(denominator);
}

Fraction::Fraction(int numerator, int denominator, std::string fractionName) : Fraction{ numerator, denominator }
{
    setFractionName(fractionName);
}

Fraction::~Fraction()
{
    Fraction::incrementRemovedFractions();
}

void Fraction::save(std::ostream& os) const
{
    os << this->toString();
}

void Fraction::load(std::istream& is)
{
    char delimiter;
    is >> numerator >> delimiter >> denominator;
}
