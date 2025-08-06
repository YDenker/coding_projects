// main.cpp 
#include "main.h" 

template <typename Generator>
void benchmark(uint32_t seed, std::string name) {
	Generator rng(seed);

	std::cout << name << ": ";
	for (int i = 0; i < 10; ++i) {
		std::cout << rng.next() << ", ";
	}
	std::cout << "\n";
}



int main() {
	benchmark<CRand>(123, "C-Type Randomizer");
	benchmark<LCG>(123, "Linear Congruential Generator");
	benchmark<XorShift>(123, "XorShift32");
	benchmark<MT19937>(123, "MT19937");
	benchmark<SplitMix>(123, "SplitMix");
	benchmark<PCG>(123, "Permuted Congruential Generator");

	return 0;
}
