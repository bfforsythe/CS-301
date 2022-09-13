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

	std::string getName() const {
		return(productName);
	}
	int getQuantity() const {
		return(quantity);
	}


	void setName(std::string n) {productName = n;}
	void setQuantity(int i) {quantity = i;}

	bool empty() const {
		if (quantity == 0) {
			return (true);
		}
		else {
			return (false);
		}
	}

	std::string toString() const {
		cout << productName << " (" << quantity << ") " << endl;
	}


};

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
	COUT << inventory.toString();
}




#endif // !INVENTORY_HPP
