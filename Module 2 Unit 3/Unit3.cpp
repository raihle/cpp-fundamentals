#include <iostream>

using namespace std;

namespace module2_unit3
{
	int abs(int value)
	{
		return value + 1;
	}
}

int main()
{
	cout << abs(-5) << endl;
	return 0;
}
