// main.cpp 
#include "main.h" 

int binarySearch(const std::vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;
	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

template <typename T>
void print(const std::vector<T>& arr) {
	for (const T& item : arr)
		std::cout << item << ", ";
	std::cout << "\n";
}


int main() {
	std::vector<int> data = { 10,5,2,8,3,7,11,13,16,19,20 };
	std::sort(data.begin(), data.end());
	int target;

	std::cout << "Enter a number to search in the array: ";
	print(data);
	std::cout << "Target: ";
	std::cin >> target;

	int result = binarySearch(data, target);

	if (result != -1)
		std::cout << "Found at index: " << result << std::endl;
	else
		std::cout << "Not found\n";

	return 0;
} 
