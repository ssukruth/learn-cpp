#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	string greeting = "hello";

	// concat
	string there = "there";
	string complete = greeting + " " + there;
	cout << complete << endl;

	// read string line from user input
	// UNCOMMENT the snippet below to try out

	//cout << "Enter a string:";
	//getline(cin, greeting);
	//cout << "You entered [" << greeting << "]" << endl;

	// String methods
	// length & size give you size of string
	int len = complete.length();
	int sz = complete.size();
	cout << complete << " is of length " << len << " and size " << sz << endl;

	// append
	complete += "!";
	complete.append("!");
	cout << complete << endl;

	// insert
	complete.insert(3, "...");
	cout << complete << endl;

	// erase
	complete.erase(3, 3);
	cout << complete << endl;

	// pop_back : remove one char at the end
	complete.pop_back();
	cout << complete << endl;

	// replace
	complete.replace(0, 5, "Hi");
	cout << complete << endl;

	// find
	int idx = complete.find("there");
	cout << idx << endl;

	// substr
	cout << complete.substr(2, 3) << endl;

	// find_first_of
	idx = complete.find_first_of("aeiou"); // find index of first vowel
	cout << idx << endl;

	// compare
	if (complete == "Hi there!") {
		cout << "strings are equal" << endl;
	}
	if (complete.compare("Hi there!") == 0) {
		cout << "strings are equal" << endl;
	}

	return 0;
}
