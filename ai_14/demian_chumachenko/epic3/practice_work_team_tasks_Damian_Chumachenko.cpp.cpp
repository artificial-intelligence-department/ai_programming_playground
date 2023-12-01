#include <iostream>
#include <string>

using namespace std;

int main() {
    string List_of_books[4] = {"Fahrenheit 451", "Harry Potter", "1984", "Don Quixote"};
    bool Books_available[4] = {true, true, true, true};
    char in_out, choice;
    string Book_name;

    do {
    menu:
        cout << "--*--*-- Menu --*--*--" << endl;
        cout << "Choose what you want to do 1-4:" << endl;
        cout << "1) Show the list of books" << endl;
        cout << "2) Take a book (if available)" << endl;
        cout << "3) Return a book" << endl;
        cout << "4) Finish" << endl;
        cin >> choice;

        switch (choice) {
            case '1':
                for (string book : List_of_books) {
                    cout << book << endl;
                }
                break;

            case '2':
                cout << "Enter the name of the book: ";
                cin.ignore();
                getline(cin, Book_name);
                for (int i = 0; i < 4; i++) {
                    if (Book_name == List_of_books[i] && Books_available[i] == true) {
                        cout << "You're welcome" << endl;
                        Books_available[i] = false;
                        goto continue_menu;
                    }
                    else if (Book_name == List_of_books[i] && Books_available[i] == false) {
                        cout << "It's already taken" << endl;
                        goto continue_menu;
                    }
                }
                cout << "We don't have it. Please try something else!" << endl;
                goto menu;

            case '3':
                cout << "Enter the name of the book: ";
                cin.ignore();
                getline(cin, Book_name);
                for (int i = 0; i < 4; i++) {
                    if (Book_name == List_of_books[i] && Books_available[i] == false) {
                        cout << "Thanks for return" << endl;
                        Books_available[i] = true;
                        goto continue_menu;
                    }
                    else if (Book_name == List_of_books[i] && Books_available[i] == true) {
                        cout << "It's already here" << endl;
                        goto continue_menu;
                    }
                }
                cout << "It's not from here" << endl;
                goto menu;

            case '4':
                in_out = 'N';
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }

    continue_menu:
        cout << "Do you want anything else (Y/N)? ";
        cin >> in_out;

    } while (in_out == 'Y');

    cout << "Goodbye!" << endl;

    return 0;
}
