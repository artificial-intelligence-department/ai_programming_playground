#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    const short quantity = 4;
    std::vector<std::string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    std::vector<bool> available = {1, 1, 1, 1};

    cout << "Hello!" <<endl;
    string input;

    do {
        Again:
        cout << "How can I help You?\n(list all books/take a book/bring book back/leave)\n-";
        getline(cin, input);
        if (input == "list all books") {
            for (int i = 0; i < quantity; i++) {
            cout << books[i] << " is " << (available[i] ? "available." : "not available.") << '\n';
            }
            cout << endl;
        }
        else if (input == "take a book") {
            cout << "What book do you want to take?\n-";
            getline(cin, input);
            bool correctInput = false;
            for (const auto &book : books) {
                if (input == book) {
                    correctInput = true;
                    if (available[&book - &books[0]]) {
                        cout << "Here you are!" << endl;
                        available[&book - &books[0]] = 0;
                    }
                    else { cout << "This book is not available! Try again later" << endl; }
                    break;
                }
            }
            cout << endl;
            if (!correctInput) goto Again;
        }
        else if (input == "bring book back") {
            cout << "What book do you want to bring back?\n-";
            getline(cin, input);
            bool correctInput = false;
            for (const auto &book: books) {
                if (input == book) {
                    correctInput = true;
                    if (!(available[&book - &books[0]]) ) {
                        cout << "Thank You!" << endl;
                        available[&book - &books[0]] = 1;
                    }
                    else { cout << "You did not take this book from our library!" << endl; }
                    break;
                }
            }
            cout << endl;
            if (!correctInput) goto Again;
        }
        else if (input != "leave") {
            cout << endl;
            goto Again;
        }
    } while (input != "leave");
    cout << "Thank you for visiting!";
    return 0;
}