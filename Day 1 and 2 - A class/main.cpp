#include <iostream>
#include <string>

#include "Temperature.h";

using namespace std;

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

	// Automatically invokes Temperature constructor because the argument matches the constructor argument of the expected type... ~~magic~~
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

	Temperature incrementing_temp(0.0f);
	cout << incrementing_temp << endl;
	cout << ++incrementing_temp << endl;
	cout << incrementing_temp << endl;

	Temperature post_incrementing_temp(0.0f);
	cout << post_incrementing_temp << endl;
	cout << post_incrementing_temp++ << endl;
	cout << post_incrementing_temp << endl;
}
