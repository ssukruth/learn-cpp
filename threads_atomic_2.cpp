#include <iostream>
#include <atomic>
#include <chrono>
#include <thread>

std::atomic<bool> flag(false);

void t2() {
	while(!flag) {};
	std::cout << "t2: exiting" << std::endl;
}

void t1() {
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "t1: setting flag as true" << std::endl;
	flag = true;
}

int main() {
	std::thread T2(t2);
	std::thread T1(t1);
	T1.join();
	T2.join();
}
