#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
	// Constructor is invoked when creating an instance through Typename variable_name(parameters)
	Book(string title, string author, int publication_year)
		// Fancy initialization of member variables
		: title(title), author(author), publication_year(publication_year)
	{
		cout << "Default constructor invoked" << endl;
	}

	Book(const Book& other)
		// Private members can be accessed from the same class, even other instances
		: title(other.title), author(other.author), publication_year(other.publication_year)
	{
		cout << "Copy constructor invoked" << endl;
	}

	// Destructor, executes when the instance is about to disappear
	~Book()
	{
		cout << "Destructor for " << this->title << " by " << this->author << endl;
	}

	string get_title()
	{
		return this->title;
	}

	void set_title(string new_title)
	{
		this->title = new_title;
	}

	string get_author()
	{
		return this->author;
	}

	void set_author(string new_author)
	{
		this->author = new_author;
	}

	int get_publication_year()
	{
		return this->publication_year;
	}

	void set_publication_year(int new_publication_year)
	{
		this->publication_year = publication_year;
	}

private:
	string title;
	string author;
	int publication_year;
};

void print_book(Book& book)
{
	cout << "The book is " << book.get_title() << ", it was written by " << book.get_author() << ", and it was published in " << book.get_publication_year() << endl;
}

int main()
{
	// Without using "new", the Book is located on the *stack* instead of the *heap*
	// This means it is unallocated when going out of scope!
	// This doesn't matter for "main" as that is when the program ends, but if we
	// want to return a pointer to an object, it has to be allocated to the heap using new,
	// and then be deleted when we are done with it.
	Book book("Title", "Author", 2018);
	print_book(book);

	{
		// Uses the "copy" constructor - this is a new Book, not just a new reference!
		// Copy constructors exist by default
		Book book2 = book;
		book2.set_author("Another author");
		print_book(book2);
		// book2 will be destructed and deallocated here
	}
	print_book(book);
	return 0;
}