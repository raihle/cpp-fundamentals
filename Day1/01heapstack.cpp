#include <iostream>

using namespace std;

class StackTester
{
public:
	StackTester(int i): i(i)
	{
		cout << "Constructor " << i << endl;
	}

	~StackTester()
	{
		cout << "Destructor " << i << endl;
	}

private:
	int i;
};

int func(int n)
{
	return n + 2;
}

void func2()
{
	StackTester st1(1);
	StackTester st2(2);
}

int main()
{
	// Just an int
	int x = 10;

	// A pointer to an int on the heap
	int* i_pointer = new int(10);
	int* i_pointer2 = i_pointer;

	cout << *i_pointer << endl; // Prints 10

	// Unallocate the heap-int, otherwise it lives there until the program exits (which, yes, happens to be right after this, but still)
	delete i_pointer;
	// delete i_pointer2; // Crashes

	// At this point neither i_pointer nor i_pointer2 can be dereferenced legally

	cout << *i_pointer2 << endl; // Undefined behavior
	// cout << *i_pointer << endl; // Crashes

	int i = func(3); // Parameters and return values live on the heap temporarily (for call-by-value and return-by-value functions)

	func2();

	return 0;
}