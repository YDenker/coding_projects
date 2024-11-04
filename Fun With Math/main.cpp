#include <iostream>
#include <conio.h>
#include <functional>
#include <array>
#include <string>
using std::string;

#include "funWithMathsIncludes.h"

using std::array;
using std::function;

static const int size = 7;
static const string funcName[size] = {"Fibonacci","Fibonacci sequence","Factorial","Collatz conjecture","Catalan numbers","Triangular numbers", "Bell numbers"};
static const array<function<std::vector<long long>(int)>, size> functions = {  funWithMaths::fibonacci, funWithMaths::fibonacciSequence, funWithMaths::factorial, funWithMaths::collatzSequence, funWithMaths::catalanNumber, funWithMaths::triangularNumber, funWithMaths::bellNumber };

static void print(std::vector<long long> sequence) {
    for (long long num : sequence) {
        std::cout << num << " ";
    }
    std::cout << "\n";
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
    int depth;
    std::cout << "Enter the value n for " << funcName[operation] << ": ";
    std::cin >> depth;
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