#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x = -45; // signed by default
	cout << "x: " << x << endl;

	unsigned int x2 = -45; // wraps around 0 and a PLATFORM-SPECIFIC upper bound
	cout << "x2: " << x2 << endl;

	float y = 5.4;
	cout << "y: " << y << endl;

	float y2 = 1 / 2; // Type of result depends on type of inputs
	cout << "y2: " << y2 << endl;

	int z = 4.5; // truncates to 4
	cout << "z: " << z << endl;

	char c = 'A';
	cout << "c: " << c << endl;

	char d = 66;
	cout << "d: " << d << endl;

	char e = c + 2;
	cout << "e: " << e << endl;

	bool t = true; // true is 1
	cout << "t: " << t << endl;

	bool f = false; // false is 0
	cout << "f: " << f << endl;

	string s = "Prince";
	cout << "s: " << s << endl;

	return 0;
}
