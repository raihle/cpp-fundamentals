#include <iostream>

using namespace std;

int main()
{
	int x = 5;
	int y = 5;

	if (x == 10 && y == 2)
	{
		cout << "Yep, x is 10 and y is 2!" << endl;
	}
	else if (y >= 5)
	{
		cout << "Y is at least 5, but x is " << x << endl;
	}
	else
	{
		cout << "Nope, x is " << x << " and y is " << y << endl;
	}

	switch (x)
	{
	case 1:
		cout << "Switching over x, it's 1" << endl;
		break;
	case 5:
		cout << "Switching over x, it's 5. This case will fall through." << endl;
		/* falls through */
	case 15:
		cout << "Switching over x, it's 15 (or 5)" << endl;
		break;
	default:
		cout << "Switching over x, it's something else" << endl;
		break;
	}
	return 0;
}