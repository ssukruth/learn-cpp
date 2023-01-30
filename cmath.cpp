#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

int main() {
	double x = log2(8); // 3
	cout << "log2(8) is " << x << endl;
	double y = log10(100); // 2
	cout << "log10(100) is " << y << endl;
	double z = pow(2, 3);
	cout << "2 power 3 is " << z << endl;
	double u = sqrt(900);
	cout << "sqrt of 900 is " << u << endl;

	cout << "Ceil of 9.14 is " << ceil(9.14) << endl;
	cout << "Floor of 9.99 is " << floor(9.99) << endl;
	cout << "Round of 9.49 is " << round(9.49) << endl;
	cout << "Abs of -9.49 is " << abs(-9.49) << endl;
}
