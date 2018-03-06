#include <iostream>
#include <string>

using namespace std;

struct book
{
	string title;
	string author;
	int publication_year;
};

void print_book(book& book)
{
	cout << "The book is called " << book.title << ", was written by " << book.author << ", and was published in " << book.publication_year << endl;
}

union double_or_int
{
	double double_value;
	int int_value;
};

void print_double_or_int(double_or_int& doi)
{
	cout << "Double value is " << doi.double_value << endl;
	cout << "Int value is " << doi.int_value << endl;
}

enum days
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

int main()
{
	book a;
	a.title = "A";
	a.author = "A A:son";
	a.publication_year = 1999;
	print_book(a);

	double_or_int doi;
	doi.int_value = 123;
	cout << "Set int to 123" << endl;
	print_double_or_int(doi);
	doi.double_value = 123.234;
	cout << "Set double to 123.234" << endl;
	print_double_or_int(doi);

	days day = Thursday;
	cout << "The day is " << day << endl;

	return 0;
}