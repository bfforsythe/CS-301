#pragma once
// esarray.h  UNFINISHED
// Glenn G. Chappell
// 2022-10-18
//
// For CS 311 Fall 2022
// Header for class ESArray
// Extremely smart array of int
// Preliminary to Assignment 5

#ifndef FILE_ESARRAY_H_INCLUDED
#define FILE_ESARRAY_H_INCLUDED

#include <cstddef> // for size_t

// *********************************************************************
// class ESArray - Class definition
// *********************************************************************


// class ESArray
// Extremely Smart Array of int.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     _size >= 0.
//		data must point to value_type, allocated with new [], and owned by *this
//		Must also be large enough to hold _size value.


class ESArray {

	// ***** ESArray: types *****
public:

	using value_type = int;
	using size_type = std::size_t;
	using iterator = value_type*;
	using const_iterator = const value_type*;


	// ***** ESArray: ctors, op=, dctor *****
public:

	explicit ESArray(size_type size = 0) {}

	ESArray(const ESArray & other) {}

	ESArray(ESArray && other) noexcept {}

	ESArray & operator=(const ESArray& other) {}

	ESArray & operator=(ESArray&& other) noexcept {}

	~ESArray() {}






	// ***** ESArray: general public operators *****
public:

	value_type & operator[](size_type index) {}

	const value_type & operator[](size_type index) const {}


	// ***** ESArray: general public functions *****
public:

	size_type size() const {}



	bool empty() const {}



	iterator begin() {}

	const iterator begin() const {}



	iterator end(){}
	
	const iterator end() const {}


	
	void resize(size_type newsize) {}

	iterator insert(iterator pos, 
					const value_type & item) {}

	iterator erase (iterator pos) {}


	void push_back (const value_type & item) {

		insert(end(), item);
	}


	void pop_back() {
		
	}

	void swap(ESArray & other) noexcept {}


	// ***** ESArray: data members *****
private:

	size_type   _size;
	value_type* _data;


};  // End class ESArray


#endif  //#ifndef FILE_ESARRAY_H_INCLUDED
