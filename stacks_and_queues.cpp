#include <iostream>
#include <queue>
#include <stack>

using std::cout;
using std::endl;


int main() {
	// stack methods:
	// size()
	// empty()
	// push()
	// top()
	// pop()

	std::stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	// queue methods:
	// size()
	// empty()
	// push()
	// front()
	// back()
	// pop()
	std::queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
}
