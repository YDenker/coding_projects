#pragma once
#include <cstdint>

struct SplitMix {
	uint64_t state;

	SplitMix(uint64_t seed = 1) : state(seed) {}

	uint64_t next64() {
		uint64_t z = (state += 0x9E3779B97F4A7C15ULL);
		z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
		z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
		return z ^ (z >> 31);
	}

	uint32_t next() {
		return static_cast<uint32_t>(next64() >> 32);
	}

	uint64_t next64(uint64_t min, uint64_t max) {
		return min + next() % (max - min);
	}

	uint32_t next(uint32_t min, uint32_t max) {
		return min + next() % (max - min);
	}
};