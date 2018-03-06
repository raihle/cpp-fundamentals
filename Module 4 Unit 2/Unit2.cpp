#include <iostream>
#include <string>

using namespace std;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "i is " << i << endl;
	}

	string input = "";
	while (input != "quit")
	{
		cout << "Enter a command (quit to stop)" << endl;
		getline(cin, input); // cin normally breaks on ANY whitespace
		cout << "You wrote: " << input << endl;
	}

	do // Will enter the loop at least once, even though input is already "quit"
	{
		cout << "Enter another command (quit to stop)" << endl;
		getline(cin, input); // cin normally breaks on ANY whitespace
		cout << "You wrote: " << input << endl;
	} while (input != "quit");

	return 0;
}