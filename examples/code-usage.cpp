#include <iostream>
#include "random.h"
#include <limits>

int main()
{
	// Initialise with a size_t n, generates vector with n random bytes.
	// ----------------------------------------------------------------
	size_t n = 32;
	Random r{n};
	std::cout << n << " random bytes sourced from /dev/urandom, displayed in hex:\n";
	r.printHex();

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
