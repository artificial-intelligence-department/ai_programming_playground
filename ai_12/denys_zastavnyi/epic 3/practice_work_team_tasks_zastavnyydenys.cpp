#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){

    int lib_size = 5;
    short int num;
    string book_name[lib_size];
    string input;
    string input2;
    bool book_available[lib_size];
    bool lib_using = true;

    book_name[0] = "The Whispers";
    book_available[0] = true;

    book_name[1] = "To Kill a Mockingbird";
    book_available[1] = true;

    book_name[2] = "The Lord of the Rings";
    book_available[2] = true;

    book_name[3] = "The Great Gatsby";
    book_available[3] = true;

    book_name[4] = "Harry Potter and the Sorcerer's Stone";
    book_available[4] = true;

    while(lib_using == true){
    mainMenu:
    cout << "Sir, Welcome to Zastavnyy's Library. Make a choise\n";
    cout << "|list all books| (1) |Borrow a book| (2) |Return a book| (3)\n";
    cin >> input;
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    if(input == "1"){

          cout << "Books in the library: \n";
        cout << "----------\n";
        int i = 0;
        for (bool a : book_available){
            cout <<  i+1 << ") " << book_name[i] << endl;
            if(a == true){
                cout << "Book is available\n";
            }else{
                cout << "Book is borrowed\n";
            }
            cout << "----------\n";
            i++;
        }
       
    }else if(input == "2"){

        Borrow: 
        cout << "Choose the book number: \n";
        cin >> num;

        if(num > 0 && num <= lib_size){

            if (book_available[num-1] == true){
                book_available[num-1] = false;
                cout << "You have sucsessfully borrowed a book\n";
            }else{
                cout << "Book is already borrowed!\n";
            }
        }else{
            cout << "There is no such an book.Try again\n";
            cin.clear();
            cin.ignore(10000,'\n');
            goto Borrow;
        }    
        
    }else if(input == "3"){

        Return:
        cout << "Choose the book number: \n";
        cin >> num;

        if(num > 0 && num <= lib_size){
            if (book_available[num-1] == false){
                book_available[num-1] = true;
                cout << "You have sucsessfully returned a book\n";
            }else{
                cout << "Book is not borrowed!\n";
            }
        }else{
            cout << "There is no such a book. Try again\n";
            cin.clear();
            cin.ignore(10000,'\n');
            goto Return;
        }   

    }else{
        cout << "There is no such an option. Try again\n";
        goto mainMenu;
    }
    
    cout<<"If you want to continue print yes, else no\n";
    
    do{   
        cin >> input2;
        transform(input2.begin(), input2.end(), input2.begin(), ::tolower);
        if(input2=="yes") {
           goto mainMenu;
        }
        else if(input2=="no")
        {
            cout << "Not a smart decision to leave such a good library.\n Goodbye!\n";
            lib_using = false;
        }
    }while(input2 !="yes" && input2 != "no");

    }
    return 0;
}