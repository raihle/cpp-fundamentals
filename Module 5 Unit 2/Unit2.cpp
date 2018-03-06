#include <iostream>

using namespace std;

// Copies the value passed in, which should be avoided for large structures unless desired (though not a problem for primitives)
// Modifying the parameter does not affect the value outside, as it is copied when calling
// (I believe it's a shallow copy, meaning any pointers inside a copied struct still point at the originals)
void increment_pass_by_value(int value)
{
	value++;
	cout << "Inside PBV: " << value << endl;
}

// Gets a pointer as a parameter, which allows the function to modify the value being pointed at
void increment_pass_by_pointer(int* reference)
{
	(*reference)++;
	cout << "Inside PBP: " << *reference << endl;
}

// Prefer this, as it provides better functionality than pass-by-pointer, and doesn't force the caller to reference or the function to dereference explicitly
void increment_pass_by_reference(int& reference)
{
	reference++;
	cout << "Inside PBR: " << reference << endl;
}

// pointer and reference parameters can also be declared "const", in which case they cannot be changed in the called function

// Higher order function - "func" is a pointer to a function which takes no arguments and returns an int
void execute_and_print(int(*func)())
{
	cout << "It returned " << (*func)() << endl;
}

// Another HOF - "func" takes an int and returns an int
void execute_and_print_with_arg(int(*func)(int), int parameter)
{
	cout << "It returned " << (*func)(parameter) << " when called with " << parameter << endl;
}

int two()
{
	return 2;
}

int triple(int value)
{
	return value * 3;
}

int main()
{
	int variable = 2;
	cout << "Before PBV: " << variable << endl;
	increment_pass_by_value(variable);
	cout << "After PBV: " << variable << endl;

	cout << "Before PBP: " << variable << endl;
	increment_pass_by_pointer(&variable);
	cout << "After PBP: " << variable << endl;

	cout << "Before PBR: " << variable << endl;
	increment_pass_by_reference(variable);
	cout << "After PBR: " << variable << endl;

	execute_and_print(two);

	execute_and_print_with_arg(triple, 8);
}