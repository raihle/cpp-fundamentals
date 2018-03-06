#include <iostream>

using namespace std;

int main()
{
	int* p = new int(15);
	
	cout << *p << endl;

	delete p;

	return 0;
}
