#pragma once

// da3.h  (Finished)
// Brandon Forsythe
// 2022-09-27
// This is the header file in order to satisfy both da3.cpp and da3_test.cpp
// My code is written inside of skeleton programs originally created by Dr. Glenn Chappell.

#ifndef FILE_DA3_H_INCLUDED
#define FILE_DA3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept> // for std::out_of_range

template <typename ValueType>
ValueType lookup(const LLNode<ValueType>* head,
    std::size_t index)

    //Using std::out_of_range to throw and catch error.
{
    while (true) {
        if (head == nullptr) {
            throw std::out_of_range("'head' points to a range not in size");
        }
        if (index == 0 ) {
            return head->_data;

        }
        head = head->_next;
        --index;
   }
}


// Implementation in source file
void didItThrow(const std::function<void()>& ff,
    bool& threw);


template <typename FDIter>
bool checkSorted(FDIter first,
    FDIter last)
{
    // PRECON = Must have FD template


    if (first == last) {
        return true;
       }

    FDIter next = first;

    while (++next != last) {
        if (*next < *first) { return false; }
        ++first;
    }
        return true;
    }



// Implementation in source file
int gcd(int a,
    int b);


#endif  //#ifndef FILE_DA3_H_INCLUDED
