#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> books = {"It", "The Green Mile","Pet Sematary","The Boogeyman"};
    vector<bool> available = {true, true, true, true};
    int selection;
    string BookName;
    int k = 0;
    
    do
    {
        cout << "Library Manegement\n";
        cout << "1. List all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Enter your selection: ";
        cin >> selection;

        switch (selection)
        {
            case 1:
                for (int i = 0; i < 4; i++) {
                    cout << i + 1 << ". " << books[i] << (available[i] ? " (Available)": "(Borrowed )") << "\n";
                }
            break;

            case 2:
                cin.ignore();
                cout << "Enter book name to borrow: ";
                getline(cin, BookName);

                for (int i = 0; i < 4; i++) {
                    if (books[i] == BookName) {

                        if (available[i] == true) {
                            available[i] = false;
                            cout << "Book borrowed successfully!\n";
                            k = 1;
                        }
                        else {
                            cout << "Book is already borrowed\n";
                            k = 1;
                        }
                    }
                }
                if(k == 0) {
                    cout << "Wrong input. Please try again\n";
                }
            break;

            case 3:
                cin.ignore();
                cout << "Enter book name to return:";
                getline(cin, BookName);
                for (int i = 0; i < 4; i++) {
                    if (books[i] == BookName) {
                        if (available[i] == false) {
                            available[i] = true;
                            cout << "Book returned successfully!\n";
                            k = 1;
                        } 
                        else {
                            cout << "Book wasn't borrowed\n";
                            k = 1;
                        }
                    }
                }
                if(k == 0) {
                    cout << "Wrong input. Please try again\n";
                }
            break;

            case 4:
                cout << "Goodbye!";
                return 0; 
            default: {
                cout << "Wrong input. Please, try again\n";
            }
            
        }
    } 
    while (true);

    return 0;
}
