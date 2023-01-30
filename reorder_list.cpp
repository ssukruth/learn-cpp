#include <iostream>
#include <vector>

int main() {
	std::vector<int> v = {1, 3, 5, 7, 28, 2, 4, 9, 6};
	int next_even = 0;
	int next_odd = v.size() - 1;
	while (next_even < next_odd) {
		if (v[next_even] % 2 == 0) {
			next_even++;
		} else {
			std::swap(v[next_even], v[next_odd]);
			next_odd--;
		}
	}
	for (auto &i: v) {
		std::cout << i << "\t";
	}
	std::cout << "\n";
}
