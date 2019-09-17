#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>	// std::generate
#include <iomanip>
#include <sstream>

class Random
{
public:
	typedef std::vector<unsigned char>::iterator iterator;
	
	Random();
	Random(size_t nBytes);
	Random(std::vector<unsigned char>& buffer);
	void fillVector(std::vector<unsigned char>::iterator initial, std::vector<unsigned char>::iterator final);
	void setRandomBytes();
	void setRandomBytes(iterator start, iterator end);
	static void randomBuffer(iterator start, iterator end);
	static unsigned char getRandomByte();
	std::vector<unsigned char> getRandomBytes() const;
	void getRandomBytes(std::vector<unsigned char>& buffer) const;
	void printHex() const;
	static void printHex(const std::vector<unsigned char>& v);
	void printInt() const;
	static void printInt(const std::vector<unsigned char>& v);
	static void print(const std::vector<unsigned char>& v, int mode);
	static void setBuffer(std::vector<unsigned char>& v);

private:
	size_t nBytes;
	std::vector<unsigned char> randomBytes;
	enum PrintMode {HEX = 0, INT = 1};
};

class OpenFileException{};

#endif
