// main.h 
#pragma once 
#include "generators/cstyle.h"
#include "generators/lcg.h"
#include "generators/xorshift.h"
#include "generators/mt19937.h"
#include "generators/splitmix.h"
#include "generators/pcg.h"
#include <string>
#include <iostream>

template <typename Generator>
void benchmark(uint32_t seed, std::string name);