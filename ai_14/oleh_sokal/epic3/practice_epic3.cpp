#include <iostream>
#include <string>
using namespace std;
int main() {
    int count=0;
    string answer;
    int max = 5;
    string books[5] = {"1984", "Woman in Berlin", "Physchology of influence", "Financier", "Animal Farm A Fairy Story"};
    bool available[5] = {true, true, true, true, true};
    int pick;
    char choice;
    string m; 
    using namespace std;
    LabelMenu:
    if(count==0){
    m="Start?(y/n): ";
    }
    else{
        m= "Keep going?(y|n): ";
    }
    cout << "" << m;
    cin >> answer;
    
    while (answer == "y") {
        count++;
        cout << "   Main Menu\n";
        cout << "1. List of books\n";
        cout << "2. Take a one\n";
        cout << "3. Return a one\n";
        cout << "Choose the option(1/2/3): ";
        cin >> choice;

        if (choice == '1') {
            cout << "List of books:\n";
            for (int i = 0; i < max; i++) {
                cout << i + 1 << ". " << books[i] << " (" << (available[i] ? "Доступна" : "Позичена") << ")\n";
            }
              goto LabelMenu;
            
        } else if (choice == '2') {
            cout << "What one do you want to pick (1-5): ";
            cin >> pick;

            if (pick >= 1 && pick <= max) {
                if (available[pick - 1]==true) {
                    cout << "You took a book '" << books[pick - 1] << "'.\n";
                    available[pick - 1] = false;
                    goto LabelMenu;
                } 
                else {
                    cout << "This book was already taken\n";
                    goto LabelMenu;
                }
            } else {
                cout << "Unknown number\n";
                goto LabelMenu;
            }
        } else if (choice == '3') {
            cout << "What one do you want to return? (1-5): ";
            cin >> pick;

            if (pick >= 1 && pick <= max) {
                if (available[pick - 1] == false) {
                    cout << "You've given <<" << books[pick - 1] << ">> back\n";
                    available[pick - 1] = true;
                } else {
                    cout << "You haven't taken it from the library\n";
                    goto LabelMenu;
                }
            } else {
                cout << "it's no available book with this number.\n";
                goto LabelMenu;
            }
        } 
        else {
            cout << "Maybe mistake. Try again\n";
            goto LabelMenu;
        }
    }

    return 0;
}