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
            this->set(row, col, 0);
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix& sourceMatrix)
{
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            this->set(row, col, sourceMatrix.get(row, col));
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement sourceMatrix[size][size])
{
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            this->set(row, col, sourceMatrix[row][col]);
}

void TwoDimensionMatrix::operator()(TwoDimensionMatrix& sourceMatrix)
{
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            this->set(row, col, sourceMatrix.get(row, col));
}

std::istream& operator>>(std::istream& is, TwoDimensionMatrix& matrix)
{
    for (size_t row = 0; row < matrix.getSize(); ++row)
        for (size_t col = 0; col < matrix.getSize(); ++col)
            is >> matrix.matrix[row][col];

    return is;
}

std::ostream& operator<<(std::ostream& os, const TwoDimensionMatrix& matrix)
{
    for (size_t row = 0; row < matrix.getSize(); ++row)
    {
        for (size_t col = 0; col < matrix.getSize(); ++col)
        {
            os << matrix.get(row, col);
        }
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
            result.set(row, col, matrix1.get(row, col) + matrix2.get(row, col));

    return result;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number)
{
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            this->set(row, col, this->get(row, col) * number);

    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& matrix) const
{
    TwoDimensionMatrix result;
    for (size_t row = 0; row < size; ++row)
        for (size_t col = 0; col < size; ++col)
            result.set(row, col, this->get(row, col) && matrix.get(row, col));

    return result;
}

MatrixElement* TwoDimensionMatrix::operator[](size_t i)
{
    return matrix[i];
}

const MatrixElement* TwoDimensionMatrix::operator[](size_t i) const
{
    return matrix[i];
}
