#include <iostream>
using std::cout;
using std::endl;

int main() {
	// logical operators
	// && : And
	// || : Or
	// ! : Not

	// comparison operators
	// == : equal to
	// != : not equal to
	// < : less than
	// > : greater than
	// <= : less than or equal to
	// >= : greater than or equal to

	// branching
	// if & switch
	int a = 10;
	if (a % 5 == 0 && a % 3 == 0) {
		cout << a << " is a multiple of 15" << endl;
	} else if (a % 5 == 0) {
		cout << a << " is a multiple of 5" << endl;
	} else if (a % 3 == 0) {
		cout << a << " is a multiple of 3" << endl;
	} else {
		cout << a << " is not a multiple of 3, 5, 15" << endl;
	}

	// switches work only on integral data types
	enum season{ summer, spring, fall, winter};
	int now = 2;
	switch(now) {
		case summer:
			cout << "summer" << endl;
			break;
		case spring:
			cout << "spring" << endl;
			break;
		case fall:
			cout << "fall" << endl;
			break;
		case winter:
			cout << "winter" << endl;
			break;
		default:
			cout << "unknown" << endl;
			break;
	}

	// looping
	// for , while & do while

	int f = 10;
	int fact = 1;
	// calculate factorial of f using while loop
	while (f > 0 ) {
		fact *= f;
		f--;
	}
	cout << "factorial of 10 is " << fact << endl;

	// calculate factorial of f using for loop
	f = 10;
	fact = 1;
	for(int x = 1; x <= f; x++) {
		fact *= x;
	}
	cout << "factorial of 10 is " << fact << endl;

	// do while always executes the branch code at least Once
	int i = 1;
	fact = 1;
	do {
		fact *= i;
		i++;
	} while (i <= f);
	cout << "factorial of 10 is " << fact << endl;

	// using continue and break
	// continue => skip to next iteration
	// break => exit the loop

	// sum of even numbers from 1 to 10
	int res = 0;
	for (int i = 1; ; i++) {
		if (i  % 2 != 0) {
			continue;
		}
		res += i;
		if (i == 10) {
			break;
		}
	}
	cout << "sum of even numbers from 1 to 10 is " << res << endl;

}
