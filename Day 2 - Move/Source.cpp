#include <iostream>
#include <string>

using namespace std;

class Movable 
{
public:
	// Normal constructor
	Movable(int value) : value(value)
	{
		cout << "One-arg con " << value << endl;
	}

	// Copy constructor (lvalue parameter)
	Movable(const Movable &copyFrom) : value(copyFrom.value)
	{
		cout << "Copy constructor " << copyFrom.value << endl;
	}

	// Move constructor (rvalue paramter)
	Movable(Movable &&moveFrom) : value(moveFrom.value) {
		cout << "Move constructor " << moveFrom.value << endl;
		// Pointless in this case since it's an int rather than a pointer to an object,
		// but it is good practice to clear the moved object
		value = 0;
		swap(value, moveFrom.value);
	}

	// Copy assignment - not a constructor
	Movable& operator =(const Movable &other)
	{
		cout << "Copy assignment " << other.value << endl;
		this->value = other.value;
		return *this;
	}

	// Move assignment
	Movable& operator =(Movable &&other)
	{
		cout << "Move assignment " << other.value << endl;
		value = 0;
		swap(value, other.value);
		this->value = other.value;
		other.value = 0;
		return *this;
	}

private:
	int value;
};

Movable createMovable()
{
	return Movable(123);
}

int main()
{
	string s1 = "some text";
	string s2 = move(s1);

	cout << "!" << s1 << "!" << endl;
	cout << "!" << s2 << "!" << endl;

	// One-arg constructor
	Movable m1(1);
	// Copy constructor
	Movable m2(m1);
	// Move constructor
	Movable m3(move(m1));
	// Copy CONSTRUCTOR, because m4 did not exist previously
	Movable m4 = m2;
	// Copy ASSIGNMENT (albeit to the same value)
	m4 = m2;
	// Move CONSTRUCTOR
	Movable m5(move(m2));
	// Move ASSIGNMENT
	m5 = move(m4);

	// Causes only one construction because of compiler magic
	Movable m6 = createMovable();
	// This is even more ~~magical~~ (still just one call)
	Movable m7(Movable(234));

	return 0;
}