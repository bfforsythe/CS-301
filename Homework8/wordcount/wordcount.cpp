// Brandon Forsythe
// CS311 - Homework 8 problem 'A'
// Created and finished 12/2/22

// Note: I also tested this with a copy of "20,000 Leagues Under the Sea" which seemed to work well.
// Also, the word "navigate" only appears 31 times in the whole book. How about that.


#include <iostream>
#include <string> 	// std::string, std::getline
using std::string;
#include <fstream> 	// std::fstream
#include <map>
#include <set>

int main ()
{
	std::fstream readIn;
	string readFile;
	

	// repeats until a .txt is actually found (.txt must be inside of project)
	while (true)
	{
		std::cout << "Please input the name of your Text: (Include '.txt') \n";
		std::getline(std::cin, readFile);
		readIn.open(readFile);

		// If readFile opens correctly exit loop.
		if (readIn.is_open())
		{
			break;
		}

		else {
			std::cout << "Invalid file, please try again\n\n";
		}
	}

	string current;
	string next;
	std::map<string, std::set<string>> wordmap;
	std::map<string, int> countItr;


	if (readIn.is_open()) // Check to make sure readIn actually has something open
	{
		while (true)
		{
			if (current == "") // if space, push one word past
			{
				readIn >> current;
			}

			readIn >> next; // push into next

			if (!readIn)
			{
				if (readIn.eof())
				{
					wordmap[current].insert("");
					break;
				}
				else {
					exit(1);
				}
			}
			wordmap[current].insert(next);
			countItr[current] += 1;
			current = next;
		}
	}
	else {
		std::cout << "Invalid file, please try again." << std::endl;

	}

	std::cout << "Distinct words: " << wordmap.size() << std::endl;
	std::cout << std::endl;
	for (auto it = countItr.begin(); it != countItr.end(); it++) {
		std::cout << it->first << ": " << it->second << std::endl;
	}

}