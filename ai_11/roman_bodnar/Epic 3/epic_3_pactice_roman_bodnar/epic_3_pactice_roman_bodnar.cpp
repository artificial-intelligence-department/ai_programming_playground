#include <iostream>
using namespace std;

int main() {

    struct Book {
        string name;
        bool available;
    };


    Book books[6];
    bool availability[6];

    for (int i = 0; i < 6; i++) {
        books[0].name = "The Little Prince";
        books[1].name = "Warcross";
        books[2].name = "Wildcard";
        books[3].name = "1984";
        books[4].name = "The Lord of the Rings";
        books[5].name = "The Picture of Dorian Gray";
        availability[i] = true;
    }


    int choice;
    do {
        cout << "Choice:" << endl;
        cout << "1. List the books" << endl;
        cout << "2. Take a book" << endl;
        cout << "3. Return the book" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;


        if (choice == 1) {
            cout << "List of books:" << endl;
            for (int i = 0; i < 6; i++) {
                cout << books[i].name << " (accessibility: " << "available" << ")" << endl;
            }
        }


        else if (choice == 2) {

            string Warcross;
            cout << "Enter the title of the book, which you want to take: ";
            cin >> Warcross;


            int i;
            for (i = 0; i < 6; i++) {
                if (books[i].name == Warcross) {
                    break;
                }
            }


            if (i == 6) {
                cout << "No book with this title was found." << endl;
            }


            else if (availability[i]) {

                availability[i] = true;
                cout << "The book is taken." << endl;
            }


            else {
                cout << "The book is not available." << endl;
            }
        }


        else if (choice == 3) {

            string It;
            cout << "Enter the title of the book you want to return: ";
            cin >> It;

            int i;
            for (i = 0; i < 6; i++) {
                if (books[i].name == It){
                    break;
                }
            }


            if (i == 5) {
                cout << "No book with this title was found." << endl;
            }


            else if (!availability[i]) {

                availability[i] = true;
                cout << "The book is returned." << endl;
            }


            else {
                cout << "The book is already available." << endl;
            }
        }


        else if (choice == 4) {
            break;
        }


        else {
            cout << "Wrong choice." << endl;
        }

    } while (choice != 4);

    goto return_to_main;

    return_to_main:

    return 0;
}