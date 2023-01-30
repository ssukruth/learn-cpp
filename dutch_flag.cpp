#include <iostream>
#include <vector>

void dutch_flag_primitive(std::vector<int> &v, int pivot) {

	int small = 0;
	for (int i=0; i < v.size(); i++) {
		if (v[i] < pivot) {
			std::swap(v[i], v[small]);
			small++;
		}
	}

	int large = v.size() - 1;
	for (int i=v.size()-1; i >= 0; i--) {
		if (v[i] > pivot) {
			std::swap(v[i], v[large]);
			large--;
		}
	}
}

void dutch_flag(std::vector<int> &v, int pivot) {
	int small = 0;
	int equal = 0;
	int large = v.size() - 1;

	while (equal < large) {
		if (v[equal] < pivot) {
			std::swap(v[small], v[equal]);
			small++;
			equal++;
		} else if (v[equal] == pivot) {
			equal++;
		} else {
			std::swap(v[large], v[equal]);
			large--;
		}
	}

}

int main() {
	std::vector<int> v = {1,4,3,2,2,3,4,1,3,2,4,1,3,2,4,1};

	std::cout << "Before: ";
        for (auto &i : v) {
                std::cout << i << "\t";
        }
        std::cout << std::endl;

	dutch_flag(v, 2);
	dutch_flag(v, 3);

	std::cout << "After: ";
	for (auto &i : v) {
		std::cout << i << "\t";
	}
	std::cout << std::endl;
}
