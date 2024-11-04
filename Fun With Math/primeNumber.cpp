#include "primeNumber.h"
namespace funWithMaths {
	//Calculating Prime Numbers up to a specified number n using the Sieve of Eratosthenes algorithm, which is efficient for generating a list of primes.
	std::vector<long long> primeNumbers(int n) {
        if (n < 2) return {}; // Return an empty vector for numbers less than 2

        std::vector<bool> isPrime(n + 1, true); // Boolean array for prime checking
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

        // Sieve of Eratosthenes algorithm
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false; // Mark multiples of i as not prime
                }
            }
        }

        // Collecting all prime numbers
        std::vector<long long> primes;
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
	}
}