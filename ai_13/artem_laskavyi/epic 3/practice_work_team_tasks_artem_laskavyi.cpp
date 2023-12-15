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

    book_name[0] = "1984";
    book_available[0] = true;

    book_name[1] = "Faust";
    book_available[1] = true;

    book_name[2] = "Moby Dick";
    book_available[2] = true;

    book_name[3] = "Lord of the Rings";
    book_available[3] = true;

    book_name[4] = "The Picture of Dorian Gray";
    book_available[4] = true;

    while(lib_using == true){
    mainMenu:
    cout << "This is main menu. Make a choise\n";
    cout << "|Print all books| (print) |Take a book| (take) |Return a book| (return)\n";
    cin >> input;
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    if(input == "print"){

        cout << "Books in the library: \n";
        cout << "----------\n";
        int i = 0;
        for (bool a : book_available){
            cout <<  i+1 << ") " << book_name[i] << endl;
            if(a == true){
                cout << "Book is available\n";
            }else{
                cout << "Book is taken\n";
            }
            cout << "----------\n";
            i++;
        }
       
    }else if(input == "take"){

        Take: 
        cout << "Choose the book number: \n";
        cin >> num;

        if(num > 0 && num <= lib_size){

            if (book_available[num-1] == true){
                book_available[num-1] = false;
                cout << "You have sucsessfully taken a book\n";
            }else{
                cout << "Book is already taken!\n";
            }
        }else{
            cout << "Invalid input. Try again\n";
            cin.clear();
            cin.ignore(10000,'\n');
            goto Take;
        }    
        
    }else if(input == "return"){

        Return:
        cout << "Choose the book number: \n";
        cin >> num;

        if(num > 0 && num <= lib_size){
            if (book_available[num-1] == false){
                book_available[num-1] = true;
                cout << "You have sucsessfully returned a book\n";
            }else{
                cout << "Book is already in the library!\n";
            }
        }else{
            cout << "Invalid input. Try again\n";
            cin.clear();
            cin.ignore(10000,'\n');
            goto Return;
        }   

    }else{
        cout << "Invalid input. Available options: print, take, return\n";
        goto mainMenu;
    }
    
    cout << "Do you want to choose another option?\n";
    cout << "Print yes to continue, print no to leave the library.\n";
    
    do{   
        cout<<"Yes/No?";
        cin >> input2;
        transform(input2.begin(), input2.end(), input2.begin(), ::tolower);
        if(input2=="yes") {
           goto mainMenu;
        }
        else if(input2=="no")
        {
            cout << "Thank you for using our library!\n Goodbye!\n";
            lib_using = false;
        }
    }while(input2 !="yes" && input2 != "no");

    }
    return 0;
}