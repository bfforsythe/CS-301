// tsort.h  SKELETON
// Glenn G. Chappell
// 2022-11-14
//
// For CS 311 Fall 2022
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TSORT_H_INCLUDED
#define FILE_TSORT_H_INCLUDED

#include <iterator>
// For std::iterator_traits

// *******************************************************
// * YOU MIGHT WANT TO GET RID OF THE FOLLOWING INCLUDES *
// *******************************************************

#include <algorithm>
// For std::stable_sort, std::move
#include <vector>
// For std::vector
#include <iterator>
// For std::distance


// Binary Search Tree implementation (BinTree);
template<typename Val>

struct binTree {
	Val _data;
	std::unique_ptr<binTree<Val>> _left; // Move left down through tree
	std::unique_ptr < binTree<Val> _right; // Move right down through tree



    // Default Constructor
     binTree(const ValType& data,
        std::unique_ptr<BSTNode<ValType>> left = nullptr,
        std::unique_ptr<BSTNode<ValType>> right = nullptr)
        : _data(data)

    {
        _left = std::move(left);
        _right = std::move(right);
    }

};




// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
	if (std::distance(first, last) == 0) {
		return;
	}


}


#endif //#ifndef FILE_TSORT_H_INCLUDED
