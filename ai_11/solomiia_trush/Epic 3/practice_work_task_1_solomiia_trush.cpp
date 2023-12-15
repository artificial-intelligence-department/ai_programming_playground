#include <iostream>
#include <vector>
#include <string>

using namespace std;

int number;
string book;
string answer;

vector<string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "The Lord of Rings", "The Adventures of Sherlock Holmes", "Hansel and Gretel", "The Fight Club"};
vector<bool> availability = {true, true, true, true, true, true, true };
void ListOfBooks () {
    for(string k : books) {    
    	cout<<k<<" " << endl;
	}
}

void Availability () {
    for (int i=0; i<books.size() ; i++) {   
        cout << "\n" << books[i] << " - " ;
        if (availability[i]==true) {
            cout << "available";
        }
        else {
            cout << "not available";
        }
    }
    cout << "\n";
}

void TakeBook (int i, string book) {
    if (availability[i]==false) {
        cout << "The book is not available" << endl;
        return;
    }
    else {
        cout << "You took the book "<< book << endl;
        availability[i] = false;
        return;
    }

}

void GiveBack (int i, string book) {
    if (availability[i]==true) {
        cout << "The book wasn't taken" << endl;
        return;
    }
    else {
        cout << "You returned the book "<< book << endl;
        availability[i] = true;
        return;
    }
}

void Operation (int number) {
    switch (number) {
        case 1 :
        cout << "List of books : " << endl;
        ListOfBooks();
        break;
        case 2 :
        Availability();
        break;
        case 3 :
        cout << "Enter the name of the book : " << endl;
        getline(cin, book);
        for (int i=0; i<size(books); i++) {
            if (books[i]==book) {
                TakeBook(i, book);
                break;
            }
        }
        break;
        case 4 : 
        cout << "Enter the name of the book : " << endl;
        getline(cin, book);
        for (int l=0; l<size(books); l++) {
            if (book==books[l]) {
                GiveBack(l, book);
                return;
            }
        }
        break;
    }
}



int main () {
     
     while (true) {
    menu :
        cout << "\n";
        cout << "MENU" << endl;
        cout << "1 List of books" << endl;
        cout << "2 Availability of books" << endl;
        cout << "3 Take the book" << endl;
        cout << "4 Return the book " << endl;
        cout << "5 Exit" << "\n" << endl;

        cout << "Enter number of the operation : " << endl;
        cin >> number;
        cin.ignore();
        if (number!=5) {
        Operation(number);
        }
        else if (number==5) {
            cout << "You've exited the program" << endl;
            return 0;
        }
        else if (number!=1 && number!=2 && number!=3 && number!=4) { 
            cout << "Invalid input. Try again" << endl;
            goto menu;
        }
        do {
            cout << "\n";
            cout << "Do you want to execute another operation? (y/n)" << endl; 
            cin >> answer;
            if (answer[0]=='y') {
               break;
            }
            else if (answer[0]=='n') {
                cout << "You've exited the program";
                return 0;
            }
            else {
                cout << "Invalid input" << endl << "\n";
                goto menu;
            }
        } while (answer[0]=='y');
        
    }

}

