#pragma once
#include <cstdint>

struct XorShift {
	uint32_t state;
	uint32_t a;
	uint32_t b;
	uint32_t c;

	XorShift(uint32_t seed = 1, uint32_t a = 13, uint32_t b = 17, uint32_t c = 5) : state(seed), a(a), b(b), c(c) {
		if (state == 0) state = 1;
	}

	uint32_t next() {
		uint32_t x = state;
		x ^= x << a;
		x ^= x >> b;
		x ^= x << c;
		state = x;
		return x;
	}

	uint32_t next(uint32_t min, uint32_t max) {
		return min + next() % (max - min);
	}
};