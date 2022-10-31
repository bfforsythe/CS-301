// Brandon Forsythe
// 10/30/22
// TESArray.cpp
// This is a templated class to satisfy requirements for HW5.


// (Invariants given in class, most of the ideas here courtesy of Glenn Chappell, 2022).
// Almost this entire template is based off of what was written for CS311, circa 2022.

#ifndef TESARRAY_H
#define TESARRAY_H
#include <cstddef>		// For std::size_t
#include <algorithm>	// For std::max

// ----------------- TES Array Class -----------------
// Invariants:
//		0 <= _size <= _capacity
//		_data points to an array of value_type, allocated with new [],
//		owned by *this, holding _capacity value_type values -- UNLESS
//		_capacity == 0, in which case _data may be nullptr.


template <typename T>
class TESArray {

    // ***** TESArray: Types *****
public:

    // value_type: type of data items
    using value_type = T;

    // size_type: type of sizes & indices
    using size_type = std::size_t;

    // iterator, const_iterator: random-access iterator types
    using iterator = value_type*;
    using const_iterator = const value_type*;

    // ***** TESArray: Internal-Use Constants *****
private:

    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 16 };

    // ***** TESArray: Constructors, Destructors, op= *****
public:

    // Default constructor and constructor from size
    // Strong Guarantee
    explicit TESArray(size_type size = 0)
        :_capacity(std::max(size, size_type(DEFAULT_CAP))),
        // _capacity must be declared before _data
        _size(size),
        _data(_capacity == 0 ? nullptr 
                             : new value_type[_capacity])
    {}

    // Copy constructor
    // Strong Guarantee
    // Pre:
    //	  TESArray object must exist in order to continue.
    TESArray(const TESArray& other) :
        _size(other.size()),
        _data(new value_type[other._capacity]),
        _capacity(other._capacity)
    {
        try
        {
            std::copy(other.begin(), other.end(), begin());
        }
        catch (...)
        {
            this->~TESArray();
            throw;
        }
    }

    // Move constructor
    // No-Throw Guarantee ( Move CANNOT throw )
    // Pre:
    //	TESArray object must exist in order to continue.
    TESArray(TESArray&& other) noexcept : _size(other.size()), _data(other._data)
    {
        other._size = 0;
        other._data = nullptr;
    }

    // Copy assignment
    // Strong Guarantee (  )
    // Pre:
    //	TES Array object must exist in order to continue.
    TESArray& operator=(const TESArray& other)
    {
        TESArray oldArray(other);
        swap(oldArray);
        return *this;
    }

    // Move assignment
    // No-Throw Guarantee
    // Pre:
    //	TESArray object must exist in order to continue.
    TESArray& operator=(TESArray&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }
        swap(other);
        return *this;
    }

    // Deconstructor
    // No-Throw Guarantee ( Destructors can NOT throw )
    ~TESArray()
    {
        delete[] _data; // deletes all to ensure no overflow.
    }



    // ***** TESArray: General Public Operators *****
public:

    // operator[] - non-const & const
    // Pre:
    //	 0 >= index
    //   index <= _size
    // 
    // No-Throw Guarantee
    value_type& operator[](size_type index) noexcept
    {
        return _data[index];
    }
    const value_type& operator[](size_type index) const noexcept
    {
        return _data[index];
    }

    // ***** TESArray: General Public Functions *****
public:

    // size
    // No-Throw Guarantee 
    size_type size() const noexcept
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    bool empty() const noexcept
    {
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin() noexcept
    {
        return _data;
    }
    const_iterator begin() const noexcept
    {
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end() noexcept
    {
        return begin() + size();
    }
    const_iterator end() const noexcept
    {
        return begin() + size();
    }

    // resize
    // Strong Guarantee (  )
    // Pre:
    //	newsize can't be zero, or negative.
    void resize(size_type newsize)
    {
        if (newsize <= _capacity)
        {
            _size = newsize;
        }
        else
        {
            size_type newCapacity = std::max(2 * _capacity, newsize);
            value_type* temp = new value_type[newCapacity];
            try
            {
                std::copy(begin(), end(), temp);
            }
            catch (...)
            {
                delete[] temp;
                throw;
            }
            delete[] _data;

            std::swap(_capacity, newCapacity);
            std::swap(_size, newsize);
            std::swap(_data, temp);
        }
    }

    // insert
    // Basic Guarantee
    // Pre:
    //	Position is within TESArray size
    //	Item is of correct value_type
    iterator insert(iterator pos,
        const value_type& item)
    {
        size_type index = pos - begin();
        resize(_size + 1);
        iterator it1 = begin() + index;
        _data[_size - 1] = item;

        try
        {
            std::rotate(it1, begin() + _size - 1, end()); // attempting this syntax.
        }
        catch (...)
        {
            resize(_size - 1);
            throw;
        }

        return it1;
    }

    // erase
    // Strong Guarantee (  )
    // Pre:
    // 	Position is within TESArray size
    iterator erase(iterator pos)
    {
        std::rotate(pos, pos + 1, end());
        resize(_size - 1);
        return pos;
    }

    // push_back
    // Strong Guarantee (  )
    // Pre:
    //	Item is of correct value_type
    void push_back(const value_type& item)
    {
        insert(end(), item);
    }

    // pop_back
    // Strong Guarantee (  )
    void pop_back()
    {
        erase(end() - 1);
    }

    // swap
    // No-Throw Guarantee
    // Pre:
    //	TESArray must be the same size of whatever is being swapped.
    void swap(TESArray& other) noexcept
    {
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
        std::swap(_data, other._data);
    }

    // ***** TESArray: Data Members *****
private:

    // Below, _capacity must be declared before _data
    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type* _data;      // Pointer to our array

}; // End class TESArray

#endif // #ifndef FILE_TFSARRAY_H_INCLUDED