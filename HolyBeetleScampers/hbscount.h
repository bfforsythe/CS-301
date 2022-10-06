#pragma once
#ifndef HBSCOUNT_HPP
#define HBSCOUNT_HPP

//hbscount.h
//Brandon Forsythe
// 10/3/22
// CS 311x

// This is the header file for counting and allowing hbscount.cpp to actually function. It runs into one error that I can't solve.
// Some of the logic and reasoning behind this program comes from queencount.cpp by Glenn Chappell


#include <vector> // for std::vector
using std::vector;

using Board = vector<vector<int>>; // this initializes the board.

// Pre: 
// All of these MUST be initialized.

int hbsCount(const int& squareX, 
			 const int& squareY,
			 const int& hole_x, 
			 const int& hole_y,
			 const int& startX, 
			 const int& startY,
			 const int& finish_x, 
			 const int& finish_y);

// Precon:
// Same as above
int hbsCount_recurse(
			 Board& board,
			 const int& squareX,
			 const int& squareY,
			 const int& finish_x, 
			 const int& finish_y,
			 int& curr_x, 
			 int& curr_y,
			 int& squaresLeft);


#endif // #ifndef FILE_COUNTHSW_H_INCLUDED
