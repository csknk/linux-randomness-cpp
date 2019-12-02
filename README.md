Access Pseudo-Random Bytes from /dev/urandom
============================================

Initialise with a Size
----------------------
Initialise the `Random` object with `size_t n`.

Access a `std::vector<unsigned char>` that contains n random bytes using `getRandomBytes()`.

Member function `printHex()` prints random bytes in zero-padded hexadecimal format.

Member function `printInt()` prints random bytes in space-separated decimal format.

```c++
size_t n = 10;
Random r{n}; // Initialise with a size n
r.printInt(); // Prints n random bytes to stdout, decimal integers.
r.printHex(); // Prints n random bytes to stdout, hexadecimal format.
```

Initialise with a Buffer
------------------------
Initialise the `Random` object with a suitable buffer to fill the buffer with random bytes.

```c++
std::vector<unsigned char> randVec(10);
Random r(randVec); // randVec now has 10 random bytes
```

Get Random Bytes
----------------
Once the `Random` object has been initialised, get it's `randomBytes` member using `getRandomBytes()`.

Returns a `std::vector<unsigned char>` filled with random bytes.
 
```c++
std::vector<unsigned char> randBytes = r.getRandomBytes(); // Assign random bytes to a vector.
```

Reset Pseudo Random Bytes
-------------------------
Call `setRandomBytes()` to reset random bytes held by the object:

```c++
r.setRandomBytes(); // Bytes have been refreshed.
```
Next call to `getRandomBytes()` return different values.

Assign Pseudo Random Bytes to a Buffer
---------------------------------------
Passing a suitable buffer to `getRandomBytes()` populates the buffer with random bytes.

```c++
Random r;
std::vector<unsigned char> buf;
r.getRandomBytes(buf);
// buf now contains random bytes
for (auto& el : buf)
	std::cout << (int)el << " ";
std::cout << '\n';

// If initialised with a vector, fill vector with random values.
// -------------------------------------------------------------
std::vector<unsigned char> v(32);
Random r2{v};

std::cout << "printRandomBytes(v) =\n";
r2.printRandomBytes(v);

return 0;
}
```

Static Methods
--------------
### Get a Random Byte

```c++
unsigned char r = Random::getRandomByte();
std::cout << "r is a random byte, value " << (int)r << '\n';
```
