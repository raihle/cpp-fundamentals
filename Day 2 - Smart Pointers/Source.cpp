#include <iostream>
#include <memory>

using namespace std;

class MyClass
{
public:
	MyClass(int value): value(value) { cout << "Con " << value << endl; }
	~MyClass() { cout << "Dec " << value << endl; }
private:
	int value;
};

int main()
{
	MyClass* mcPtr = new MyClass(1);
	// Without delete, mcPtr's MyClass object is leaking
	// delete mcPtr;

	MyClass* mcPtr2 = new MyClass(2);
	delete mcPtr2;

	// unique_ptr automatically deletes when it goes out of scope
	unique_ptr<MyClass> mcPtr3(new MyClass(3));

	{
		// This unique_ptr will delete before the end of main because it is within a smaller scope
		unique_ptr<MyClass> mcPtr4(new MyClass(4));
	}

	// shared_ptr deletes when all pointers to the same object are out of scope
	shared_ptr<MyClass> mcPtr5(new MyClass(5));
	{
		// No deconstruction will occur when mcPtr6 leaves scope
		shared_ptr<MyClass> mcPtr6 = mcPtr5;
	}

	// Assigning a unique_ptr to another is not legal
	//unique_ptr<MyClass> mcPtr7(new MyClass(7));
	//unique_ptr<MyClass> mcPtr8 = mcPtr7;

	cout << "main ending" << endl;
	return 0;
}