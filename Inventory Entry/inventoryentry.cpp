#include "inventoryentry.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// Overloads

bool operator==(const InventoryEntry& lhs, const InventoryEntry& rhs) {
	if (lhs.getQuantity() == rhs.getQuantity() && lhs.getName() == rhs.getName()) {
		return true;
	}
	else {
		return false;
	}
}


bool operator!=(const InventoryEntry& lhs, const InventoryEntry& rhs) {
	if (lhs.getName() != rhs.getName() || lhs.getQuantity() != rhs.getQuantity()) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream& operator <<(std::ostream& COUT, const InventoryEntry& inventory) {
	return COUT << inventory.getName() << " (" << inventory.getQuantity() << ")";
}
