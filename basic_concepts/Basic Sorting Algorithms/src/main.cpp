// main.cpp 
#include "main.h"
#include <iostream>
#include <print>
#include <algorithm>
#include <random>
#include <chrono>

SortStats bubbleSort(std::vector<int>& arr) {
	SortStats stats;
	for (size_t i = 0; i < arr.size(); ++i) {
		bool swapped = false;
		for (size_t j = 0; j < arr.size() - i - 1; ++j) {
			++stats.comparisions;
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				++stats.swaps;
				swapped = true;
			}
		}
		if (!swapped) break;
	}
	return stats;
}

SortStats insertionSort(std::vector<int>& arr) {
	SortStats stats;
	for (size_t i = 1; i < arr.size(); ++i) {
		int key = arr[i];
		size_t j = i;
		while (j > 0) {
			++stats.comparisions;
			if (arr[j - 1] > key) {
				arr[j] = arr[j - 1];
				++stats.swaps;
				--j;
			}
			else {
				break;
			}
		}
		arr[j] = key;
	}
	return stats;
}

SortStats selectionSort(std::vector<int>& arr) {
	SortStats stats;
	for (size_t i = 0; i < arr.size(); ++i) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < arr.size(); ++j) {
			++stats.comparisions;
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		if (i != minIndex) {
			std::swap(arr[i], arr[minIndex]);
			++stats.swaps;
		}
	}
	return stats;
}

template <typename T>
void print(const std::vector<T>& arr) {
	for (const T& item : arr)
		std::cout << item << ", ";
	std::cout << "\n";
}

template <typename Func>
SortStats benchmark(const std::vector<int>& data, Func sortFunc, const std::string& name, bool printResult) {
	std::vector<int> arr = data;
	auto start = std::chrono::high_resolution_clock::now();
	SortStats stats = sortFunc(arr);
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> duration = end - start;
	if (printResult) {
		std::cout << name << " Sorted: ";
		print(arr);
	}
	std::cout << name << " took " << duration.count() << " ms\n";
	std::cout << "Comparision: " << stats.comparisions << ", Swaps: " << stats.swaps << "\n\n";
	return stats;
}

std::vector<int> generateRandomVector(size_t size, int min = 0, int max = 10000) {
	std::vector<int> vec(size);
	std::random_device rd;
	std::mt19937 gen(rd()); //Mersenne Twister RNG
	std::uniform_int_distribution<> dist(min, max);

	for (size_t i = 0; i < size; ++i) {
		vec[i] = dist(gen);
	}
	return vec;
}

int main() {
	std::vector<int> data = { 9218, 142, 124124, 1431, 1425, 6264, 642, 124, 5235, 12, 4, 5, 61, 1, 2, 3 };
	std::cout << "Original ";
	print(data);
	benchmark(data, bubbleSort, "Bubble Sort", true);
	benchmark(data, selectionSort, "Selection Sort", true);
	benchmark(data, insertionSort, "Insertion Sort", true);

	size_t length;
	std::cout << "\nInsert size of vector for larger stress test. (WARNING 1000 is already really slow!!)" << "\nN: ";
	std::cin >> length;

	std::vector<int> largeData = generateRandomVector(length);
	benchmark(largeData, bubbleSort, "Bubble Sort", false);
	benchmark(largeData, selectionSort, "Selection Sort", false);
	benchmark(largeData, insertionSort, "Insertion Sort", false);

	return 0; 
} 
