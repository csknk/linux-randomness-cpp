#include <iostream>
#include "random.h"
#include <limits>

int main()
{
	// Initialise with a size_t n, generates vector with n random bytes.
	// ----------------------------------------------------------------
	std::cout << "Please enter the number of random bytes required:\n";
	size_t n;
	while(!(std::cin >> n)) {
		std::cout << "Please enter an unsigned integer.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	Random r{n};
	r.printHex();

	for (auto& el : r.getRandomBytes())
		std::cout << (int)el << " ";
	std::cout << '\n';

	// If initialised with a vector, fill vector with random values.
	// -------------------------------------------------------------
	std::vector<unsigned char> v(8);
	Random r2{v};
	r2.printHex(v);
	r2.printInt(v);
	std::cout << "r2.printHex(): ";
	r2.printHex(); // Prints the randomBytes member variable - empty.

	// Populate a buffer with random bytes statically.
	// ----------------------------------------------
	std::vector<unsigned char> s(10);
	Random::setBuffer(s);
	std::cout << "Static method: ";
	Random::printHex(s);
	
	return 0;
}
