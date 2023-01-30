#include <iostream>
#include <future>
#include <thread>
#include <chrono>


bool background_thread_fn(int x) {
	for (int i = 0; i < x; i++) {
		std::cout << "Background: " << i*i << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return true;
}

int main() {
	std::future<bool> background_thread = std::async(std::launch::async, background_thread_fn, 30);
	std::future_status status;
	while (true) {
		std::cout << "Main thread is running" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		// use wait_for to get background thread status.
		status = background_thread.wait_for(std::chrono::seconds(1));
		if (status == std::future_status::ready) {
			std::cout << "Background thread is done" << std::endl;
			break;
		}
	}
}
