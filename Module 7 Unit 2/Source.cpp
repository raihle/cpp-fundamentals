#include <iostream>
#include <string>

using namespace std;

// "Regular" function with concrete types
int max(int left, int right)
{
	return left > right ? left : right;
}

// Overloaded regular function
// C++ will resolve it correctly, but code is duplicated
double max(double left, double right)
{
	return left > right ? left : right;
}

// *Another* overloaded regular function
string max(string left, string right)
{
	return left > right ? left : right;
}

// This "generic" template function will work for "any" type (with a meaningful > operator)
template <typename T>
T genericMax(T left, T right)
{
	return left > right ? left : right;
}

int main()
{
	int i1 = 4;
	int i2 = 5;
	// "Regular" function
	cout << "The biggest is " << max(i1, i2) << endl;
	// Generic / Template function
	cout << "The generically biggest is " << genericMax(i1, i2) << endl;

	double d1 = 5.64;
	double d2 = 9.12345;
	cout << "The biggest is " << max(d1, d2) << endl;
	cout << "The generically biggest is " << genericMax(d1, d2) << endl;
	// Call with specified generic type
	cout << "The generically biggest as int is " << genericMax<int>(d1, d2) << endl;

	string s1 = "Hello,";
	string s2 = "World!";
	cout << "The biggest is " << max(s1, s2) << endl;
	cout << "The generically biggest is " << genericMax(s1, s2) << endl;

	return 0;
}