// tsort.h  
// Brandon Forsythe
// 11/18/22

// This header file satisfies the requirements for CS311
// This header file was modified from a skeleton provided by Dr. Chappell.

#ifndef FILE_TSORT_H_INCLUDED
#define FILE_TSORT_H_INCLUDED

#include <iterator>
// For std::iterator_traits
#include <algorithm>
// For std::stable_sort, std::move
#include <vector>
// For std::vector
#include <iterator>
// For std::distance
#include <memory>
// For std::unique_ptr


// Attempted BinSearch algorithm.
template<typename Val>

struct binTree {
	Val _data;
	std::unique_ptr<binTree<Val>> _left; // Move left down through tree
	std::unique_ptr < binTree<Val>> _right; // Move right down through tree



    // Default Constructor
    explicit binTree(const Val& data,
        std::unique_ptr<binTree<Val>> left = nullptr,
        std::unique_ptr<binTree<Val>> right = nullptr)
        : _data(data)

    {
        _left = std::move(left);
        _right = std::move(right);
    }



     ~binTree() = default;

};

// traverse
// Pre:
//     Iter must exist and point to the first object
// Requirements on Types:
//     Val must include a copy and < constructor
//     FDIter must be a forward iterator
// Exception safety guarantee:
// No-Throw (???)


template<typename Val, typename FDIter>
void traverse(std::unique_ptr<binTree<Val>>& head, FDIter& iter)
{
    if (head == nullptr)
    {
        return;
    }
    traverse(head->_left, iter);
    *iter++ = head->_data;
    traverse(head->_right, iter);
}


// insert
// Pre:
//     Smart pointers :) my favorite
// Requirements on Types:
//     Val must include a copy and < constructor.
// Exception safety guarantee:
// Strong


template<typename Val>
void insert(std::unique_ptr<binTree<Val>>& head, const Val& item)
{
    if (head == nullptr)
    {
        head = std::make_unique<binTree<Val>>(item);
        return;
    }
    if (item < head->_data)
    {
        insert(head->_left, item);
    }
    else {
        insert(head->_right, item);
    }
}



// treesort
// Sort a given range using Treesort.
// Pre:
//     first and last must exist
// Requirements on Types:
//     Val must include a copy and < constructor
// Exception safety guarantee:
//     STRONG
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    using Value = typename std::iterator_traits<FDIter>::value_type;

	if (std::distance(first, last) == 0) {
		return;
	}

    std::unique_ptr<binTree<Value>> head = std::make_unique<binTree<Value>>(*first);
    FDIter placeholder = first;


    while (std::distance(placeholder, last) != 1)
    {
        std::advance(placeholder, 1);
        insert(head, *placeholder);
    }

    traverse(head, first);

}


#endif //#ifndef FILE_TSORT_H_INCLUDED
