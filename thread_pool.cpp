#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <functional>
#include <chrono>

#define MAX_THREADS 10
class ThreadPool {
	public:
		void QueueJob(const std::function<void()>& job);
		void Start();
		void Stop();
		void busy();
	private:
		bool should_terminate;
		void ThreadLoop(); // Loop run within each thread
		std::mutex q_lock; // lock on the queue
		std::condition_variable q_condvar; // condition variable
		std::vector<std::thread> threads; // pool of threads
		std::queue<std::function<void()>> jobs;
};

void ThreadPool::Start() {
	for(int i=0; i < MAX_THREADS; i++) {
		threads.push_back(std::thread(&ThreadPool::ThreadLoop, this));
	}
}

void ThreadPool::ThreadLoop() {
	//std::cout<< "TID: " << std::this_thread::get_id() << " started" << std::endl;
	while(true) {
		//std::cout<< "TID: " << std::this_thread::get_id() << " looping" << std::endl;
		std::function<void()> job;
		{
			std::unique_lock<std::mutex> ul(q_lock);
			// wait until you get new jobs or you're asked to terminate
			while(jobs.empty() && !should_terminate) {
				q_condvar.wait(ul);
			}
			if (should_terminate && jobs.empty()) {
				//std::cout<< "TID: " << std::this_thread::get_id() << " jobs size " << jobs.size() << std::endl;
				//std::cout<< "TID: " << std::this_thread::get_id() << " ended" << std::endl;
				return;
			}
			job = jobs.front();
			jobs.pop();
			std::cout<< "Dequed a job" << std::endl;
		}
		job();
	}
}

void ThreadPool::QueueJob(const std::function<void()>& job) {
	std::unique_lock<std::mutex> ul(q_lock);
	jobs.push(job);
	std::cout<< "Enqued a job. job size:" << jobs.size() << std::endl;
	q_condvar.notify_one();
}

void ThreadPool::Stop() {
	{
		std::unique_lock<std::mutex> ul(q_lock);
		//std::cout<< "Stopping the pool" << std::endl;
		should_terminate = true;
		q_condvar.notify_all();
	}
	std::cout<< "Size of threads before clear: " << threads.size() << " and job size " << jobs.size() << std::endl;
	for (auto &t : threads) {
		//std::cout<< "TID: " << std::this_thread::get_id() << " joined" << std::endl;
		t.join();
	}
	threads.clear();
	std::cout<< "Size of threads after clear: " << threads.size() << " and job size " << jobs.size() << std::endl;
}


void incr() {
	unsigned long milliseconds_since_epoch =
	    std::chrono::system_clock::now().time_since_epoch() /
	    std::chrono::milliseconds(1);
	//std::cout<< milliseconds_since_epoch << std::endl;
}

int main() {
	ThreadPool tp;
	tp.Start();
	for (int i=0; i < 30; i++) {
		tp.QueueJob(incr);
	}
	tp.Stop();
}

/*
queue<std::function<void()>>
register_callback(const std::function<void()>& job)


add to queue:
 - acquire unique lock
 - push
 - notify added (cv.notify_one())

deque:
 - acquire unique lock
 - wait until queue is not empty using cond var (cv.wait(lock))
 - pop
 - release lock
 - run callback

*/
