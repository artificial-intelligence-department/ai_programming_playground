#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> books = {"This summer I turned pretty", "Harry Potter", "Book Lovers"};
    vector<bool> availability = {true, true, true};

    while (true) {
        cout << "1.Borrow a book\n";
        cout << "2)Return a book\n";
        cout << "3)List all books\n";
        cout << "4)Exit\n";

        int choice;
        cout << "Select operation: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                {
                    cout << "Available books:\n";
                    for (int i = 0; i < books.size(); ++i) {
                        if (availability[i]) {
                            cout << i + 1 << ". " << books[i] << endl;
                        }
                    }

                    int bookChoice;
                    cout << "Choose number of book you want to take: ";
                    cin >> bookChoice;

                    if (bookChoice > 0 && bookChoice <= books.size() && availability[bookChoice - 1]) {
                        cout << "You took a book: " << books[bookChoice - 1] << endl;
                        availability[bookChoice - 1] = false;
                    } else {
                        cout << "Book is not available\n";
                        goto mainMenu;
                    }
                }
                break;

            case 2:  
                {
                    cout << "Books you took early:\n";
                    for (int i = 0; i < books.size(); ++i) {
                        if (!availability[i]) {
                            cout << i + 1 << ". " << books[i] << endl;
                        }
                    }

                    int returnChoice;
                    cout << "Choose number of book you want to return: ";
                    cin >> returnChoice;

                    if (returnChoice > 0 && returnChoice <= books.size() && !availability[returnChoice - 1]) {
                        cout << "You return book: " << books[returnChoice - 1] << endl;
                        availability[returnChoice - 1] = true;
                    } else {
                        cout << "Wrong choice\n";
                        goto mainMenu;
                    }
                }
                break;

            case 3: 
                cout << "All books:\n";
                for (const auto& book : books) {
                    cout << book << endl;
                }
                break;

            case 4:  
                cout << "Thanks for using our library. Bye!\n";
                return 0;

            default:
                cout << "Wrong choice. Try again! \n";
                goto mainMenu;
        }

        mainMenu:
        cout << "Do you want to perform another operation? (1 - yes, 0 - exit): ";
        cin >> choice;
        if (choice == 0) {
            break;
        }
    }

    return 0;
}
