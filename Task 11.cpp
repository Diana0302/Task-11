#include <iostream>
#include <fstream>
#include <vector>
#include <string>

enum Sorting {
	BUBBLE_SORT,
	SELECTION_SORT
};

struct SortingOption {
	Sorting val;
	void (*foo)(int*, int);
};


std::vector<int> read(const std::string& file_name) {
	std::vector<int> k;
	int value;
	std::ifstream input_file(file_name);
	if (input_file.is_open()) {
		while (input_file >> value) {
			k.push_back(value);
		}
		input_file.close();
	}
	else {
		std::cout << "Error" << std::endl;
	}
	return k;
}

void write(const std::string& file_name, std::string& s)
{
	std::fstream myfile;
	myfile.open(file_name, std::ios::out);
	if (myfile.is_open()) {
		myfile << s << std::endl;
		myfile.close();
	}
}
void save(const std::vector<int>& arr, const std::string& file_name) {
	std::ofstream output_file(file_name);
	if (!output_file.is_open()) {
		std::cout << "Error " << file_name << std::endl;
		return;
	}
	for (auto i = arr.begin(); i != arr.end(); ++i) {
		output_file << *i << " ";
	}
	output_file.close();
	std::cout << "Save Sorted array: " << file_name << std::endl;
}



void BubbleSorting(int* arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void SelectionSorting(int* arr, int size) {
	int min;
	for (int i = 0; i < size - 1; ++i) {
		min = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] > arr[min]) {
				min = j;
			}
			std::swap(arr[j], arr[min]);
		}
	}
}

int main()
{
	std::string file_name = "my_file.txt";
		std::vector<int,std::allocator<int>> array = read(file_name);
	for (auto i = array.begin(); i != array.end(); ++i) {
		std::cout << *i << " ";
	}
	const int size = 2;
	SortingOption arr[size];
	int a;
	std::cout << "if you want to see bubble sorting algorithm choose 1, else 2" << std::endl;
	std::cin >> a;
	std::string s = "Hello world";
	write(file_name, s);
	std::cout << "It's my file" << std::endl;
	read(file_name);
	std::vector<std::string> lines;
	std::string line;
	arr[0].val = BUBBLE_SORT;
	arr[0].foo = BubbleSorting;
	arr[1].val = SELECTION_SORT;
	arr[1].foo = SelectionSorting;
    std::cout << "Array" << std::endl;
	for (int j = 0; j < size; ++j) {
		std::cout << "Enter the " << j << "st SortingStrategy " << std::endl;
	//	arr[j].foo(array);
		for (auto i = array.begin(); i != array.end(); ++i) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
	save(array, file_name);
	return 0;
}
