#include <iostream>
#include <string>

using namespace std;

// Would normally be in a header file
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
	Temperature operator +(const Temperature &other);

	// Friend function for backwards operator overloading
	// We have no instance here, so there are two arguments to the operator
	friend Temperature operator +(const float &left, const Temperature &right);
	friend istream& operator >>(istream &stream, Temperature &temp);
private:
	float celsius;
};

Temperature::Temperature(float celsius): celsius(celsius) {}
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

Temperature Temperature::operator +(const Temperature &other)
{
	return Temperature(celsius + other.celsius);
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

int main()
{
	Temperature room_temp(21.0f);
	Temperature body_temp(37.5f);
	Temperature freezing_temp(0.0f);
	Temperature boiling_temp(100.0f);
	Temperature really_freezing_temp(-40.0f);

	// Overloaded operator whooo
	Temperature boiling_body = body_temp + boiling_temp;

	// Performed by adding two-by-two in left-to-right order
	Temperature really_really_freezing_room_temp = really_freezing_temp + freezing_temp + room_temp;

	// Automatically invokes Temperature constructor because the argument matches the constructor argument of the expected type... ~~~magic~~
	Temperature magic_temp = boiling_temp + 15.0f;

	// To do it "backwards", we need a "friend" function
	Temperature friend_temp = 22.0f + freezing_temp;

	cout << "Room temp " << room_temp.format() << endl;
	cout << "Body temp " << body_temp.format() << endl;
	cout << "Freezing temp " << freezing_temp.format() << endl;
	cout << "Boiling temp " << boiling_temp.format() << endl;
	cout << "Really freezing temp " << really_freezing_temp.format() << endl;
	cout << "Boiling body temp " << boiling_body.format() << endl;
	cout << "Really really freezing room temp " << really_really_freezing_room_temp.format() << endl;
	cout << "Magic temp " << magic_temp.format() << endl;
	cout << "Friend temp " << friend_temp.format() << endl;

	// We can also overload << to implicitly call #format
	cout << "Magic temp auto stream " << magic_temp << endl;

	Temperature reading_temp(0.0f);
	cout << "Enter temp: ";
	cin >> reading_temp;
	cout << "You entered " << reading_temp << endl;
}