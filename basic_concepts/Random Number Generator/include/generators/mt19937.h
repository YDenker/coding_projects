#pragma once
#include <random>

struct MT19937 {
	std::mt19937 engine;

	MT19937(uint32_t seed = 1) : engine(seed){}

	uint32_t next() {
		return engine();
	}

	uint32_t next(uint32_t min, uint32_t max) {
		std::uniform_int_distribution<uint32_t> dist(min, max - 1);
		return dist(engine);
	}
};