#include <iostream>
#include <vector>
using namespace std;

int main (){

vector<string> books = {"Pride and Prejudice", "To Kill a Mockingbird", "One Hundred Years of Solitude", "Don Quixote", "Nineteen Eighty-Four", "Great Expectations"};
vector<bool> available = {true, true, true, true, true, true};

start:
bool exit = false;
    while (!exit) {
        cout << "LIBRARY\n";
        cout << "1.Show all books\n2.Borrow a book\n3.Return a book\n4.Exit\n";
        cout << "Choose an option: ";

int option;
cin >> option;

if (option == 1) {
    cout << "List of available books:\n";
    for (size_t i = 0; i < books.size(); i++) {
        if (available[i]) {
            cout << i+1 << ". " << books[i] << endl;
        } }

} else if (option == 2) {
    cout << "Enter the number of the book you want to borrow: ";
    int booknum;
    cin >> booknum;
    if (booknum > 0 && booknum <= books.size()) {
                if (available[booknum-1]) {
                    available[booknum-1] = false;
                    cout << "You have borrowed '" << books[booknum-1] << "'.\n";
                } else {
                    cout << "Book '" << books[booknum-1] << "' is not available at the moment.\n";
                }
            } else {
                cout << "Invalid book number.\n";
                goto start;
            } }

else if (option == 3) {
    cout << "Books available for return:\n";
    for (size_t i = 0; i < available.size(); i++) {
            if (!available[i]) {
                cout << i + 1 << ". " << books[i] << endl;
            } } 
    cout << "Enter the number of the book you want to return: ";
    int booknum;
    cin >> booknum;
if (booknum > 0 && booknum <= books.size()) {
            if (!available[booknum-1]) {
                available[booknum-1] = true;
                cout << "You have returned '" << books[booknum-1] << "'.\n";
            } else {
                cout << "Book '" << books[booknum - 1] << "' is available.\n";
            }
        } else {
            cout << "Invalid book number.\n";
            goto start;
        } }

else if (option == 4) {
    return 0; } 

cout << "Do you want to perform another operation? (yes/no): ";
string answer;
cin >> answer;
if (answer == "no") {
    exit = true;
} else if (answer == "yes") {
    goto start;
} else {
    cout << "Invalid input.";
    cout << "\nDo you want to perform another operation? (yes/no): ";
    cin >> answer; 
    } }
    return 0;
}
