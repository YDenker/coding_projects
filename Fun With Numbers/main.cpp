#include <iostream>
#include <conio.h>
#include <functional>
#include <array>
#include <string>
using std::string;

#include "funWithNumbersIncludes.h"

using std::array;
using std::function;

static const int size = 4;
static const string funcName[size] = { "Prime number check", "Palindrome number check","Perfect number check","Mersenne prime number check" };
static const array<function<bool(long long)>, size> functions = { funWithNumbers::isPrime, funWithNumbers::isPalindrome, funWithNumbers::isPerfect, funWithNumbers::isMersennePrime };

static void print(bool y) {
	if (y) std::cout << "TRUE\n";
	else std::cout << "FALSE\n";
}

static int mainLoop() {
    int operation;
    std::cout << "Please enter the number of the operation you would like to perform:\n";
    int i = 0;
    for (string name : funcName) {
        std::cout << i << " | " << name << "\n";
        i++;
    }
    std::cout << "------------------------------------------------------------------\nEnter Number: ";
    std::cin >> operation;
    if (!std::cin || operation >= size || operation < 0) {
        std::cout << "Invalid Value!\n";
        return -1;
    }
    int depth;
    std::cout << "Enter the value n for " << funcName[operation] << ": ";
    std::cin >> depth;
    if (!std::cin) {
        std::cout << "Invalid Value!\n";
        return -1;
    }
    std::cout << "Result:\n";
    print(functions[operation](depth));
    char c;
    std::cout << "\nTo restart press [T]. To exit press any other [Button]: ";
    c = _getch();
    if (c == 't' || c == 'T')
        return 0;
    else return -1;
}

int main() {
    int running = 0;
    while (running >= 0) {
        std::cout << "\n";
        running = mainLoop();
    }
    return 0;
}