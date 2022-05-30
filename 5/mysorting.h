#ifndef MYSORTING_H
#define MYSORTING_H

#include "myList.h"
#include <algorithm>
#include <cstring>
#include <vector>

template <typename T, size_t n> void mySort(T(&toSort)[n])
{
    std::sort(toSort, toSort+n);
}

template <size_t n, size_t m> void mySort(char(&toSort)[n][m])
{
    std::vector<std::string> strings(n);
    for (size_t i = 0; i < n; ++i)
        strings[i] = std::string(toSort[i]);

    std::sort(strings.begin(), strings.end(), 
        [](const auto& s1, const auto& s2) {
            return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), 
                [](const char& ch1, const char& ch2) {
                    return toupper(ch1) < toupper(ch2);
                });
        });

    for (size_t i = 0; i < n; ++i)
        strcpy(toSort[i], strings[i].c_str());
}

template <typename T> void mySort(T& toSort)
{
    std::sort(toSort.begin(), toSort.end());
}

template <typename T> void mySort(MyList<T>& toSort)
{
    std::vector<std::unique_ptr<typename MyList<T>::Node>> pointers(toSort.size());

    pointers[0] = std::move(toSort.head);
    for (size_t i = 1; i < toSort.size(); ++i)
        pointers[i] = std::move(pointers[i-1]->next);

    std::sort(pointers.begin(), pointers.end(), 
        [](const auto& l, const auto& r) {
            return l->value() < r->value();
        });

    for (size_t i = toSort.size() - 1; i > 0; --i)
        pointers[i-1]->next = std::move(pointers[i]);

    toSort.head = std::move(pointers[0]);
}

#endif // MYSORTING_H
