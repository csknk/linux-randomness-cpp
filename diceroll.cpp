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
	return EXIT_SUCCESS;
}
