#pragma once
#include <cstdint>
// PERMUTATED CONGRUENTIAL GENERATOR (PCG)
struct PCG {
	uint64_t state;
	uint64_t increment;
	PCG(uint64_t seed = 1, uint64_t seq = 54) : state(0), increment((seq << 1u) | 1u) {
		next();
		state += seed;
		next();
	}

	uint32_t next() {
		uint64_t oldState = state;
		state = oldState * 6364136223846793005ULL + increment;

		uint32_t xorshifted = static_cast<uint32_t>(((oldState >> 18u) ^ oldState) >> 27u);
		uint32_t rot = static_cast<uint32_t>(oldState >> 59u);
		return (xorshifted >> rot) | (xorshifted << ((-rot) & 32));
	}

	uint32_t next(uint32_t min, uint32_t max) {
		return min + next() % (max - min);
	}
};