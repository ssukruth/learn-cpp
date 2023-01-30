#include <iostream>
using std::cout;
using std::endl;

template<typename T>
void swaps(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 5;
	int b = 10;
	cout << a << " " << b << endl;
	swaps(a, b);
        cout << a << " " << b << endl;

	std::string foo = "foo";
	std::string bar = "bar";
        cout << foo << " " << bar << endl;
	swaps(foo, bar);
        cout << foo << " " << bar << endl;
}
