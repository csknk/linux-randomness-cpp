Access Pseudo-Random Bytes from /dev/urandom
============================================

Initialise with a Size
----------------------
Initialise the class with a `size_t` type n. This generates a vector with n random bytes.

```c++
Random r{10};
r.printRandomBytes(); // Prints the random bytes to stdout.
std::vector<unsigned char> randBytes = r.getRandomBytes(); // Assign random bytes to a vector.
```

Reset Pseudo Random Bytes
-------------------------
Call `setRandomBytes()` to reset random bytes held by the object:

```c++
r.setRandomBytes(); // Bytes have been refreshed.
```
Further calls to `getRandomBytes()` return different values.

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
