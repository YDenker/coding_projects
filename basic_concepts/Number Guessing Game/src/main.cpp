// main.cpp 
#include "main.h" 
int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Define the range for the random number
    const int minNumber = 1;
    const int maxNumber = 100;
    int randomNumber = std::rand() % (maxNumber - minNumber + 1) + minNumber;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have chosen a number between " << minNumber << " and " << maxNumber << "." << std::endl;

    // Game loop
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess == randomNumber) {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
            break;
        }
        else if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        }
        else {
            std::cout << "Too high! Try again." << std::endl;
        }
    }
    return 0;
} 
