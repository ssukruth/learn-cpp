#include <iostream>

using std::cout;
using std::endl;

int main() {
	int o = 030; // octal 030 => decimal 24
	cout << o << endl; //24
	cout << std::oct << o << std::dec << endl; // 030

	int h = 0x30; // hex 030 => decimal 48
	cout << h <<  endl; // 48
	cout << std::hex << h << endl;
}
