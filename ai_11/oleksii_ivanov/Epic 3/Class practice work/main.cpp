#include "../books/book.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string menu_prompt = "Menu\n"
                     "1 - Enumerate books\n"
                     "2 - Borrow a book\n"
                     "3 - Return a borrowed book\n"
                     "0 - Exit\n";

string  enter_choice        = "Enter your choice: ",
        wrong_input         = "Unexpected input",
        continuation_prompt = "Do you wanna continue? (Y/n): ",
        selection_prompt    = "Select a book: ";

void seed_books(vector<Book>& _books);
void enumerate_books(const vector<Book>& books);

int main() {
    vector<Book> books;
    seed_books(books);

    string input_buf;

    char action_choice;
    char continuation_choice;

    bool should_continue;
    bool exit = false;

    while (!exit) {
        goto menu_start;

        wrong_input:
        cout << wrong_input << endl;
        goto menu_start;

        menu_start:
        should_continue = true;
        cout << menu_prompt << enter_choice;
        getline(cin, input_buf);

        // considering only first character of the input
        if (input_buf.size() > 1) goto wrong_input;
//        else if (input_buf.empty()) goto menu_start;
        action_choice = input_buf[0];

        do {
            switch (action_choice) {
                case '1':
                    enumerate_books(books);
                    break;
                case '2': {
                    cout << selection_prompt;
                    enumerate_books(books);
                    cout << enter_choice;

                    size_t book_index;
                    cin >> book_index;
                    cin.ignore(INT_MAX, '\n');

                    // shifting from user input (1, ...) to vector index
                    book_index--;

                    if (book_index >= books.size()) goto wrong_input;

                    Book &selected_book = books[book_index];

                    if (selected_book.getIsAvailable()) {
                        selected_book.setIsAvailable(false);
                        cout << "Successfully borrowed \""
                             << selected_book.getName()
                             << "\" book" << endl;
                    } else
                        cout << "The book \"" << selected_book.getName()
                             << "\" is not available." << endl;

                    break;
                }
                case '3': {
                    cout << selection_prompt;
                    enumerate_books(books);
                    cout << enter_choice;

                    size_t book_index;
                    cin >> book_index;
                    cin.ignore(INT_MAX, '\n');

                    // shifting from user input (1, ...) to vector index
                    book_index--;

                    if (book_index >= books.size()) goto wrong_input;

                    Book &selected_book = books[book_index];

                    if (!selected_book.getIsAvailable()) {
                        selected_book.setIsAvailable(true);
                        cout << "Successfully returned \""
                             << selected_book.getName()
                             << "\" book" << endl;
                    } else
                        cout << "The book \"" << selected_book.getName()
                             << "\" is already in library." << endl;

                    break;
                }
                case '0':
                    exit = true;
                    should_continue = false;
                    break;
                default:
                    goto wrong_input;
            }

            if (!should_continue || action_choice == '1') break;

            cout << continuation_prompt;
            getline(cin, input_buf);
            // considering only first character of the input
            if (input_buf.size() != 1) goto wrong_input;
            continuation_choice = (char) tolower(input_buf[0]);

            if (continuation_choice == 'y')
                should_continue = true;
            else if (continuation_choice == 'n')
                should_continue = false;
            else goto wrong_input;
        } while (should_continue);
    }

    cout << "Bye";
    return 0;
}

void seed_books(vector<Book>& _books) {
    _books.emplace_back("1984", true);
    _books.emplace_back("Fahrenheit 451", true);
    _books.emplace_back("Harry Potter", true);
    _books.emplace_back("The Hobbit", true);
    _books.emplace_back("The Witcher", true);
    _books.emplace_back("The Hitchhiker's Guide to the Galaxy", true);
    _books.emplace_back("The Restaurant at the End of the Universe", true);
    _books.emplace_back("Life, the Universe and Everything", true);
    _books.emplace_back("So Long, and Thanks for All the Fish", true);
    _books.emplace_back("Mostly Harmless", true);
    _books.emplace_back("The Metamorphosis", true);
}

void enumerate_books(const vector<Book>& books) {
    for (int i = 0; i < books.size(); ++i)
        cout << i + 1 << " - " << books[i].toString() << endl;
}