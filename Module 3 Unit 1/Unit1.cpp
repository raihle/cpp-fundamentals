#include <iostream>

using namespace std;

int main()
{
	int x = 10;

	int* p_x = &x;
	*p_x = 14;
	cout << x << endl;

	return 0;
}
