#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    char continueChoice;
    vector<string> books{"Becoming", "Faust", "The Amber Spyglass", "Autumn", "Sapiens"};

do {
    int userChoice;
    cout << "Welcome to our library! Here's what we offer:" << endl;
    cout << "1. Display list of books" << endl;
    cout << "2. Borrow a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "4. Exit" << endl;
    cout << "Please enter your choice (1-4):" << endl;

while (!(cin >> userChoice) || userChoice < 1 || userChoice > 4) {
    cout << "Invalid input. Please enter a number from 1 to 4." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

switch (userChoice) {
case 1:
        cout << "Here's our collection of books:" << endl;
    for (const string& book : books) {
        cout << "- " << book << endl;
            }
    break;

case 2: 
{
    string chosenBook;
        cout << "Which book would you like to borrow?" << endl;
        cin.ignore();
    getline(cin, chosenBook);
    auto it = find(books.begin(), books.end(), chosenBook);
    if (it != books.end()) {
    books.erase(it);
        cout << "You've successfully borrowed the book: " << chosenBook << endl;
    if (books.empty()) {
        cout << "All books are currently borrowed." << endl;
}
    }
     else {
        cout << "Sorry, the book " << chosenBook << " is not available." << endl;
}
}
    break;

case 3:
{
    string returnedBook;
        cout << "Which book are you returning?" << endl;
        cin.ignore();
    getline(cin, returnedBook);
    books.push_back(returnedBook);
        cout << "You've successfully returned the book: " << returnedBook << endl;
}
break;

case 4:
        cout << "Thank you for using our library services. Goodbye!" << endl;
    return 0;

default:
        cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
    break;
}

        cout << "Would you like to continue? (y/n): " << endl;
        cin >> continueChoice;

    } 

while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}
