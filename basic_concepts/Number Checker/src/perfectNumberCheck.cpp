#include "perfectNumberCheck.h"

namespace funWithNumbers {
	bool isPerfect(long long n) {
        if (n <= 1) return false; // 0 and 1 are not perfect numbers

        int sum = 0;
        // Find all divisors and sum them
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i == 0) {
                sum += i; // Add proper divisor
            }
        }

        return sum == n; // Check if sum of divisors equals the number
	}
}