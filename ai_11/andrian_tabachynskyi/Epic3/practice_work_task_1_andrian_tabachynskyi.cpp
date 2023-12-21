#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<string> books = { "Harry Potter", "Kings of Narnia", "The Usborne Book of Night Time", "1984","Sherlock Holmes", "Footballer"};
    vector<bool> present = { 1, 0, 1, 1, 0, 1};
    string Name, prodov;
    int yourchoice;


    here:
    do {
        cout << "Menu:\n"<< "1. List all books\n"<< "2. Return a book\n"<< "3. Take a book\n"<< "4. Exit\n"<< "Choose one of the options: ";
        cin >> yourchoice; 

        switch (yourchoice) {
        case 1:
            for (int i = 0; i < books.size(); i++) {

                cout << books[i] << ": " << (present[i] ? "Available" : "Borrowed") << endl;
            }
            break;

        case 2:
            cin.ignore();

            cout << "Enter book name to return: ";
            getline(cin, Name);


            for (string& book : books) {
                if (book == Name) {
                    int i = &book - &books[0];
                    if (!present[i]) {
                        present[i] = 1;
                        cout << "You return the book, thank you!\n";
                        break;
                    }
                    else {
                        cout << "You didn't take this book\n";
                        break;
                    }
                }
            }
            break;

        case 3:
            cin.ignore();

            cout << "Enter book name to take: ";
            getline(cin, Name);

            for (string& book : books) {
                if (book == Name) {

                    int i = &book - &books[0];

                    if (present[i]) {
                        present[i] = 0;
                        cout << "You take the book\n";
                        break;
                    }
                    else {
                        cout << "This book is taken\n";
                        break;
                    }
                }
            }
            break;

        case 4:
            cout << "Goodbye!!!";

            return 0;

        default: goto here;
        }

        cout << "Do you want to chose another operation?(Yes/No):";
        cin >> prodov;

        if (prodov == "No") {
            cout << "Goodbye! See you soon)";
            return 0;
        }

    } while (prodov == "Yes");
}
