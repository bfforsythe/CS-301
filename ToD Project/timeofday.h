// timeofday.h
// Brandon Forsythe
// 2022-09-02
// Header with Class for timeofday.cpp

#pragma once

#ifndef timeofday
#define timeofday

#include <ostream>
#include<iostream>
#include <cassert>


class TimeOfDay {

public:


	friend std::ostream& operator << (std::ostream& str, const TimeOfDay& obj) {}

	TimeOfDay()
		:_secs(0)
	{



	}

	TimeOfDay(int hh, int mm, int ss) {

		assert(0 <= hh && hh < 24);
		assert(0 <= mm && mm < 60);
		assert(0 <= ss && ss < 60);

		setTime(hh, mm, ss);

	}
	
	TimeOfDay & operator++() {  // Pre-Inc

		++_secs;

		if (_secs == 24 * 60 * 60 - 1) {
			_secs = 0;
		}
		return *this;
	}

	TimeOfDay operator++(int dummy) { // Post-Inc

		auto save = *this;
			++(*this);
			return save;
	}

	TimeOfDay& operator--() { // Pre-Dec


		--_secs;

		if (_secs == 24 * 60 * 60 - 1) {
			_secs = 0;
		}
		return *this;
	}

	

	TimeOfDay& operator--(int dummy) { // Post-Dec

		auto save = *this;
		--(*this);
		return save;
	}


	void getTime( int& hh,  int& mm,  int& ss) const {}


	void setTime(int hh, int mm, int ss) 
	{
		_secs = hh * 60 * 60 + mm * 60 + ss;
	}

private:

	int _secs; // # of seconds since midnight (0 - 24*60*60 -1) 



}; // End Class TimeOfDay

std::ostream & operator << (std::ostream& str, const TimeOfDay& obj) {

	int hh, mm, ss;
	obj.getTime(hh, mm, ss);


	if (hh < 10) {
		str << " ";
		str << hh;
	}

	std::cout << ":";

	if (mm < 10) {
		str << " ";
		str << mm;
	}

	std::cout << ":";

	if (ss < 10) {
		str << " ";
		str << ss;
	}
}
return(_secs);

#endif // !timeofday

