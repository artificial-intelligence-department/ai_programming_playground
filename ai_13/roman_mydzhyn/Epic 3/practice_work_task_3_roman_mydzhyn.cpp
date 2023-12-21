#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> books = {"The Red and the Black", "Gulliver's Travels", "The Lord of the Rings", "The Adventures of Tom Sawyer"};
	vector<bool> available = {true, true, true, true};
	int choice;
	string bookName;

menu:
	cout << "Library Management" << endl;
	cout << "1. List all books" << endl;
	cout << "2. Borrow a book" << endl;
	cout << "3. Return a book" << endl;
	cout << "4. Exit " << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	switch (choice)
	{
	// Display our menu
	case 1:
		for (int i = 0; i < books.size(); i++)
		{
			cout << i + 1 << ". " << books[i] << (available[i] ? " (Available)" : " (Borrowed)") << endl;
		}
		break;
		// Take our book
	case 2:
		cin.ignore();
		cout << "Enter book name to borrow: ";
		getline(cin, bookName);

		for (const auto &book : books)
		{
			if (book == bookName)
			{
				int index = &book - &books[0];
				if (available[index])
				{
					available[index] = false;
					cout << "Book borrowed successfully!" << endl;
				}
				else
				{
					cout << "Book is already borrowed." << endl;
				}
				break;
			}
		}
		break;
		// Return book
	case 3:
		cin.ignore();
		cout << "Enter book name to return: ";
		getline(cin, bookName);

		for (const auto &book : books)
		{
			if (book == bookName)
			{
				int index = &book - &books[0];
				if (!available[index])
				{
					available[index] = true;
					cout << "Book returned successfully!" << endl;
				}
				else
				{
					cout << "Book wasn't borrowed." << endl;
				}
				break;
			}
		}
		break;
		// Exit the program
	case 4:
		cout << "Goodbye!";
		return 0;
	default:
		cout << "Invalid choice." << endl;
		goto menu;
	}

	char continueChoice;
	do
	{
		cout << "Do you want to perform another operation? (Y/N): ";
		cin >> continueChoice;
	} while (continueChoice != 'Y' && continueChoice != 'N' && continueChoice != 'y' && continueChoice != 'n'); // Uppercases and lowercases

	if (continueChoice == 'Y' || continueChoice == 'y')
	{
		goto menu;
	}
	else
	{
		cout << "Goodbye!";
	}

	return 0;
}
