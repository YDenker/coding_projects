#include "bellNumber.h"
namespace funWithMaths {
	//Bell numbers count the number of ways to partition a set of n elements.They can be computed with dynamic programming or recursion.
	std::vector<long long> bellNumber(int n) {
        std::vector<long long> bell(n + 1, 0); // Vector to store Bell numbers
        bell[0] = 1; // Base case

        // Create a 2D array to store the values of binomial coefficients
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1; // C(i, 0) = 1
        }

        // Fill the dp table with binomial coefficients
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // C(i, j) = C(i-1, j-1) + C(i-1, j)
            }
        }

        // Calculate Bell numbers
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                bell[i] += dp[i - 1][j] * bell[j]; // Bell number relation
            }
        }

        return bell;
	}
}