#include <iostream>
#include "random.h"

int main()
{
	// Initialise with a size n, generates vector with n random bytes.
	// ---------------------------------------------------------------
	Random r{10};
	for (auto& el : r.getRandomBytes())
		std::cout << (int)el << " ";
	std::cout << '\n';

	std::vector<unsigned char> buf(5);
	r.setRandomBytes();
	r.getRandomBytes(buf);

	std::cout << "Set buffer: \n";
	for (auto& el : buf)
		std::cout << (int)el << " ";
	std::cout << '\n';
	
	// If initialised with a vector, fill vector with random values.
	// -------------------------------------------------------------
	std::vector<unsigned char> v(256);
	Random r2{v};
	
	std::cout << "printRandomBytes(v) =\n";
	r2.printRandomBytes(v);
	
	return 0;
}
