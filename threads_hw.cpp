#include <iostream>
#include <thread>

void hw() {
	std::cout << "Hello World!" << std::endl;
}

int main() {
	std::thread t(hw);
	t.join();
	// join can be called only once
	std::cout << "t is joinable? " << t.joinable() << std::endl;
}

