#include <iostream>
#include "random.h"

int main()
{
	int low, high, nRolls;
	std::cout << "Enter low: " << '\n';
	std::cin >> low;

	std::cout << "Enter high: " << '\n';
	std::cin >> high;

	std::cout << "Enter number of rolls: " << '\n';
	std::cin >> nRolls;

	int m = (high - low) + 1;
	std::cout << "modulo is " << m << '\n';

	std::vector<unsigned char> results;
	while (1) {
		unsigned char c = Random::getRandomByte();
		std::cout << "c is " << (int)c << '\n';
		if (!c % m)
			continue;
		if (c >= 255 - (255 % m))
			continue;
		results.push_back((c % m) + low);
		if (results.size() == (size_t)nRolls)
			break;
	}
	for (auto& el : results)
		std::cout << (int)el << " ";
	std::cout << '\n';
//	int ones = count(results.begin(), results.end(), 1);
//	int zeroes = count(results.begin(), results.end(), 0);
//	std::cout << "ones:\t" << ones << '\n' << "zeroes:\t" << zeroes << '\n';
	return 0;
	// Initialise with a size_t n, generates vector with n random bytes.
	// ----------------------------------------------------------------
	Random r{10};
	for (auto& el : r.getRandomBytes())
		std::cout << (int)el << " ";
	std::cout << '\n';

	// Copy randomBytes member variable into the provided buffer.
	// ----------------------------------------------------------
	std::vector<unsigned char> buf(5);
//	r.setRandomBytes(); // Reset random buffer with fresh bytes
	r.getRandomBytes(buf);

	
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
