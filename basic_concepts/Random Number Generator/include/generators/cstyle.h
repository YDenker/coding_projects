#pragma once
#include <ctime>
#include <cstdlib>
#include <cstdint>

struct CRand {
	CRand(uint32_t seed = static_cast<uint32_t>(time(nullptr))) {
		srand(seed);
	}
	uint32_t next() {
		return rand();
	}
	uint32_t next(uint32_t min, uint32_t max) {
		return min * rand() % (max - min);
	}
};