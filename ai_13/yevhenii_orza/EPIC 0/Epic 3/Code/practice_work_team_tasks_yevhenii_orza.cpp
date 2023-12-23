#include <iostream>
#include <vector>
using namespace std;

int choose = 0;
int bookStatusCheck = 0;

int main() {
    
    vector<string> books = {
        "Harry Potter and the Deathly Hallows",
        "The Da Vinci Code",
        "She: A History of Adventure",
        "A Tale of Two Cities",
        "Don Quixote"
    };
    
    vector<int> available = {
        1, 1, 1, 1, 1
    };

    vector<string> functions = {
        "List of Books",
        "Take Book",
        "Return Book",
        "Exit from the Library"
    };

    do {
        cout << "Choose what you want to do:" << endl;
        for(int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << functions[i] << endl;
            cout << endl;
        }
        cout << endl;
        cin >> choose;

        switch (choose) {
            case 1:
                for(int b = 0; b < 5; b++) {
                    cout << b + 1 << ". " << books[b] << endl;
                    if (available[b] == 1) {
                        cout << "Available" << endl;
                    } else {
                        cout << "Not Available" << endl;
                    }
                }
                break;
            case 2:
                cout << "What book do you want to take? (Enter number 1-5)" << endl;
                cin >> bookStatusCheck;
                if (available[bookStatusCheck - 1] == 0) {
                    cout << "You can't take this book; it is unavailable" << endl;
                } else {
                    available[bookStatusCheck - 1] = 0;
                    cout << "Here is your book" << endl;
                }
                break;
            case 3:
                cout << "What book are you returning? (Enter number 1-5)" << endl;
                cin >> bookStatusCheck;
                if (available[bookStatusCheck - 1] == 1) {
                    cout << "You already returned this book" << endl;
                } else {
                    available[bookStatusCheck - 1] = 1;
                    cout << "Book is returned" << endl;
                }
                break;
            case 4:
                cout << "Have a nice day!" << endl;
                break;
            default:
                cout << "Please choose a number between 1 and 4" << endl;    
        } 
    } while (choose != 4);

    return 0;
}
