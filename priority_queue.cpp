#include <iostream>
#include <queue>
using std::cout;
using std::endl;

int main() {
	// priority queue in C++ is a max heap
	// size()
	// empty()
	// push()
	// top()
	// pop()
	std::priority_queue<int> pq;
	pq.push(1);
	pq.push(21);
	pq.push(99);
	pq.push(31);
	cout << pq.size() << endl;
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;

	// priority queue of pairs
	std::priority_queue<std::pair<int, int>> pq_pairs;
	pq_pairs.push(std::make_pair(3, 0));
	pq_pairs.push(std::make_pair(2, 1));
	pq_pairs.push(std::make_pair(2, 12));
	cout << pq_pairs.size() << endl;
	std::pair<int,int> p =  pq_pairs.top();
	cout << p.first << " " << p.second << endl;
	pq_pairs.pop();
	p =  pq_pairs.top();
	cout << p.first << " " << p.second << endl;
}
