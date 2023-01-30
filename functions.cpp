#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

double power(double base, int exponent) {
	if (exponent < 1) {
		cout << "exponent has to be greater than 1";
		return -1;
	}
	double result = 1;
	for (int i = 0; i < exponent; i++) {
		result *= base;
	}
	return result;
}

int main() {
	double base;
	int exponent;
	cout << "Base: ";
	cin >> base;
	cout << "Exponent: ";
	cin >> exponent;
	cout << "cmath pow() returns: " << pow(base, exponent) << endl;
	cout << "custom power() returns: " << power(base, exponent) << endl;
}
