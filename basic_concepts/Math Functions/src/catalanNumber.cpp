#include "catalanNumber.h"

#include <vector>
namespace funWithMaths {
	//Catalan numbers are a sequence of natural numbers that have applications in combinatorial mathematics. The n-th Catalan number can be expressed directly in terms of the central binomial coefficients. To calculate this efficiently a recursive formular is used.
	std::vector<long long> catalanNumber(int n) {
        // Vector to store Catalan numbers up to C_n
        std::vector<long long> catalan(n + 1, 0);

        // Base case
        catalan[0] = 1;

        // Fill the catalan array using the recursive formula
        for (int i = 1; i <= n; ++i) {
            catalan[i] = 0;
            for (int j = 0; j < i; ++j) {
                catalan[i] += catalan[j] * catalan[i - 1 - j];
            }
        }
        return catalan;
	}
}