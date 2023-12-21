#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<string> booklist = {"The Hunger Games", "The Da Vinci Code", "To Kill a Mockingbird", "Harry Potter", "Bible"};
    vector<bool> availability = {true, true, true, true, true};
    int option;
    string bookTitle;
    char decision;

    menu:
    cout << "What action do You want to take?" << endl;
    cout << "1) View the booklist" << endl;
    cout << "2) Choose a book" << endl;
    cout << "3) Return a book" << endl;
    cout << "4) Exit" << endl;
    cout << "Enter a number of action: ";
    cin >> option;

    if (option == 1) {
        for (int a=0; a < booklist.size(); a++) {
            if(availability[a]){
                cout << a+1 << ") " << booklist[a] << " is available." << endl;
            } else {
                cout << a+1 << ") " << booklist[a] << " is not available at the moment." << endl;
            }
        }
    } else if (option == 2) {
        cin.ignore();
        cout << "Which book You want to choose?" << endl;
        getline(cin, bookTitle);

        for (const auto &book : booklist) {
            if (book == bookTitle) {
              int a = &book - &booklist[0];

              if (availability[a]) {
                availability[a] = false;
                cout << "You chose " << booklist[a] << ". Enjoy it!" << endl;
              } else {
                cout << "Unfortunatelly, " << booklist[a] << " is not available at the moment." << endl;
            }
            break;
            } 
        }
    } else if (option == 3) {
        cin.ignore();
        cout << "Which book You want to return?" << endl;
        getline(cin, bookTitle);

        for (const auto &book : booklist) {
            if (book == bookTitle) {
            int a = &book - &booklist[0];

            if (!availability[a]) {
                availability[a] = true;
                cout << "You returned " << booklist[a] << ". Thanks!" << endl;
            } else {
                cout << "You did not borrow " << booklist[a] << "." << endl;
            }
            break;
            }
        }
    } else if (option == 4) {
        do {
            cout << "Are you sure?" << endl;
            cin >> decision;
        } while (decision != 'Y' && decision != 'y' && decision != 'n' && decision != 'N');
        
        if (decision == 'Y' || decision == 'y') {
            cout << "We look forward to hear You again soon!" << endl;
            return 0;
        } else {goto menu;}
    } else { 
        cout << "Wrong option." << endl;
        goto menu;
    }

    char choice;
    do {
        cout << "Do You want to take another action?" << endl;
        cin >> choice;
    } while (choice != 'Y' && choice != 'y' && choice != 'n' && choice != 'N');

    if (choice == 'Y' || choice == 'y') {
        goto menu;
    } else {
        cout << "You borrowed: " << endl;
        for (int a=0; a<booklist.size(); a++) {
            if(!availability[a]){
              cout << booklist[a] << endl;
            }
        }
        cout << "Have a nice read. We look forward to hear You again soon!" << endl;
    }

    return 0;
}