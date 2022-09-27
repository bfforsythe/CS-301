// Brandon Forsythe
// Chappell 311
// 9/18/22 - 9/22/22
// nsarray.h
// Template Header Class in order to satisfy nsarray_test.cpp

// NOTE: This throws some error that is caught by the _test.cpp program. I can't figure out how to fix it, it has something to do with the 1 param ctor.

#pragma once
#ifndef NSARRAY_HPP
#define NSARRAY_HPP


#include <iostream>
using std::endl; // both endl and cout for ease of access
using std::cout;

// Class Invariants: _size MUST BE >= 0 



template<typename T> // initialize template
class NSArray { // (Nearly) Smart Array begins here.




public:
	using size_type = std::size_t;
	using value_type = T;



	value_type& operator[](size_type i) // [ ] Overload
	{
		return _createArray[i];
	}
	const value_type& operator[](size_type i) const
	{
		return _createArray[i];
	}



	// *********** Constructors ***********

	 NSArray() // Default Ctor
		 :_createArray(new value_type[8]), _size(8)
	 {}

	 NSArray(size_type size) // 1 param ctor
		 :_createArray(new value_type[8]), _size(8) 
	 {}
	

	 NSArray(size_type size, const value_type& value) // 2 param ctor
		 :_createArray(new value_type[size]), _size()
	 {}


	 ~NSArray() { // Dctor
		 delete[] _createArray;
	 }


	// ****************** "General" (? I don't know if that's the right term) Functions ******************


	// PRECON: _size must be defined
	std::size_t size() const // Checks size;
	{
		
		return _size;
	}

	// PRECON: _createArray must be defined
	value_type * begin()   { // returns itr value (default zero)
		return(_createArray);
	}

	// PRECON: _createArray must be defined
	const value_type* begin() const { // returns itr value (default zero) (Constant Version)
		return(_createArray);
	}



	value_type* end() { // returns itr value (max + 1)
		return(_createArray + _size);
	}
	const value_type* end() const { // returns itr value (max + 1) (Constant Version)
		return(_createArray + _size);
	}




	// ****************** The Big Five Functions ******************

	// Move Func. (PRECON: _createArray must exist, .size() must exist)

	NSArray(NSArray&& old) noexcept
		: _createArray(old._createArray), _size(old.size())
	{
		old._createArray = nullptr;
		old._size = 0;
	}


	// Move Operator (PRECON: size_t of i can't be less than 0)

	NSArray(const NSArray& og)
		: _createArray(new value_type[og.size()]), _size(og.size())
	{
		for (std::size_t i = 0; i < _size; ++i)
			_createArray[i] = og[i];
	}


	// Copy Func. (PRECON: NSArray must exist, _createArray must exist)

	NSArray& operator=(NSArray&& og) noexcept
	{
		std::swap(_size, og._size);
		std::swap(_createArray, og._createArray);
		return *this;
	}


	// Copy Oppy (PRECON: _createArray must exist)

	NSArray& operator=(const NSArray& original)
	{
		NSArray old(original);
		std::swap(_size, old._size);
		std::swap(_createArray, old._createArray);
		return *this;
	}

private:


		value_type* _createArray; // Array PTR
		size_type _size;

};


// ********Overloads**********


// ==
template<typename T>
bool operator==(const NSArray<T>& lhs, const NSArray<T>& rhs) {
	return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}




// !=
template<typename T>
bool operator!=(const NSArray<T> lhs, const NSArray<T> rhs)  {
	return !(lhs == rhs);
}



// <=
template <typename T>
bool operator<=(const NSArray<T>& lhs, const NSArray<T>& rhs)
{
	return !(rhs < lhs);
}



// >
template <typename T>
bool operator>(const NSArray<T>& rhs, const NSArray<T>& lhs)
{
	return (rhs < lhs);
}



// >=
template <typename T>
bool operator>=(const NSArray<T>& lhs, const NSArray<T>& rhs)
{
	return !(lhs < rhs);
}


// <
template <typename T>
bool operator<(const NSArray<T>& lhs, const NSArray<T>& rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(),
		rhs.begin(), rhs.end());
}




#endif // !NSARRAY_HPP



