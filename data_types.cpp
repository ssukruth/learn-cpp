#include <iostream>
#include <climits>
#include <float.h>

using std::cout;
using std::endl;
using std::boolalpha;

#define X 10 // defines a constant X with value 10

int main() {

	// integral datatypes
	short a;
	int b;
	long c;
	long long d;
	unsigned short aa;
	unsigned int bb;
	unsigned long cc;
	unsigned long long dd;
	// short <= int <= long <= long long
	cout << "Size of short in bytes: " << sizeof(short) << endl;
	cout << "Size of int in bytes: " << sizeof(int) << endl;
	cout << "Size of long in bytes: " << sizeof(long) << endl;
	cout << "Size of long long in bytes: " << sizeof(long long) << endl;

	cout << "Size of unsigned short in bytes: " << sizeof(unsigned short) << endl;
	cout << "Size of unsigned int in bytes: " << sizeof(unsigned int) << endl;
	cout << "Size of unsigned long in bytes: " << sizeof(unsigned long) << endl;
	cout << "Size of unsigned long long in bytes: " << sizeof(unsigned long long) << endl;

	cout << "Short ranges from " << SHRT_MIN << " to " << SHRT_MAX << endl;
	cout << "Unsigned Short ranges from 0 to " << USHRT_MAX << endl;

	cout << "Int ranges from " << INT_MIN << " to " << INT_MAX << endl;
	cout << "Unsigned Int ranges from 0 to " << UINT_MAX << endl;

	cout << "Long ranges from " << LONG_MIN << " to " << LONG_MAX << endl;
	cout << "Unsigned Long ranges from 0 to " << ULONG_MAX << endl;

	cout << "Long Long ranges from " << LLONG_MIN << " to " << LLONG_MAX << endl;
	cout << "Unsigned Long Long ranges from 0 to " << ULLONG_MAX << endl;

	// Char datatype: used to store characters or integers
	// Use single quote to store character
	char x = 'A';
	cout << "x = '"<< x << "' and it's int val is " << (int) x << endl;
	char y = 7;
	cout << "y = '"<< y << "' and it's int val is " << (int) y << endl;
	cout << "Char ranges from " << CHAR_MIN << " to " << CHAR_MAX << endl;
	unsigned char z = 169;
	cout << "z = '"<< z << "' and it's int val is " << (int) z << endl;
	cout << "Unsigned Char ranges from 0 to " << UCHAR_MAX << endl;

	// bool :  boolean datatype
	// true & false are acceptable values
	// we can also use integers
	// 0 is false and anything else is true
	bool bf = false;
	bool bf1 = 0;
	bool bt = true;
	bool bt1 = -3; // will be set to 1 when you print, indicating it's true
	cout << "bf = " << bf << endl;
	cout << "bf1 = " << bf1 << endl;
	cout << "bt = " << bt << endl;
	cout << "bt1 = " << bt1 << " i.e. " << boolalpha << bt1 << endl;

	// 3 types of floating point numbers
	// float, double, & long double
	// the number of trust worthy digits after the decimal increasingly varies from float to double to long double
	float f1 = 10.0 / 3 ;
	double d1 = 10.0 / 3 ;
	long double d2 = 10.0 / 3;
	f1 *= 10000000;
	d1 *= 10000000;
	d2 *= 10000000;

	cout << "f1: " << std::fixed << f1 << endl;
	cout << "d1: " << d1 << endl;
	cout << "d2: " << d2 << endl;
	cout << "float guarantees accuracy for " << FLT_DIG << " digits after decimal point." << endl;
	cout << "double guarantees accuracy for " << DBL_DIG << " digits after decimal point." << endl;
	cout << "long double guarantees accuracy for " << LDBL_DIG << " digits after decimal point." << endl;

	// constants
	// creates a read only variable. i.e you cannot change it after initialization.
	const int k = 5;
	// x++; // uncomment and you'll see that you get a compilation error for changing a constant

	// enum constants
	enum { foo = 1 };
	cout << k << endl;
	cout << X << endl;
	cout << foo << endl;


	return 0;
}

