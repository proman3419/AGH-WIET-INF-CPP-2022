// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()

#include "vector.h"

Vector::Vector(std::size_t capacity)
{
    data_ = std::unique_ptr<Fraction[]>(new Fraction[capacity]);
    size_ = 0;
    capacity_ = capacity;
}

void Vector::shallowCopy(const Vector& toCopy)
{
    for (std::size_t i = 0; i < toCopy.size(); ++i)
        data()[i] = toCopy.data()[i];
    size_ = toCopy.size();
    capacity_ = toCopy.capacity();
}

Vector::Vector(const Vector& toCopy)
{
    *this = toCopy;
}

Vector::Vector(Vector&& toMove)
{
    *this = std::move(toMove);
}

void Vector::operator=(const Vector& toCopy)
{
    data_ = std::unique_ptr<Fraction[]>(new Fraction[toCopy.capacity()]);
    shallowCopy(toCopy);
}

void Vector::operator=(Vector&& toMove)
{
    data_ = std::unique_ptr<Fraction[]>(std::move(toMove.data_));
    size_ = toMove.size();
    capacity_ = toMove.capacity();

    toMove.data_ = nullptr;
    toMove.size_ = 0;
    toMove.capacity_ = 0;
}

void Vector::push_back(const Fraction toAdd)
{
    if (size() >= capacity())
    {
        // possible improvement: 2 * capacity + 1 even though capacity + 1 would be enough
        // this way we resize fewer times (but we lose some space for a while)
        capacity_ = capacity() + 1;
        data_ = std::unique_ptr<Fraction[]>(new Fraction[capacity()]);
        shallowCopy(*this);
    }
    data()[size_++] = toAdd;
}

Fraction Vector::operator[](std::size_t index)
{
    if (index >= size())
        throw std::out_of_range("Index out of bounds (size) of the vector");
    else
        return data()[index];
}

Fraction Vector::operator[](std::size_t index) const
{
    if (index >= size())
        throw std::out_of_range("Index out of bounds (size) of the vector");
    else
        return data()[index];
}
