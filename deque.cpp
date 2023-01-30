#include <iostream>
#include <deque>

using std::cout;
using std::endl;

void print_deque(std::deque<int> d) {
	cout << "Deque: ";
	for(auto i : d) {
		cout << i << "\t";
	}
	cout << endl;
}

int main() {

	// deque => double ended queue
	// size() => len of queue
	// empty() => is empty?
	// front() => first element
	// back() => last element
	// push_back() => append to tail
	// push_front() => insert at head
	// insert() => insert at pos
	// begin() & end() => iterators at beginning and end
	// emplace() => same as insert() but doesn't require copy constructor
	// emplace_back() & emplace_front() => same as push_back() & push_front() but doesn't require copy constructor
	// pop_back() => remove last element
	// pop_front() => remove first element
	// clear() => empty the queue

	std::deque<int> dq;
	cout << dq.empty() << endl;
	dq.push_back(2);
	dq.push_back(4);
	dq.push_front(1);
	dq.insert(dq.begin()+2, 3);
	cout << dq.front() << endl;
	cout << dq.back() << endl;
	print_deque(dq);
	dq.clear();
	print_deque(dq);
        dq.emplace_back(2);
        dq.emplace_back(4);
        dq.emplace_front(1);
        dq.emplace(dq.begin()+2, 3);
	print_deque(dq);
	dq.pop_back();
	print_deque(dq);
	dq.pop_front();
	print_deque(dq);
	cout << dq.size() << endl;
}
