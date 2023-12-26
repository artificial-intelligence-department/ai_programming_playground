#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string getBook, returnBook;
    vector<string> availability = {"(Available)", "(Available)", "(Available)", "(Available)"};
    vector<string> shelf = {"Metamorphosis", "Brave new world", "Industrial society and its future", "1984"};
    int choice;
    bool cond = true;
    bool working = true;
    while (working == true)
    {
    Menu:
        cout << "0 - End \n1 - Borrow the book \n2 - Return the book \n3 - Show all books\n";
        cin >> choice;

        if (choice!= 0 && choice != 1 && choice != 2 && choice != 3)
        {
            cout << "Try again" << endl;
            goto Menu;
        } 
        else 
        {
            if (choice==3)
            {
                for (int i = 0; i < shelf.size(); i++)
                {
                    cout << shelf[i] <<"\n";
                }
            } 
            else if (choice == 1)
            {
                cout << "Choose the book: ";
                for (int i = 0; i < shelf.size(); i++)
                {
                    cout << "\n" << i+1 << " " << "\"" << shelf[i] << "\"" << " " << availability[i] << " " <<"\n";
                }
                cin.ignore();
                getline(cin, getBook);

                for(int i = 0; i < 4; i++)
                {
                    if (shelf[i] == getBook)
                    {
                        if(availability[i]=="(Available)")
                        {
                            cout << "You borrowed " << "\"" << shelf[i] << "\"" << endl;
                            availability[i] = "(Unavailable)";
                        } else
                        {
                            cout << "This book is unavailable" << endl;
                        }
                        cond = false;
                        break;
                    } else{
                        cond = true;
                    }
                }
                if(cond == true)
                {
                    cout << "Error" << endl;
                }
            } else if (choice == 2)
            {
                cout << "What book do you want to return?";
                cin.ignore();
                getline(cin, returnBook);
                for(int i = 0; i < 4; i++)
                {
                    if (returnBook == shelf[i] &&availability[i]!="(Unavailable)")
                    {
                        cout << "You returned " << "\"" << returnBook << "\"" << endl;
                        availability[i] = "(Available)";
                        cond = false;
                        break;
                    } 
                    else if(returnBook == shelf[i] && availability[i]=="(Available)") 
                    {
                        cout << "Wrong input" << endl;
                        cond = false;
                        break;
                    }
                }
                if (cond == true)
                {
                    cout << "Error" << endl;
                    goto Menu;
                }
            } 
            else if (choice == 0)
            {
                cout << "Thanks for coming";
                break;
            }

            do
            {
                cout << "Anything else?\n1 - yes\n2 - no\n";
                int k;
                cin >> k;
                if (k == 1)
                {
                    goto Menu;
                } 
                else if (k == 2)
                {
                    cout << "Thanks for coming";
                    working = false;
                    break;
                }
                else 
                {
                    cout << "Try again" << endl;
                }
            } 
            while (true);  
        }
    }
    return 0;
}
