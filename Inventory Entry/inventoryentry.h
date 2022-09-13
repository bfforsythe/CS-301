#pragma once
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <iostream>

class InventoryEntry {
private:
	std::string productName;
	int quantity;

public:

	InventoryEntry() {
		productName = "NOT SPECIFICED";
		quantity = 0;
	}

	InventoryEntry(std::string name, int amnt) {
		productName = name;
		quantity = amnt;
	}

	std::string getName() {
		return(productName);
	}
	int getQuantity() {
		return(quantity);
	}


	void setName(std::string n) {productName = n;}
	void setQuantity(int i) {quantity = i;}

	bool empty() {
		if (quantity == 0) {
			return (true);
		}
		else {
			return (false);
		}
	}

	std::string toString() {
		cout << productName << " (" << quantity << ") " << endl;
	}
};


#endif // !INVENTORY_HPP
