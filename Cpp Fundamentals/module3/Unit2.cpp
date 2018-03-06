#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int* p_x = &x;

	p_x = new int(15);

	cout << *p_x << endl;

	return 0;
}
