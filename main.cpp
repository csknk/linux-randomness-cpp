#include <iostream>
#include "random.h"

int main()
{
	// Initialise with a size_t n, generates vector with n random bytes.
	// ----------------------------------------------------------------
	Random r{10};
	for (auto& el : r.getRandomBytes())
		std::cout << (int)el << " ";
	std::cout << '\n';

	// Copy randomBytes member variable into the provided buffer.
	// ----------------------------------------------------------
	std::vector<unsigned char> buf(5);
	r.setRandomBytes();
	r.getRandomBytes(buf);

	std::cout << "Set buffer: \n";
	for (auto& el : buf)
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
