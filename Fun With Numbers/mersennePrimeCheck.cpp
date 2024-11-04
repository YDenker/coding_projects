#include "mersennePrimeCheck.h"
#include <cmath>
namespace funWithNumbers {
    //A Mersenne prime is a prime number that can be expressed in the form 2^p - 1 where p is also a prime number.
	bool isMersennePrime(long long n) {
        if (n < 1) return false; // Mersenne primes are greater than 0
        long long p = n + 1; // Mersenne form is n + 1 = 2^p

        // Check if n + 1 is a power of 2
        if ((p & (p - 1)) != 0) return false; // Not a power of 2

        // Find p such that 2^p = n + 1
        long long exponent = log2(p);

        // Check if exponent is prime
        return isPrime(exponent);
	}
}