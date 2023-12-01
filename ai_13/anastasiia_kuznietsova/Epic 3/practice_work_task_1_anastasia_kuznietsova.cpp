#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main ()
{

    vector<string> books = {"The Seven Husbands of Evelyn Hugo","I see you are interested in the dark","The Maid","A silent witness","Harry Potter"};
    string name, answer;
    vector <bool> status = {false, true, false ,true, true};
    int option;

menu:
    cout<<"\nMenu:\n";

    cout<<"1. List of books in the library\n";
    cout<<"2. To borrow a book\n";
    cout<<"3. To return a book\n";
    cout<<"4. Exit\n";

    cin>>option;

switch(option)
    {
    case 1:
        cout<<"List of the books in the library:\n";
        for (int i=0; i<books.size(); i++)
        {
            cout<<i+1<<". "<<books[i]<<"\n";
        }
    break;
    case 2:
    cin.ignore();
        cout<<"Enter a name of the book you want to borrow\n";
        getline(cin,name);

        for(const auto&book : books)
        {
            if (book == name)
            {
                int number = &book - &books[0];
                if (status[number])
                {
                    status[number]=false;
                    cout<<"You borrowed a book successfully";
                }
                else
                {cout<<"Sorry, this book is already borrowed or doesn't exist";}
            break;
            }
        }
    break;
    case 3:
    cin.ignore();
        cout<<"Enter a name of the book you want to return\n";
        getline(cin,name);

        for(const auto&book : books)
        {
            if (book == name)
            {
                int number = &book - &books[0];
                if (!status[number])
                {
                    status[number]=true;
                    cout<<"You returned a book successfully";
                }
                else{cout<<"Sorry, this book wasn't borrowed or doesn't exist";}
            break;
            }
        }
    break;
    case 4:
        return 0;
    }
cout<<"\nDo you want to go to the menu?\n";
cin>>answer;
if (answer == "yes" || answer == "Yes" || answer == "YES")
{
    goto menu;
}
else
{
    return 0;
}

return 0;
}