#include <iostream>

using namespace std;

class VirtualShape
{
public:
	VirtualShape(int width, int height) : width(width), height(height) {}
	virtual int getArea() = 0;
protected:
	int width;
	int height;
};

class Shape : public VirtualShape
{
public:
	Shape(int width, int height) : VirtualShape(width, height) {}
	int getArea() { return 0; }
};

class Rectangle : public Shape
{
public:
	// Calling Shape constructor
	Rectangle(int width, int height) : Shape(width, height) {}
	int getArea()
	{
		return width * height;
	}
};

class Triangle : public Shape
{
public:
	Triangle(int width, int height) : Shape(width, height) {}

	int getArea() {
		return width * height / 2;
	}
};

void printArea(VirtualShape* shape)
{
	cout << shape->getArea() << endl;
}

int main()
{
	Rectangle r1(10, 14);
	cout << r1.getArea() << endl;

	Triangle t1(10, 14);
	cout << t1.getArea() << endl;

	Shape r2 = Rectangle(15, 16);
	// getArea is not virtual, so the static type's (Shape) version is used
	cout << r2.getArea() << endl;

	// VirtualShape has a pure virtual function, it cannot be used as a variable type
	// VirtualShape r3 = Rectangle(11, 14);
	// cout << r3.getArea() << endl;

	// However, we CAN, if it is a pointer
	VirtualShape *r4 = &r1;
	// Printed according to r1s static type
	cout << r4->getArea() << endl;

	VirtualShape *r5 = &r2;
	// Printed according to r2s static type
	cout << r5->getArea() << endl;

	return 0;
}