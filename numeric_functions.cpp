#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

int main() {
	// sqrt => square root of a number
	cout << sqrt(-25) << endl; // you get nan i.e. not a number

	// remainder function. use in place of mod if you want floating remainder values
	cout << remainder(10, 3.25) << endl; // 3.25

	// ceil: ceiling of a value
	cout << ceil(10.2) << endl; // 11

	// floor: floor of a value
	cout << floor(-10.2) << endl; // -11

	// truncate
	cout << trunc(-10.2) << endl; // -10

	// round
	cout << round(10.233) << endl; // 10
	cout << round(10.5) << endl;  // 11

	// INFINITY & -INFINITY
	cout << INFINITY << endl; // inf
	cout << -INFINITY << endl; // -inf

	// absolute value
	cout << abs(-15.05) << endl; // 15.05

	return 0;
}
