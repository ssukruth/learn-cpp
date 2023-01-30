#include <iostream>
using std::cout;
using std::endl;

class User {
	std::string first_name;
	std::string last_name;
	public:
		// Constructor
		User(std::string f, std::string l) {
			cout << "Calling constructor" << endl;
			this->first_name = f;
			this->last_name = l;
		}
		std::string greeting() {
			return "Hello " + this->first_name + " " + this->last_name + "!";
		}
		// Destructor
		~User() {
			cout << "Bye " << this->first_name << " " << this->last_name << "!" << endl;
		}

};

int main() {
	User u("Foo", "Bar");
	cout << u.greeting() << endl;
}
