#include<iostream>
using namespace std;

int main(){
    const string Books[] = {"Nausea",
     "How to Disappear Completely and Never Be Found",
     "Oral Sadism and the Vegetarian Personality",
     "Strangers have the best candy"};
    bool Is_Available[] = {1,1,1,1}, exit_the_programm = 0;
    int choice_on_what_to_do;


    while(exit_the_programm == 0){
Start:
    cout << "\nWelcome, what can I do for ya today?\n" << " 1. Borrow a book\n 2. Return a book\n 3. View all books\n 4. Nothing\n";
    cin >> choice_on_what_to_do;

    switch(choice_on_what_to_do)
    {
        case 1:{
            cout << "Great! What book would ya like to borrow?(To go back type any number but 1,2,3,4)\n";
            for(int i = 0; i < 4; i++){
                cout << i+1 << "." << Books[i] << "\n";
            }
            int Which_to_borrow;
            cin >> Which_to_borrow;

            bool bookFound = false;
            for (const string book : Books) {
                if (book == Books[Which_to_borrow - 1]) {
                    if (Is_Available[Which_to_borrow - 1] == 1) {
                        cout << "\nGreat! You borrowed " << Books[Which_to_borrow - 1];
                        Is_Available[Which_to_borrow - 1] = 0;
                        bookFound = true;
                        break;
                    }else{
                        cout << "This one is already taken by someone else, sowwy";
                        bookFound = true;
                        break;
                    }
                }
            }

            if (bookFound != 1) {
                cout << "Book not found :( Please select a valid book\n";
                goto Start;
            }

            break;
        }
        case 2:{
            cout << "Okay, What book would ya like to return?(To go back type any number but 1,2,3,4)\n";
            for(int i = 0; i < 4; i++){
                cout << i+1 << "." << Books[i];
                if (Is_Available[i]==1){
                    cout<< " and it is available!\n";
                }else{
                    cout << " but it isnt available right now\n";
                }
            }
            int book_to_return;
            cin >> book_to_return;
            bool bookFound;

            for (const string book : Books) {
                if (book == Books[book_to_return - 1]) {
                    if (Is_Available[book_to_return - 1] == 0) {
                        cout << "\nGreat! You returned " << Books[book_to_return - 1];
                        Is_Available[book_to_return - 1] = 1;
                        bookFound = true;
                        break;
                    }else{
                        cout << "We already have this one";
                        bookFound = true;
                        break;
                    }
                }
            }
            if (bookFound != 1) {
                cout << "Book not found :( Please select a valid book\n";
                goto Start;
            }

            break;
        }
        case 3:{
            for(int i = 0; i < 4; i++){
                cout << i+1 << "." << Books[i];
                if (Is_Available[i]==1){
                    cout<< " and it is available!\n";
                }else{
                    cout << " but it isnt available right now\n";
                }
            }
            break;
        }
        case 4:{
            cout << "okay bye :(\n";
            return 0;
            break;
        }
        default:{
            cout << "Invalid choice\n";
            break;
        }
            
    }
    do {
            cout << "Is this all?  1 - yeah bye 0 - no, one more thing please: ";
            cin >> exit_the_programm;
        } while (exit_the_programm != 0 && exit_the_programm != 1);
    }
    if(exit_the_programm==1) cout << "okay bye :(\n";
    return 0;
}
