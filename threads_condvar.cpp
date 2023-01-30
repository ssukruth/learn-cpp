#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex gLock;
std::condition_variable gcv;
int result = 0;
bool notified = false;

void work() {
	std::unique_lock<std::mutex> ul(gLock);
	result = 42;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	notified = true;
	std::cout << "Work done" << std::endl;
	gcv.notify_one(); // Wake up one thread waiting on this CV
}

void report() {
	std::unique_lock<std::mutex> ul(gLock);
	if (!notified) { // it is okay to use if since there's only one consumer but if there are multiple then while is recommended
		gcv.wait(ul); // wait until condition is true. causes current thread to block and unlocks the lock provided.
	}
	std::cout << "Reporter result: " << result << std::endl;
}

int main() {
	std::thread reporter(report);
	std::thread worker(work);
	reporter.join();
	worker.join();
	std::cout << "Program completed" << std::endl;
}
