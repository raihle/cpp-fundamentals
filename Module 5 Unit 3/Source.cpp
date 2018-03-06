#include <iostream>

using namespace std;

int main()
{
	// Arrays have a fixed size (4 in this case) and are 0-indexed
	int numbers[4];
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

	// Standard for loop. We are able to exceed the length of the array and get "random" values.
	for (int i = 0; i < 5; i++)
	{
		cout << "At location " << i << " there is " << numbers[i] << endl;
	}

	// Immediately initialized array - specifying size in brackets is optional (not shown)
	int numbers2[] = { 1, 2, 3, 4, 5, 6, 7 };

	// Iterate over each value. We do not risk going outside the array (though entries can still be empty), but we cannot get the index.
	for (int number : numbers2)
	{
		cout << "The current number is " << number << endl;
	}

	return 0;
}