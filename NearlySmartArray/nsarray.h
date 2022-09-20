#pragma once
#ifndef NSARRAY_HPP
#define NSARRAY_HPP

#include <iostream>
using std::endl;
using std::cout;


template<class T>

class NSArray {

private:

	T noOfMem;


public:

	int& operator[](int i) {
		if (i < noOfMem) {
			// return first element.
			return NSArray[i];
		}
		else {
			cout << "I out of bounds";
			return (-1);
		}
		
	}


	 NSArray() {	// Default Ctor
		noOfMem = 8;
	}


	 NSArray(T numItems) { // 1 param ctor
		noOfMem = numItems
	}

	 NSArray(T numItems, T typeItems) { // 2 param ctor
	}


	~NSArray(){}; // Dctor



	int size() {
		
	}

	int begin() {
		return(0);
	}

	NSArray(const NSArray& other);
	NSArray& operator=(const NSArray& rhs);
	NSArray(NSArray&& other);
	NSArray& operator=(NSArray&& rhs);


};

template<typename T>
bool operator==(const NSArray<T>& lhs, const NSArray<T>& rhs){
	if (lhs.size() == rhs.size()) {
		return(true);
	}
	else {
		return(false);
	}
}

template<typename T>
bool operator!=(const NSArray<T>& lhs, const NSArray<T>& rhs) {
	if (lhs.size() != rhs.size()) {
		return(true);
	}
	else {
		return(false);
	}
}


#endif // !NSARRAY_HPP
