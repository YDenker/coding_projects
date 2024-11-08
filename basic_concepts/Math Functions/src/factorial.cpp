#include "factorial.h"
namespace funWithMaths {
    std::vector<long long> factorial(int n) {
        std::vector<long long> result;
        if (n < 0) {
            result.push_back(-1);
            return result;
        }; // Error case for negative numbers
        long long tmp = 1;
        for (int i = 1; i <= n; ++i) {
            tmp *= i;
        }
        result.push_back(tmp);
        return result;
    }
}