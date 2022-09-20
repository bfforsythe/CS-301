#pragma once
#ifndef NSARRAY_HPP
#define NSARRAY_HPP

template<class T>

class NSArray {

private:

	


public:

	int& operator[](int i) {
		if (i > SIZE) {
			cout << "Index out of bounds" << endl;
			// return first element.
			return arr[0];
		}

		return arr[i - 1];
	}
	NSArray() { // Default Ctor
		T[8];
	}


	NSArray(int numItems) { // 1 param ctor
		T[numItems];
	}

	NSArray(int numItems, auto typeItems) { // 2 param ctor
		T[numItems, typeItems];
	}


	~NSArray(); // Dctor





	NSArray(const NSArray& other);
	NSArray& operator=(const NSArray& rhs);
	NSArray(NSArray&& other);
	NSArray& operator=(NSArray&& rhs);


};







#endif // !NSARRAY_HPP
