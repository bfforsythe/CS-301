// Brandon Forsythe
// Chappell 311
// nsarray.h
// Note: This leads to a linker error and I Cannot for the life of me figure out why.

#pragma once
#ifndef NSARRAY_HPP
#define NSARRAY_HPP

#include <iostream>
using std::endl; // both endl and cout for ease of access
using std::cout;


template<class T> // initialize template
class NSArray {

private:

	int max; // Maximum size of array
	int types = 0;
	T* createArray; // pointer to type array



public:


	int& operator[](int i) {  // [ ] overload
		if (i < 0 || i > max-1){
			return(createArray[0]);
		}

		return createArray[i];
	}


	 NSArray() {	// Default Ctor
		 max = 8;
		 types = 0;
		 createArray = new T[max];
	}


	 NSArray(T numItems) { // 1 param ctor
		 max = numItems;
		 createArray = new T[max];
	}

	 NSArray(T numItems, T typeItems) { // 2 param ctor

		 max = numItems;
		 createArray = new T[max];
	}


	~NSArray(){ // Dctor
		delete[] createArray;
	}; 



	int size() { // Size should return maximum size of array
		return(max);
	}

	int* begin()  { // returns itr value (default zero)
		auto itr = createArray;
		return(itr);
	}

	int* end() { // returns itr value (max + 1)
		auto itr = createArray;
		return(itr + max + 1);
	}

	// The Big Functions

	NSArray(const NSArray& other);
	NSArray& operator=(const NSArray& rhs);
	NSArray(NSArray&& other);
	NSArray& operator=(NSArray&& rhs);


};


// Overloads (FAILS)

template<typename T>
bool operator==(const NSArray<T>& lhs, const NSArray<T>& rhs) {
	if (lhs == rhs) {
		return(true);
	}
	else {
		return(false);
	}
}

template<typename T>
bool operator!=(const NSArray<T> lhs, const NSArray<T> rhs)  {
	if (lhs.size() != rhs.size()) {
		return(true);
	}
	else {
		return(false);
	}
}


#endif // !NSARRAY_HPP
