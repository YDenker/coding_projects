// main.cpp 
#include "main.h" 
int main() { 
	int fromUnit;
	int toUnit;
	double inputTemperature;
	std::cout << "Please select from the possible units below by their id:\n";
	for (int i = 0; i < static_cast<int>(temperatures::TemperatureUnit::end); ++i) {
		std::cout << "[" << i << "] " << temperatures::toString(static_cast<temperatures::TemperatureUnit>(i)) << "\n";
	}
	std::cout << "FROM UNIT: ";
	std::cin >> fromUnit;
	std::cout << "TO UNIT: ";
	std::cin >> toUnit;

	if (!std::cin.good()) {
		std::cout << "SELECTION ERROR";
		return -1;
	}

	std::cout << "Selected:\nFROM " << temperatures::toString(static_cast<temperatures::TemperatureUnit>(fromUnit)) << " TO " << temperatures::toString(static_cast<temperatures::TemperatureUnit>(toUnit)) << "\nGive a value for " << temperatures::toString(static_cast<temperatures::TemperatureUnit>(fromUnit)) << ": ";
	std::cin >> inputTemperature;

	if (!std::cin.good()) {
		std::cout << "VALUE ERROR";
		return -1;
	}

	double result = temperatures::convertTemperature(inputTemperature, static_cast<temperatures::TemperatureUnit>(fromUnit), static_cast<temperatures::TemperatureUnit>(toUnit));

	std::cout << "\n" << temperatures::asUnit(inputTemperature, static_cast<temperatures::TemperatureUnit>(fromUnit)) << " = " << "\033[33m" << temperatures::asUnit(result, static_cast<temperatures::TemperatureUnit>(toUnit)) << "\033[0m" << "\n";

	return 0; 
}
