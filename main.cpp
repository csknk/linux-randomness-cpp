#include <iostream>
#include "random.h"

#define LINEBREAK std::cout << "--------\n";

int main()
{
	
	unsigned char rByte = Random::getRandomByte();
	std::cout << "Get a single random byte using static method: " << (int)rByte << '\n';
	LINEBREAK;

	// Initialise with a size_t n, generates vector with n random bytes.
	// ----------------------------------------------------------------
	Random r{10};
	std::cout << "Initialise with a size:\n";
	r.printInt();
	r.setRandomBytes(); // Reset random buffer with fresh bytes
	std::cout << "Reset the random buffer with fresh bytes: setRandomBytes()\n";
	r.printHex();
	r.printInt();
	std::cout << "Custom output:\n";
	for (auto& el: r.getRandomBytes()) {
		std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)el;
	}
	std::cout << '\n';

	LINEBREAK;

	// If initialised with a suitable vector, fill vector with random values.
	// ----------------------------------------------------------------------
	std::vector<unsigned char> buf(5);
	Random r2(buf);
	std::cout << "Insert random bytes into buffer:\n";	
	for (auto& el : buf)
		std::cout << (int)el << " ";
	std::cout << '\n';
	std::cout << "Print using static methods:\n";
	Random::printInt(buf);
	Random::printHex(buf);
	LINEBREAK;
	
	// Populate a buffer with random bytes statically.
	// ----------------------------------------------
	std::cout << "Populate a buffer with random bytes statically.\n";
	std::vector<unsigned char> s(10);
	Random::setBuffer(s);
	Random::printHex(s);
	
	return 0;
}
