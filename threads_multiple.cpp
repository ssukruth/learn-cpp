#include <iostream>
#include <thread>
#include <vector>

std::mutex m;

void print_arg(int i) {
	m.lock();
	std::cout << "Thread [" << std::this_thread::get_id() << "] got the arg: " << i << std::endl;
	m.unlock();
}

int main() {
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; i++) {
		threads.push_back(std::thread(&print_arg, i*i));
	}

	for(auto &t: threads) {
		t.join();
	}
}
