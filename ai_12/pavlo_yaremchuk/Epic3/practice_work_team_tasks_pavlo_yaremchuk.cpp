#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> books = {"The Da Vinci Code", "The Lord of the Rings", "Twilight", "Alchemist", "Harry Potter"};
    vector<bool> available = {true, true, true, true, true};
    int number;
    string list = "list", borrow = "borrow", back = "back", exit = "exit", choice, again;
    Start:
    cout << "In our library you can:" << endl;
    cout << "1. See the entire list of books (Enter: ''list'')" << endl;
    cout << "2. Borrow a book (Enter ''borrow'')" << endl;
    cout << "3. Get back a book (Enter ''back'')" << endl;
    cout << "4. Exit (Enter ''exit'')" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    while(choice != exit)
    {
        switch(choice[1])
        {
            case 'i':
            for (int i = 0; i < 5; ++i)
            {
                cout << i + 1 << "." << books[i]<< endl;
            }
            goto Cont;

            case 'o':
            for (auto book : available)
            {
                if(book)
                {
                    cout << "available" << endl;
                }
                else
                {
                    cout << "unavailable" << endl;
                }
            }
            cout << "Enter the book number: ";
            cin >> number;
            if (available[number - 1] == false)
            {
                cout << "Sorry, this book has already been borrowed" << endl;
            }
            else
            {
                available[number - 1] = false;
                cout << "You can borrow this book" << endl;
            }
            goto Cont;
            
            case 'a':
            cout << "Enter the book number: ";
            cin >> number;
            available[number - 1] = true;
            goto Cont;

            default:
            goto Start;
        }

        Cont:
        do
            {
                cout << "Do you want to do something else? (Enter ''yes'' or ''no'')" << endl;
                cin >> again;
                if (again == "yes")
                {
                    goto Start;
                }
            }
            while (again != "no");
            break;
    }
    return 0;
}