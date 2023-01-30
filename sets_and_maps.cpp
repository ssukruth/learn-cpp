#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using std::cout;
using std::endl;

void find_in_set(std::set<int> s, int v) {
	std::set<int>::iterator it = s.find(v);
	if (it == s.end()) {
		cout << v << " is not in set" << endl;
	} else {
		cout << v << " is in set" << endl;
	}
}

void find_in_unordered_set(std::unordered_set<int> s, int v) {
	std::unordered_set<int>::iterator it = s.find(v);
	if (it == s.end()) {
		cout << v << " is not in unordered set" << endl;
	} else {
		cout << v << " is in unordered set" << endl;
	}
}

int main() {
	// sets are often implented as BSTs
	// size()
	// empty()
	// begin()
	// end()
	// clear()
	// erase()
	// insert()
	// find()
	std::set<int> s;
	s.insert(61);
	s.insert(29);
	s.insert(92);
	find_in_set(s, 12);
	find_in_set(s, 29);
	s.erase(29);
	find_in_set(s, 29);

	// unordered sets are impleted using Hash maps
	// methods are same as sets
	std::unordered_set<int> os;
	os.insert(61);
	os.insert(29);
	os.insert(92);
	find_in_unordered_set(os, 12);
	find_in_unordered_set(os, 29);
	os.erase(29);
	find_in_unordered_set(os, 29);

	// maps implemented using BSTs
        // size()
        // empty()
        // begin()
        // end()
        // clear()
        // erase()
        // emplace()
	// find()
	// count()
	std::map<std::string, std::string> m;
	m.emplace("hi", "hello");
	m.emplace("bye", "ciao");
	cout << "Map size " << m.size() << endl;
	cout << m.count("hi") << endl;
	cout << m.count("hey") << endl;
	for (auto p: m) {
		cout << p.first << ":" << p.second << endl;
	}
	m["bye"] = "goodbye";
	cout << m.at("bye") << endl;

	// unordered maps implemented using hash maps
        // size()
        // empty()
        // begin()
        // end()
        // clear()
        // erase()
        // emplace()
	// find()
	// count()
	std::unordered_map<std::string, std::string> om;
	om.emplace("hi", "hello");
	om.emplace("bye", "ciao");
	cout << "Map size " << om.size() << endl;
	cout << om.count("hi") << endl;
	cout << om.count("hey") << endl;
	for (auto p: om) {
		cout << p.first << ":" << p.second << endl;
	}
	om["bye"] = "goodbye";
	cout << om.at("bye") << endl;
}
