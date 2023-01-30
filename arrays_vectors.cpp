#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_array(int arr[], int sz) {
	// int size = sizeof(arr)/sizeof(int); // sizeof(arr) => size of int pointer
	// cout << "size within function " << size << endl;
	for (int i=0; i < sz; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void print_vector(vector<int> v) {
	cout << "size of vector is " << v.size() << endl;
	for (auto i = v.begin(); i < v.end(); i++) {
		cout << *i << "\t";
	}
	cout << endl;
}

void range_print_vector(vector<int> v) {
	for (auto i: v ) {
		cout << i << "\t";
	}
	cout << endl;
}

void print_matrix(vector<vector<int>> m) {
	int r = m.size();
	int c = m[0].size();
	cout << "r=" << r << " c=" << c << endl;
	for (int i=0; i < r ; i++) {
		for (int j=0; j < c; j++) {
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
}

int main() {

	// Array
	// type name[size]
	// statically sized collection of elements
	int numbers[5];

	int nums[] = {1, 2, 3, 4, 5}; // initialize array
	cout << nums[3] << endl;
	nums[3] = 10;
	cout << nums[3] << endl;

	// no specific size method. need to figure out size by dividing size of collection with size of item in collection
	int size = sizeof(nums)/sizeof(int);

	for (int i = 0; i < size; i++) {
		numbers[i] = nums[i];
	}

	// Passing array to functions
	print_array(nums, size);


	// Vectors
	// vector<type> name
	// Dynamically sized collections of elements

	// vector methods:
	// empty() => checks if empty
	// size() => size of vector
	// push_back(item) => appends item to vector
	// pop_back() => removes last item in vector
	// begin() => iterator to the beginning of vector
	// end() => iterator to the end of vector
	// insert() => insert element at a particular index
	// clear() => destroys vector & sets size to 0
	// erase() => remove item at index
	vector<int> items;
	if (items.empty()) {
		cout << "empty vector" << endl;
	}
	for (int i = 0; i < 10; i++) {
		items.push_back((i*2)%7);
	}
	items.pop_back();
	items.insert(items.end(), 1, 10);
	print_vector(items);
	items.clear();
	print_vector(items);
	// push_back & insert tend to:
	// 1. create a new temp object
        // 2. resize the vector and copy the temp obj value to vector
        // 3. destroy the object
	// emplace_back on the other hand merely appends the item to the vector
	items.emplace_back(12);
	items.emplace_back(13);
	items.emplace_back(14);
	cout << items.front() << endl;
	cout << items.back() << endl;
	items.emplace_back(15);
	print_vector(items);
	items.erase(items.begin()+2);
	range_print_vector(items);
	int min = *std::min_element(items.begin(), items.end());
	int max = *std::max_element(items.begin(), items.end());
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;


	// 2D vector
	vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	print_matrix(matrix);
}
