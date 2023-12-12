#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Library {
private:
    vector<string> bookTitles;
    vector<bool> availability;

public:
    // Add a book to the library
    void addBook(const string& title) {
        bookTitles.push_back(title);
        availability.push_back(true);  // Initially, all books are available
    }

    // List all books in the library
    void listBooks() const {
        cout << "List of books in the library:\n";
        for (size_t i = 0; i < bookTitles.size(); ++i) {
            cout << i + 1 << ". " << bookTitles[i] << " - " << (availability[i] ? "Available" : "Borrowed") << "\n";
        }
        cout << "\n";
    }

    // Borrow a book by index
    void borrowBook(size_t index) {
        if (index > 0 && index <= bookTitles.size()) {
            if (availability[index - 1]) {
                cout << "You have borrowed the book \"" << bookTitles[index - 1] << "\".\n\n";
                availability[index - 1] = false;  // Mark the book as borrowed
            } else {
                cout << "This book is already borrowed.\n\n";
            }
        } else {
            cout << "Invalid book index.\n\n";
        }
    }

    // Return a book by index
    void returnBook(size_t index) {
        if (index > 0 && index <= bookTitles.size()) {
            if (!availability[index - 1]) {
                cout << "You have returned the book \"" << bookTitles[index - 1] << "\".\n\n";
                availability[index - 1] = true;  // Mark the book as available
            } else {
                cout << "This book is already available.\n\n";
            }
        } else {
            cout << "Invalid book index.\n\n";
        }
    }
};

int main() {
    Library library;

    // Add some books to the library
    library.addBook("Book 1");
    library.addBook("Book 2");
    library.addBook("Book 3");

    // Check the list of books
    library.listBooks();

    // Borrow a book
    library.borrowBook(1);

    // Return a book
    library.returnBook(1);

    // Check the list of books again
    library.listBooks();

    return 0;
}
