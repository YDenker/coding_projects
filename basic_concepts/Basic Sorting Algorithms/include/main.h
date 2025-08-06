// main.h 
#pragma once

#include <vector>
#include <string>

struct SortStats {
	size_t comparisions = 0;
	size_t swaps = 0;
};

SortStats bubbleSort(std::vector<int>& arr);
SortStats insertionSort(std::vector<int>& arr);
SortStats selectionSort(std::vector<int>& arr);

template <typename Func>
SortStats benchmark(const std::vector<int>& data, Func sortFunc, const std::string& name, bool printResult);

std::vector<int> generateRandomVector(size_t, int min, int max);
