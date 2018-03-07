#include <iostream>

using namespace std;


// x is a reference to an int, it can only bind to lvalues
void func1(int &x)
{
	x++;
}

// x is a const reference to an int, it can bind to lvalues and rvalues
void func2(const int &x)
{
	// Can't modify a const reference
	// x++;
}


// x is a regular (lvalue) reference to an int, it can only bind to lvalues
void func3(int &x)
{
	cout << "x is an lvalue reference" << endl;
}

// x is an rvalue reference (or "refref") to an int, it can only bind to rvalues
// Why can you do this?
void func3(int &&x)
{
	cout << "x is an rvalue reference" << endl;
}

int main()
{
	// x is an lvalue, 5 is an rvalue
	// It *used* to be simply that lvalues could be to the left of assignments, while rvalues could only be on the right
	// A new, imperfect, explanation is that rvalues are things that we cannot get the address of
	// The distinction is more important starting with C++ 11 and the introduction of rvalue references
	int x = 5;
	// &x is an lvalue (normal) reference
	cout << &x << endl;
	// &5 is not legal
	// cout << &5 << endl;

	int n = 10;
	func1(n);
	cout << n << endl; // n has been modified by func1

	func2(n); // We can pass lvalues as const references

	// func1(3); // We cannot pass rvalues as non-const references - that would redefine 3 to be 4 D:
	func2(3); // We can pass rvalues as const references

	func3(n); // Invokes the lvalue version
	func3(3); // Invokes the rvalue version
	func3(move(n)); // Move casts lvalues into rvalues. This is only OK if n will never be used again.
	// After this point, n is potentially invalid.
	// Implement "move semantics" in your classes to take advantage of potential performance gains in
	// datastructures (like vector) that use move.

	return 0;
}