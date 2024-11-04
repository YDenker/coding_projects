#include "collatzConjecture.h"

namespace funWithMaths {
	//For a given number n, if n is even, divide it by 2; if n is odd, multiply it by 3 and add 1. Repeat this process until you reach 1.
	std::vector<long long> collatzSequence(int n) {
        std::vector<long long> sequence;
        if (n <= 0) return sequence; // Return an empty vector for non-positive integers

        while (n != 1) {
            sequence.push_back(n);
            if (n % 2 == 0) {
                n /= 2; // Even
            }
            else {
                n = 3 * n + 1; // Odd
            }
        }
        sequence.push_back(1); // Add the final 1 to the sequence

        return sequence;
	}
}