#include <iostream>
#include <string>


using namespace std;




int main() {
    int count = 0, maxBooks = 4;
    string answer;
    string books[maxBooks] = { "Bible", "1984", "Brave new world", "Thus Spake Zarathustra"};
    bool available[maxBooks] = {true, true, true, true};
    int pick;
    char choice;


    do {
        cout << (count == 0 ? "Start?" : "Keep going?") << " (y/n): ";
        cin >> answer;


        if (answer != "y") {
            break;
        }


        cout << "   Main Menu\n";
        cout << "1. List of books\n";
        cout << "2. Take a one\n";
        cout << "3. Return a one\n";
        cout << "Choose the option (1/2/3): ";
        cin >> choice;


        switch (choice) {
            case '1': {
                cout << "List of books:\n";
                for (int i = 0; i < maxBooks; i++) {
                    cout << i + 1 << ". " << books[i] << " (" << (available[i] ? "Available" : "Borrowed") << ")\n";
                }
                break;
            }
            case '2': {
                cout << "What one do you want to pick (1-" << maxBooks << "): ";
                cin >> pick;


                if (pick >= 1 && pick <= maxBooks) {
                    if (available[pick - 1]) {
                        cout << "You took a book '" << books[pick - 1] << "'.\n";
                        available[pick - 1] = false;
                    } else {
                        cout << "This book was already taken\n";
                    }
                } else {
                    cout << "Unknown number\n";
                }
                break;
            }
            case '3': {
                cout << "What one do you want to return? (1-" << maxBooks << "): ";
                cin >> pick;


                if (pick >= 1 && pick <= maxBooks) {
                    if (!available[pick - 1]) {
                        cout << "You've returned '" << books[pick - 1] << "'.\n";
                        available[pick - 1] = true;
                    } else {
                        cout << "You haven't taken it from the library\n";
                    }
                } else {
                    cout << "No available book with this number.\n";
                }
                break;
            }
            default:
                cout << "Maybe a mistake. Try again\n";
        }
    } while (true);


    cout << "Thank you for using the library. Have a good day!\n";


    return 0;
}
