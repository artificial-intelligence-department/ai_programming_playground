#include <iostream>
#include <vector>
#include <string>

using namespace std;
int choice;
vector<string> books = { "Harry Potter", "Charlie Chaplin", "Star Wars", "1984", "Encyclopedia"};
size_t range;
string title;
void print();
vector<bool> available = {true, true, true, true, true};
void borrow();
void returns ();
int main(){
    menu:
    {
            bool done = false;
        while(!done){
        range = books.size(); 
            cout << "Library management\n" <<
            "1 - List all books\n" <<
            "2 - Borrow a book\n" <<
            "3 - Return a book\n" <<
            "4 - Exit library\n" <<
            "Enter your choice: " ;
            cin >> choice;
        
        if( choice<=4&&choice>=1 )
                done = true;
        else
        cout <<"Oops... You probably wrote smth different. Please try again\n";
        }
    switch (choice){
    case 1:
        print();
        goto menu;
    case 2:
        borrow();
        goto menu;
    case 3:
        returns();
        goto menu;
    case 4:
        cout << "Have a nice day :)";
        break;
        
 }
}


}
void print(){
for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << books[i] << (available[i] ? " (Available)" : " (Borrowed)") << "\n";
            }    
}
void borrow(){
        cin.ignore();
    cout << "Enter book name to borrow: ";
    getline(cin, title);

    for (const auto &book : books) {
        if (book == title) {
            int index = &book - &books[0];
            if (available[index]) {
                available[index] = false;
                cout << "Book borrowed successfully!\n";
            } else {
                cout << "Book is already borrowed.\n";
            }
            break;
        }
    }
}
void returns(){
        cin.ignore();
    cout << "Enter book name to return: ";
    getline(cin, title);

    for (const auto &book : books) {
        if (book == title) {
            int index = &book - &books[0];
            if (!available[index]) {
                available[index] = true;
                cout << "Book returned successfully!\n";
            } 
            else {
                cout << "Book is not borrowed.\n";
            }
        }
    }
}