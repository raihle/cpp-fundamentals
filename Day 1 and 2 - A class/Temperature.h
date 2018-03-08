#pragma once

#include <iostream>
#include <string>

using namespace std;

class Temperature
{
public:
	// Constructor
	Temperature(float celsius);
	// Getters
	float getFahrenheit() const;
	float getCelsius() const;
	// Convert to string
	string format() const;
	// Operator overloading
	Temperature operator +(const Temperature &other) const;
	// prefix operator
	Temperature operator ++();
	// postfix operator - wut?
	Temperature operator ++(int);

	// Friend function for backwards operator overloading
	// We have no instance here, so there are two arguments to the operator
	friend Temperature operator +(const float &left, const Temperature &right);
	friend istream& operator >>(istream &stream, Temperature &temp);
private:
	float celsius;
};

ostream& operator <<(ostream &stream, const Temperature &temp);