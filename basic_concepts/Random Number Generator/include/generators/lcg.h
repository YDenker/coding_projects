#pragma once
#include <cstdint>
// LINEAR CONGRUENTIAL GENERATOR (LCG)
struct LCG {
	uint32_t state;
	uint32_t multiplier;
	uint32_t increment;
	LCG(uint32_t seed = 1, uint32_t multiplier = 1664525, uint32_t increment = 1013904223) : state(seed), multiplier(multiplier), increment(increment) {}

	uint32_t next() {
		state = multiplier * state + increment;
		return state;
	}

	uint32_t next(uint32_t min, uint32_t max) {
		return min + next() % (max - min);
	}
};