#include <iostream>
#include <string>

#include "Temperature.h";

using namespace std;

Temperature::Temperature(float celsius) : celsius(celsius) {}
float Temperature::getCelsius() const
{
	return celsius;
}

float Temperature::getFahrenheit() const
{
	return celsius * 1.8f + 32;
}

string Temperature::format() const
{
	return to_string(getCelsius()) + "C, " + to_string(getFahrenheit()) + "F";
}

Temperature Temperature::operator +(const Temperature &other) const
{
	return Temperature(celsius + other.celsius);
}

Temperature Temperature::operator ++()
{
	++celsius;
	return Temperature(celsius);
}

Temperature Temperature::operator ++(int)
{
	Temperature result(celsius);
	celsius++;
	return result;
}

Temperature operator +(const float &left, const Temperature &right)
{
	return Temperature(left + right.celsius);
}

// ostream is the type of cout
ostream& operator <<(ostream &stream, const Temperature &temp)
{
	// Because #format is declared const, we can call it on our const reference
	stream << temp.format();
	return stream;
}

// istream is the type of cin
istream& operator >>(istream &stream, Temperature &temp)
{
	// We are declared as a friend, so we can modify the temp directly
	stream >> temp.celsius;
	return stream;
}
