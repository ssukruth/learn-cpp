#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
// atomic needs c++ 17

static std::atomic<int> shared_int = 0;

void atomic_increment_shared_value() {
	shared_int++; // shared_int += 1 works to but not shared_int = shared_int + 1
}

int main() {
	std::vector<std::thread> threads;
	for (int i=0; i < 10; i++) {
		threads.push_back(std::thread(atomic_increment_shared_value));
	}
	for (auto &t : threads) {
		t.join();
	}
	std::cout << "Shared int: " << shared_int << std::endl;
}
