#include "fibonacci.h"
// Matrix multiplication function
static std::vector<std::vector<long long>> multiply(const std::vector<std::vector<long long>>& a, const std::vector<std::vector<long long>>& b) {
    std::vector<std::vector<long long>> result(2, std::vector<long long>(2));
    result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    result[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    result[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    return result;
}

// Matrix exponentiation function
static std::vector<std::vector<long long>> matrixPower(std::vector<std::vector<long long>> matrix, int n) {
    std::vector<std::vector<long long>> result = { {1, 0}, {0, 1} }; // Identity matrix
    while (n > 0) {
        if (n % 2 == 1) {
            result = multiply(result, matrix);
        }
        matrix = multiply(matrix, matrix);
        n /= 2;
    }
    return result;
}

namespace funWithMaths {

    // Function to get the nth Fibonacci number.
    // By representing the Fibonacci sequence in matrix form, you can compute the nth Fibonacci number by raising a transformation matrix to the power n-1. This approach uses matrix multiplication and fast exponentiation to compute the result efficiently.
    std::vector<long long> fibonacci(int n) {
        std::vector<long long> result;
        if (n == 0) {
            result.push_back(0);
            return result;
        }
        if (n == 1) {
            result.push_back(1);
            return result;
        }

        std::vector<std::vector<long long>> baseMatrix = { {1, 1}, {1, 0} };
        std::vector<std::vector<long long>> resultMatrix = matrixPower(baseMatrix, n - 1);

        result.push_back(resultMatrix[0][0]); // Top-left element is Fn
        return result; 
    }

    // Function to get all Fibonacci numbers up the the nth.
    // For the sequence an iterative approach makes more sense then a matrix exponentiation one, since we need the value from each iteration.
    std::vector<long long> fibonacciSequence(int n) {
        std::vector<long long> sequence;

        if (n < 0) return sequence; // Return empty vector for invalid depth

        long long a = 0, b = 1;
        sequence.push_back(a); // F(0)
        if (n >= 1) sequence.push_back(b); // F(1)

        for (int i = 2; i <= n; ++i) {
            long long c = a + b;
            sequence.push_back(c);
            a = b;
            b = c;
        }
        return sequence;
    }
}