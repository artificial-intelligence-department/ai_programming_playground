#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<string> books = {"Harry Potter", "C++ for kettles", "The Grinch", "Breaking Bad", "a-ba-ba-ga-la-ma-ga"};
    vector<bool> available = {true, true, true, true, true};
    vector<string> taken;
    int n;
    do {
        cout << "Welcome to Serhii`s library\n";
        cout << "1. List all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. List borrowed books\n";
        cout << "5. Exit\n";
        cout << "Enter your action: ";
        cin >> n;
        switch (n) {
            case 1:
                cout << "Available books:\n";
                for (int i = 0; i < books.size(); ++i) {
                    if (available[i]) {
                        cout << books[i] << endl;
                    }
                }
                cout << "\n";
                break;
            case 2:
                {
                    string minus;
                    cout << "Enter the book you want to borrow: ";
                    cin.ignore();
                    getline(cin, minus);
                    int num = -1;
                    for (int i = 0; i < books.size(); ++i) {
                        if (books[i] == minus && available[i]) {
                            num = i;
                            break;
                        }
                    }
                    if (num != -1) {
                        cout << "You have successfully borrowed " << minus << ".\n";
                        cout << "\n";
                        available[num] = false;
                        taken.push_back(minus);
                    } else {
                        cout << "Sorry, the book is unavailable.\n";
                        cout << "\n";
                    }
                }
                break;
            case 3:
                {
                    string plus;
                    cout << "Enter the book you want to return: ";
                    cin.ignore();
                    getline(cin, plus);
                    int num = -1;
                    for (int i = 0; i < taken.size(); ++i) {
                        if (taken[i] == plus) {
                            num = i;
                            break;
                        }
                    }
                    if (num != -1) {
                        cout << "You have successfully returned " << plus << ".\n";
                        cout << "\n";
                        taken.erase(taken.begin() + num);
                        for (int i = 0; i < books.size(); ++i) {
                            if (books[i] == plus) {
                                available[i] = true;
                                break;
                            }
                        }
                    } else {
                        cout << "Sorry, the book was not borrowed.\n";
                        cout << "\n";
                    }
                }
                break;
            case 4:
                cout << "Borrowed books:\n";
                for (const string& book : taken) {
                    cout << book << endl;
                }
                cout << "\n";
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid action. Please try again.\n";
                cout << "\n";
        }
    } while (n != 5);
    return 0;
}
