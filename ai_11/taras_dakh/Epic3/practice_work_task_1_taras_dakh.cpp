#include <iostream>
#include <string>

using namespace std;

int main() {

string books[5] = {"Harry Potter", "The Hobbit", "Pride and Prejudice","1984","A way to sucess"};
string availability[5] = {"Available", "Available", "Available", "Available","Available"};
int answer, bookchoise, quitchoise;

do {
Mainmenu:
    cout << "MENU" << endl;
    cout << "1 - List of books" << endl;
    cout << "2 - Take a book" << endl;
    cout << "3 - Return a book" << endl;
    cout << "4 - Quit" << endl;
cin >> answer;

    if (answer == 1) {
        for (int i = 0; i < 5; i++) {
            cout << books[i] << " - " << availability[i] << endl;
            }
        cout << "------------------" << endl;
        goto Quitchoise;
    }
    else if (answer == 2) {
        Takebook:
        cout << "Whick book do you want to take?(1-5)" << endl;
        cout << "6 - Back" << endl;
        cin >> bookchoise;
        if (availability[bookchoise-1]== "Available") {
            cout << "You took " << books[bookchoise-1] << endl;
            availability[bookchoise-1] = "Unavailable"; 
        }
        else if (availability[bookchoise-1]== "Unavailable") {
            cout << "This book is already taken. You can take another one" << endl;
            goto Takebook;
        }
        else if (bookchoise==6) {
            goto Mainmenu;
        }
        else {
            cout << "Unknown choise. Please try again" << endl;
            goto Takebook;
            }
        goto Quitchoise;    
    }
    else if (answer == 3) {
        Returnbook:
        cout << "Which book do you want to return?(1-5)" << endl;
        cout << "6 - Back" << endl;
        cin >> bookchoise;
        if (availability[bookchoise-1]== "Unavailable") {
            cout << "You returned " << books[bookchoise-1] << endl;
            availability[bookchoise-1] = "Available"; 
        }
        else if (availability[bookchoise-1]== "Available") {
            cout << "This book wasn't taken yet" << endl;
            goto Returnbook;
        }
        else if (bookchoise==5) {
            goto Mainmenu;
        }
        else {
            cout << "Unknown choise. Please try again" << endl;
            goto Returnbook;
            }
        goto Quitchoise;

    }
    else if (answer == 4) {
        return 0;
    }
    else {
        cout << "Unknown choise. Please try again" << endl;
        goto Mainmenu;
    }

Quitchoise:
cout << "Do you want to continue?" << endl;
cout << "1 - Yes" << endl;
cout << "2 - No" << endl;
cin >> quitchoise;
if (quitchoise == 1) goto Mainmenu;
else if (quitchoise != 1 && quitchoise != 2) {
    cout << "Unknown choise. Please try again" << endl;
    goto Quitchoise;
}

}
while (quitchoise != 2);
return 0;
}