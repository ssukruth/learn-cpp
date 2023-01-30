#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::to_string;

// structs & classes both are used to create objects
// conventionally structs are used for smaller objects
// In structs the members are public by default whereas in classes they're private by default
// structs are pass by value by default.

struct Point
{
	int x;
	int y;
	std::string get_point() {
		return to_string(x) + " " + to_string(y);
	}
};

int main() {
	Point p1;
	p1.x = 10;
	p1.y = 20;
	//cout << p1.x << " " << p1.y << endl;
	cout << p1.get_point() << endl;
}
