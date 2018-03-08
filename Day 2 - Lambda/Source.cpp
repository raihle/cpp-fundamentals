#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// This is a valid lambda :^) (we're even calling it on the same line)
	// []: "capture" identifies a lambda and creates a closure over the identified variables
	// (): Parameter list, as usual
	// {}: Body, as usual
	// (): Invocation
	[]() {}();

	auto func = [](int x)
	{
		cout << x << endl;
	};

	func(1);

	int n = 10;
	auto capturingFunc1 = [&n](int x)
	{
		cout << x << " & " << n << endl;
	};

	auto capturingFunc2 = [n](int x)
	{
		cout << x << " & " << n << endl;
	};

	capturingFunc1(2);
	capturingFunc2(3);

	n = 15;
	// n was captured by reference, it will have the updated n
	capturingFunc1(4);
	// n was captured by value, it will have the n at the point of lambda definition
	capturingFunc2(5);


	int sum = 0;
	auto addToSum = [&sum](int x)
	{
		sum += x;
	};

	vector<int> v = { 1, 2, 3, 4, 5 };
	for_each(begin(v), end(v), addToSum);
	cout << "The sum is " << sum << endl;

	// Lambdas can also be passed as paramters inline

	// Closure example
	auto f = [](int a)
	{
		return [a](int b)
		{
			return a * b;
		};
	};
	auto times2 = f(2);
	cout << times2(3) << endl;
	cout << times2(4) << endl;

	return 0;
}