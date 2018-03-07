#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1 = "Hello guys";
	cout << s1.substr(2, 5) << endl;

	string *s2 = new string("Hello guys");
	// We need to dereference s2 to use its string methods
	// dot has precedence over asterisk
	cout << (*s2).substr(2, 5) << endl;
	// Same function, preferred syntax
	cout << s2->substr(2, 5) << endl;
	
	delete s2;
	return 0;
}