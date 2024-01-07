#include <iostream> 
#include <vector>
#include <string>
using namespace std;

int main(){
    vector <string> books = { "Harry_Potter", "The_Hobbit", "Pride_and_Prejudice", "1984" }; 
    int SIZE = books.size();
    vector <bool> available = { true, true, true, true };
    string books_i_took;
    string empty = "Exit";
    bool exit = false;
    int choice;

    while (exit == false) {

    start: cout << "\nLIBRARY MENU\n";
        cout << "1.List of books\n";
        cout << "2.Availability of books\n";
        cout << "3.Borrow a book\n";
        cout << "4.Return a book\n";
        cout << "5.Exit\n\n";
        cout << "Choose one of the option: ";
        cin >> choice;

        switch (choice) {

            case 1: 
            {
                for (int i = 0, p = 1; i < SIZE; i++, p++) {
                    cout << p << ". " << books[i] << endl;
                } 
                int x;
                cout << "To exit press 0: ";
                cin >> x;
                cout << endl;
                while(x != 0 ){
                    cout << "To exit press 0: ";
                    cin >> x;
                }
            } break;

            case 2: 
            {
                for (int i = 0, k = 0, p = 0; i < SIZE; i++) {
                    if (available[i] == true) {
                        k++;
                        cout << k << ". " << books[i] << " is available\n";
                    }
                } 

                cout << endl;
                for (int i = 0, k = 0, p = 0; i < SIZE; i++) {
                    if (available[i] == false) {
                        p++;
                        cout << p << ". " << books[i] << " isn't available\n";
                    }
                } 

                int x;
                cout << "To exit press 0: ";
                cin >> x;
                cout << endl;
                while(x != 0 ){
                    cout << "To exit press 0: ";
                    cin >> x;
                }
            } break;

            case 3:
            {
                for (int i = 0, k = 0; i < SIZE; i++) {
                    if (available[i] == true) {
                        k++;
                        cout << k << ". " << books[i] << " is available\n";
                    }
                }

                cout << "Choose the book you want to borrow or come back to the menu (You can borrow only one book): ";
                cin >> books_i_took;
                if (books_i_took == empty) {
                    goto menu;
                }
                
                bool review = false;
                while(review == false) {
                    if (books[0] != books_i_took && books[1] != books_i_took && books[2] != books_i_took && books[3] != books_i_took) {
                        cout << "Choose another one: ";
                        cin >> books_i_took;
                    }
                    else review = true;
                }

                for (int i = 0; i < SIZE; i++) {
                    if (books[i] == books_i_took) {
                        if (available[i] == true) {
                            cout << "You just borrow this book\n\n";
                            available[i] = false;
                            break;
                        }
                        else if (available[i] == false) {
                            cout << "This book isn't available. Choose another one.\n\n";
                            break;
                        }
                    }
                    else continue;
                }
            } break;

            case 4:
            {
                if (books_i_took == "") {
                    cout << "You didn't borrow anything" << endl;
                }
                cout << "You borrow \"" << books_i_took << "\"\nYou can return it." << endl;
                cout << "To return this book press 1/to exit press 0: ";
                int return_but;
                cin >> return_but;
                cout << endl;
                bool review = false;
                while(review == false){
                    if (return_but == 0 || return_but == 1) review = true;
                    else {
                        cout << "To return this book press 1/to exit press 0: ";
                        cin >> return_but;
                        cout << endl;
                    }
                }
                
                if (return_but == 0) goto menu;
                if (return_but == 1) 
                    for (int i = 0; i < SIZE; i++) {
                        if (books[i] == books_i_took) {
                            if (available[i] == false) {
                                cout << "You just return this book\n\n";
                                available[i] = true;
                                books_i_took = "";
                                break;
                            }
                        }
                        else continue;
                    }
            } break;

            case 5: 
            {
                cout << "\nYou leave the library";
                exit = true;
                return 0;
            } break;

            default: 
            {
                cout << "You input wrong number. Try again: ";
                cin >> choice;
            }
        }

    menu: char choice_to_con;
        do {
            cout << "Do you rant to continue? Y/N: ";
            cin >> choice_to_con;
            if (choice_to_con == 'Y') goto start;
            else if (choice_to_con == 'N') {
                cout << "\nYou leave the library";
                return 0;
            }
            else {
                cout << "Try again: ";
                cin >> choice_to_con;
            }
        } while (choice_to_con != 'Y' || choice_to_con != 'N');
    }
    return 0;
}