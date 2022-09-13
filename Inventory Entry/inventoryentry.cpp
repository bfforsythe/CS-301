#include "inventoryentry.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


int main(int argc,
	char* argv[]) {

	// Prints Greens (100); 

	InventoryEntry input;

	input.setName("Greens");
	input.setQuantity(100);


	input.toString();

}