#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

static int shared_int = 0;
std::mutex gLock;

// This causes a deadlock as the first thread to acquire the lock
// will exit without releasing the lock
void deadlock_shared_increment() {
	gLock.lock();
		try {
			shared_int = shared_int + 1;
			throw "induced exception";
		} catch (...) {
			// std::cout << "Exception occurred";
			return;
		}
	gLock.unlock();
}

// Use lock_guard. This is RAII styled i.e. Resource acquisition is initialization
// This means that when the lock_guard exits the scope, a destructor is called which
// will release the lock.
void lock_guard_shared_increment() {
	std::lock_guard<std::mutex> gLock_guard(gLock); // lock gets acquired
	try {
		shared_int = shared_int + 1;
		throw "induced exception";
	} catch (...) {
		// std::cout << "Exception occurred";
		return;
	}
	// lock gets released as part of lock guard exiting the scope
}

int main() {
	std::vector<std::thread> threads;
	for (int i=0; i < 10; i++) {
		threads.push_back(std::thread(lock_guard_shared_increment));
	}
	for (auto &t : threads) {
		t.join();
	}
	std::cout << "Shared int: " << shared_int << std::endl;
}
