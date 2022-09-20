#include "nsarray.h"
#include <iostream>>
#include <string>
#include <vector>



int main() {

    NSArray<int> ia(8);           // Array of 8 ints
    NSArray<int> iax;             // Another array of 8 ints
    NSArray<double> da(40, 3.2);  // Array of 40 doubles; each is set to 3.2
    NSArray x(8);                 // DOES NOT COMPILE; no template parameter

    // Set all items (counter loop)
    for (int c = 0; c < ia.size(); ++c)
    {
        ia[c] = c * c;
    }

    // Range-based for-loop calls NSArray member functions begin, end
    for (auto x : ia)
    {
        cout << "Item :" << x << endl;
    }

    const NSArray<int> ia2 = ia;  // Copy constructor
    if (ia2 == ia)                // Condition should be true
        cout << "Equal!" << endl;

    NSArray<double> da2;
    da2 = da;                     // Copy assignment
    da2 = ia;                     // DOES NOT COMPILE; different value types

    if (da == ia)                 // DOES NOT COMPILE; different value types
        cout << "blah blah" << endl;


}