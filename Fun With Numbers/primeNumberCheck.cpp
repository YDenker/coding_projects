#include "primeNumberCheck.h"

namespace funWithNumbers {
	bool isPrime(long long n) {
        if (n <= 1) return false; // 0 and 1 are not prime numbers
        if (n <= 3) return true;  // 2 and 3 are prime numbers

        if (n % 2 == 0 || n % 3 == 0) return false; // Eliminate multiples of 2 and 3

        for (long long i = 5; i * i <= n; i += 6) { // check up to the squareroot of n
            if (n % i == 0 || n % (i + 2) == 0) return false; // Check for factors
        }
        return true;
    }
}