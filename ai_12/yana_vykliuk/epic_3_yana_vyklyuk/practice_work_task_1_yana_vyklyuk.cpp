#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <string> books;
    books.push_back("Sherlock Holmes");
    books.push_back("1984");
    books.push_back("It");
    books.push_back("The Picture of Dorian Gray");
    
    vector <string> is_available;
    for (int i = 0; i < books.size(); i++)
    {
        is_available.push_back("available");
    }

    string borrow_book, return_book, next_option;
    int option;

    Start_menu:

        cout << "Choose your option: \n1 - borrow\n2 - return\n3 - recalculate\n4 - exit" << endl;
        cin >> option;

        while(option != 4)
        {
            if (option != 1 && option != 2 && option != 3)
            {
                cout << "Enter available option!" << endl;
                goto Start_menu;
            }

            if (option == 3)
            {
                for (int i = 0; i < books.size(); i++)
                {
                    cout << "The book " << books[i] << " is " << is_available[i] << endl;
                }
            }

            if (option == 1)
            {
                cout << "Choose the book you wanna borrow: \n";
                for (int i = 0; i < books.size(); i++)
                {
                    cout << books[i] << " is " << is_available[i] << endl;
                }

                cin.ignore();
                getline(cin, borrow_book);

                bool av_book = false;

                for (int i = 0; i < books.size(); i++)
                {
                    if(borrow_book == books[i] && is_available[i] == "available")
                    {
                        cout << "You borrow: " << borrow_book << endl;
                        is_available[i] = "unavailable";
                        av_book = true;
                        break;
                    }
                }  
            
                if (av_book != true)
                {
                    cout << "Unfortunately, this book is unavailable :(" << endl;
                }
            }

            if(option == 2)
            {
                cout << "Oh, you finally decided to return the book you borrowed. Please name it!" << endl;

                cin.ignore();
                getline(cin, return_book);

                bool rt_book = false;

                for (int i = 0; i < books.size(); i++)
                {
                    if (return_book == books[i] && is_available[i] == "unavailable")
                    {
                        cout << "Sadly, you won't pay any fine" << endl;
                        is_available[i] = "available";
                        rt_book = true;
                        break;
                    }
                    else if(return_book == books[i] && is_available[i] == "available")
                    {
                        cout << "You did not borrow this book!" << endl;
                        rt_book = true;
                        break;
                    }
                }

                if(rt_book != true)
                {
                    cout << "This book was not in our library, but you can present it to us)" << endl;
                }
            }

            bool nxt = false;
            do
            {
                cout << "Do you want to do any other option? (yes or no)" << endl;
                cin.clear();
                cin >> next_option;
                
                if (next_option == "yes")
                {
                    nxt = true;
                    cout << "Choose your option: \n1 - borrow\n2 - return\n3 - recalculate\n4 - exit" << endl;
                    cin.ignore();
                    cin >> option;
                    break;
                }
                else if (next_option == "no")
                {
                    option = 4;
                    nxt = true;
                    break;
                }
                
                cout << "Enter correct answer!" << endl;
            } 
            while (nxt != true);
            
        }
        cout << "Thanks)" << endl;
    return 0;
}
