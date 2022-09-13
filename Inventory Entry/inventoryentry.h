#pragma once
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <iostream>


class InventoryEntry {
	std::string productName;
	int quantity;

public:


	InventoryEntry() { // Default Constructor
		productName = "NOT SPECIFIED";
		quantity = 0;
	}

	InventoryEntry(std::string name, int amnt) { // Parameterized Constructor
		productName = name;
		quantity = amnt;
	}

	// Getters
	std::string getName() const {
		return(productName);
	}
	int getQuantity() const {
		return(quantity);
	}

	// Setters
	void setName(std::string n) { productName = n; }
	void setQuantity(int i) { quantity = i; }

	bool empty() const {
		if (quantity == 0) {
			return (true);
		}
		else {
			return (false);
		}
	}

	// Will print out string of typed variables
	std::string toString() const {
		std::cout << getName() << " (" << getQuantity() << ") ";
	}




	InventoryEntry& operator++() // Pre-Inc
	{
		++quantity;
		return *this;
	}


	InventoryEntry operator++([[maybe_unused]] int dummy) // Post-Inc
	{

		auto save = *this;
		++(*this);
		return save;
	}


	InventoryEntry& operator--() // Pre-Dec
	{
		if (quantity > 1) {
			quantity--;
			return *this;
		}
		else {
			return *this;
		}
	}

	InventoryEntry operator--([[maybe_unused]] int dummy) // Post-Dec
	{
		auto save = *this;
		--(*this);
		return save;
	}

	

};

// Overloads


bool operator==(const InventoryEntry& lhs, const InventoryEntry & rhs) {
	if (lhs == rhs){
		return true;
	}
	else {
		return false;
	}
}


bool operator!=(const InventoryEntry& lhs, const InventoryEntry& rhs) {
	if (lhs != rhs) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream& operator <<(std::ostream& COUT, const InventoryEntry& inventory) {
	return COUT << inventory.getName() << " (" << inventory.getQuantity() << ")";
}




#endif // !INVENTORY_HPP
