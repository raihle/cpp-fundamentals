#include <iostream>
#include <vector>

using namespace std;


void print_numbers(vector<int>& numbers)
{
	for (int number : numbers)
	{
		cout << "The current number is " << number << endl;
	}
}

int main()
{
	// Vectors can grow and shrink dynamically
	// They probably use arrays internally?
	vector<int> numbers = { 1, 2, 3, 4 };
	print_numbers(numbers);
	
	// Push back adds a value to the end
	numbers.push_back(5);
	cout << "Added 5 to the end" << endl;
	print_numbers(numbers);

	// Pop back removes the last value
	numbers.pop_back();
	cout << "Removed the last number" << endl;
	print_numbers(numbers);

	// Erase removes a value at a given position
	numbers.erase(numbers.begin() + 1);
	cout << "Removed the second number" << endl;
	print_numbers(numbers);

	// Insert inserts a value at a given position, shifting later positions
	numbers.insert(numbers.begin() + 2, 16);
	cout << "Inserted 16 at third index" << endl;
	print_numbers(numbers);

	// Direct indexing works, too
	numbers[1] = 34;
	cout << "Overwrote the second index with 34" << endl;
	print_numbers(numbers);

	vector<int> numbers2 = { 1,2,3,4,1,2,3 };
	cout << "Created a new vector" << endl;
	print_numbers(numbers2);

	vector<int>::iterator iter = numbers2.begin();
	while (iter != numbers2.end())
	{
		if (*iter == 2)
		{
			iter = numbers2.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	cout << "Removed all 2s" << endl;
	print_numbers(numbers2);
	
	return 0;
}