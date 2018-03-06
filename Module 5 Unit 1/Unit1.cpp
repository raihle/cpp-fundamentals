#include <iostream>

using namespace std;

void print_it()
{
	cout << "it" << endl;
}

void print_argument(int arg)
{
	cout << "it is " << arg << endl;
}

int square_it(int to_square)
{
	return to_square * to_square;
}

void print_squared_argument(int arg)
{
	print_argument(square_it(arg));
}

// Parameters can have default values
// If a parameter has a default value, all later parameters must, too
int multiply_them(int left, int right = 1)
{
	return left * right;
}

// Functions have to be declared before they are referred to
// Perhaps the mythical "header" files can work around this
int main()
{
	print_it();
	print_argument(26);
	print_squared_argument(4);
	print_argument(multiply_them(5, 6));
	// Leaving out the default parameter
	print_argument(multiply_them(10));
	return 0;
}
