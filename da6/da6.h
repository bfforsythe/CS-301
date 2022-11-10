// da6.h
// Brandon Forsythe
// CS301
// 11-8-22
// This is the header file that satisfies da6_test.cpp.



#ifndef FILE_DP6_H_INCLUDED
#define FILE_DP6_H_INCLUDED

#include "llnode2.h"	
#include <memory>		// for std::unique_ptr
#include <functional>	// for std::function
#include <cstddef>		// for std::size_t
#include <stdexcept>	// for std::throw_except

// reverseList
// .... reverses a list :)
// Pre:
//	a Unique pointer under The LL2Node specifications must exist
// No-Throw Guarantee
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>>& head)
{
	std::unique_ptr<LLNode2<ValType>> newHead(nullptr);
	std::unique_ptr<LLNode2<ValType>> currentHead(nullptr);

	while (head != nullptr)
	{
		currentHead = std::move(head->_next);
		head->_next = std::move(newHead);
		newHead = std::move(head);
		head = std::move(currentHead);
	}

	head = std::move(newHead);
}

// --------------
// Slow Map Class
// --------------

// Templated linked list map
// Invariants:
//    _next must be empty eventually
//	  LLNode2 must meet requirements
// Requirements on Types:
//		Key and Data must have a construct and non-throwing destruct
//		and NOTHING ELSE!
template <typename Key, typename Data>
class SlowMap {

	// ***** types *****
public:
	// key_type: type of key items
	using key_type = Key;
	// data_type: type of data items
	using data_type = Data;


	// **** constructors, destructors *****
public:

	// Strong Guarantee
	SlowMap() : _head(nullptr)
	{}

	// Default destructor
	// No-Throw Guarantee
	~SlowMap()
	{}

	// The rest of the 5:
	// we Must delete everything else

	SlowMap(const SlowMap& other) = delete;
	SlowMap(SlowMap&& other) = delete;
	SlowMap& operator=(const SlowMap& other) = delete;
	SlowMap& operator=(const SlowMap&& other) = delete;



	// ----- Main program functions -----


public:

	// size
	// Returns an integer of appropriate type 
	// No-Throw Guarantee
	size_t size() const
	{
		auto it = _head.get();
		std::size_t i = 0;
		while (it)
		{
			it = it->_next.get();
			++i;
		}
		return i;
	}


	// empty
	// Returns a bool indicating if there are no pairs
	// No-Throw Guarantee
	bool empty() const
	{
		if (_head == nullptr)
		{
			return true;
		}
		return false;
	}


	// present and const present
	// returns a bool on whether or not a key is found in the dataset
	// Pre:
	//		There must be a key lol
	// No-Throw Guarantee
	bool present(const key_type& key)
	{
		auto it = _head.get();
		while (it)
		{
			if (it->_data.first == key) {
				return true;
			}
			it = it->_next.get();
		}
		return false;
	}

	const bool present(const key_type& key) const
	{
		auto it = _head.get();
		while (it)
		{
			if (it->_data.first == key)
			{
				return true;
			}
			it = it->_next.get();
		}
		return false;
	}


	// Set
	// Takes two sets of values, a key and a data type
	// and adds them into the linked list at a specified point
	// 
	// Pre:
	//		key,data must be valid and exist
	// Strong Guarantee
	void set(key_type key, data_type data)
	{
		auto p = _head.get();
		while (p != nullptr) {
			if (p->_data.first == key) {
				p->_data.second = data;
				return;
			}
			p = p->_next.get();
		}

		push_front(_head, std::pair<key_type, data_type>(key,data));
	}

	// Get
	// Runs through the data set, returns if a match is found
	// WILL THROW IF NOT FOUND!
	// Pre:
	//		_head, _data, _next must all be defined
	//		proper catch must be implemented
	// Strong Guarantee


	data_type & get(key_type key) const {
			
		auto p = _head.get();

		while (p != nullptr && p->_data.first != key) {

			p = p->_next.get();
		}

		if (p == nullptr) {
			throw std::out_of_range("Key not in data");
		}

		return p->_data.second;
		
	}
	// erase
	// Erases a set pair of values
	// Pre:
	//		key has must be valid
	// No-Throw Guarantee
	void erase(key_type key)
	{
		auto it = _head.get();
		auto it2 = _head.get();
		while (it) {
			if (it->_data.first == key) {
				std::swap(it2->_next, it->_next);
				it->_next = nullptr;
				it = nullptr;
			}
			else {
				it2 = it;
				it = it->_next.get();
			}
		}
	}

	// traverse
	// walks through dataset, unmodifying
	// Pre:
	//		func has two data types that exist.
	// Basic Guarantee
	void traverse(std::function<void(key_type, data_type)> func) const
	{
		auto it = _head.get();
		while (it)
		{
			func(it->_data.first, it->_data.second);
			it = it->_next.get();
		}
	}

	// ***** Data Members *****
private:
	std::unique_ptr<LLNode2<std::pair<key_type, data_type>>> _head;

}; // End class SlowMap

#endif // FILE_DP6_H_INCLUDED