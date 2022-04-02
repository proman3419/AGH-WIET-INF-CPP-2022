#include <iostream>
#include <string>

#include "matrix.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

TwoDimensionMatrix::TwoDimensionMatrix()
{
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            (*this)[row][col] = 0;
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix& sourceMatrix)
{
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            (*this)[row][col] = sourceMatrix[row][col];
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement sourceMatrix[size][size])
{
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            (*this)[row][col] = sourceMatrix[row][col];
}

void TwoDimensionMatrix::operator()(TwoDimensionMatrix& sourceMatrix)
{
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            (*this)[row][col] = sourceMatrix[row][col];
}

std::istream& operator>>(std::istream& is, TwoDimensionMatrix& matrix)
{
    for (size_t row = 0; row < matrix.getSize(); ++row)
        for (size_t col = 0; col < matrix.getSize(); ++col)
            is >> matrix[row][col];

    return is;
}

std::ostream& operator<<(std::ostream& os, const TwoDimensionMatrix& matrix)
{
    for (size_t row = 0; row < matrix.getSize(); ++row)
    {
        for (size_t col = 0; col < matrix.getSize(); ++col)
            os << matrix[row][col];
        os << '\n';
    }

    return os;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix&
    matrix2)
{
    TwoDimensionMatrix result(matrix1);
    for (size_t row = 0; row < matrix1.getSize(); ++row)
        for (size_t col = 0; col < matrix1.getSize(); ++col)
            result[row][col] = matrix1[row][col] + matrix2[row][col];

    return result;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number)
{
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            (*this)[row][col] = (*this)[row][col] * number;

    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& matrix) const
{
    TwoDimensionMatrix result;
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            result[row][col] = (*this)[row][col] && matrix[row][col];

    return result;
}
