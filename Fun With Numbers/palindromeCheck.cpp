#include "palindromeCheck.h"
#include <sstream>
#include <string>

namespace funWithNumbers {
    bool isPalindrome(long long n) {
        // Convert to string for palindrome check
        std::stringstream ss;
        ss << n;
        std::string str = ss.str();
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false; // Characters do not match
            }
            left++;
            right--;
        }
        return true; // All characters matched
    }
}