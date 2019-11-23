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
	std::cout << n << " random bytes sourced from /dev/urandom, displayed in hex:\n";
	r.printHex();

	std::cout << "Same random bytes, displayed as decimal integers:\n";
	for (auto& el : r.getRandomBytes())
		std::cout << (int)el << " ";
	std::cout << '\n';
	
	return 0;
}
