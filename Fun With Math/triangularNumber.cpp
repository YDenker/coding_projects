#include "triangularNumber.h"
namespace funWithMaths {
    // Triangular numbers are a sequence where the nth term represents the number of dots in an equilateral triangle with n dots on a side.
	std::vector<long long> triangularNumber(int n) {
        std::vector<long long> triangular(n + 1, 0); // Vector to store triangular numbers

        for (int i = 0; i <= n; ++i) {
            triangular[i] = i * (i + 1) / 2; // Calculate T_i
        }

        return triangular;
	}
}