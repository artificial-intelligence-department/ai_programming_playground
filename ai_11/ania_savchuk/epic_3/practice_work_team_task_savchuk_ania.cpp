#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 
 
int main() { 
    vector <string> books = {"Lord of the Rings", "Chronicles of Narnia", "Heidi", "1984"}; 
    vector <bool> available = {true, true, true, true}; 
    int operation; 
    string book; 
 
    while (true) { 
        Menu:
        cout << "Library Management" << endl; 
        cout << "1. List all books" << endl; 
        cout << "2. Borrow a book" << endl; 
        cout << "3. Return a book" << endl; 
        cout << "4. Exit the program" << endl; 
        cout << "Enter your operation: " << endl; 
        cin >> operation; 

        if (operation == 1){
            for (int i = 0; i < 4; i++) { 
                cout << i + 1 << ". " << books[i] << endl ; 
            }
        }else if(operation == 2){
            cout << "Enter book name to borrow: "; 
            string book;
            cin >> book; 
 
            for (int i = 0; i < 4 ; i++) { 
                if (books[i] == book) { 
                    if (available[i]) { 
                        available[i] = false; 
                        cout << "This book borrowed successfully!" << endl; 
                    } else { 
                        cout << "Sorry, this book is already borrowed" << endl; 
                    } 
                } 
            }
        }else if(operation == 3){
            cout << "Enter book name to return: "; 
            string book;
            cin >> book; 
 
            for (int i = 0; i < 4; i++) { 
                if (books[i] == book) { 
                    if (!available[i]) { 
                        available[i] = true; 
                        cout << "Book returned successfully!" << endl; 
                    } else { 
                        cout << "Book wasn't borrowed" << endl; 
                    } 
                } 
            }
        }else if (operation == 4){
            cout << "Goodbye!";
            break;
        }else{
            cout << "Invalid operation. Please enter a valid operation." << endl;
            goto Menu;
            break;
        }
 
        string continueChoice; 
        do { 
            cout << "Do you want to perform another operation? (Yes or No): "; 
            cin >> continueChoice; 
           if(continueChoice == "no"){
                return 0;
           }else{
                break;
           }
        }while (continueChoice == "yes");
    } 
 
    return 0; 
}

