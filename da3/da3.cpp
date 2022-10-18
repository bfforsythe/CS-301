// da3.cpp  (Finished)
// Brandon Forsythe
// 2022-09-27
// This program is a finished skeleton by Dr. Glenn Chappell, my code has been written in the functions in order to satisfy da3_test.cpp

#include "da3.h"       // For Assignment 3 prototypes & templates

#include <functional>
using std::function;


void didItThrow(const function<void()>& ff,
    bool& threw)
{
    try  {
        ff();
    }
    catch (...) {
        threw = true;
        throw;
    }

    threw = false;
    return;
}


int gcd(int a,
    int b)
{
   //BASE CASE

    if (a == 0) {
        return b;
    }

    // RECURSE CASE

    else if (a > b) {
        return gcd(b, a);
    }
    else {
        return gcd(b % a , a);
    }

}
