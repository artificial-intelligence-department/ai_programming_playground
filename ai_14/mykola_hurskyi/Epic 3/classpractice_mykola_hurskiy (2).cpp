#include <iostream>
#include <string>
#include <vector>
#include <limits> 
#include <cstdlib> 
using namespace std;

int main()
{
    vector<string> books = { "50 shapes of grey", "Harry Potter", "Zakhar Berkut", "Kobzar", "Faust", "1984", "Vacation" };
    vector<string> available = books;

    while (true)
    {
        cout << "1 - list the books\n2 - borrow a book\n3 - return a book\n4 - check availability of a book\n5 - exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "\033[35m" << "All existing books:" << "\033[37m" << endl;
            for (const auto& book : books)
            {
                cout << book << endl;
            }

            cout << "\n\033[35m" << "Available books:" << "\033[37m" << endl;
            for (const auto& book : available)
            {
                if (book != "none")
                {
                    cout << "\033[32m" << book << "\033[37m" << endl;
                }
            }
        }
        else if (choice == 2)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string strchoice;
            do
            {
                cout << "Enter the name of a book or type <<return>> to quit: ";
                getline(cin, strchoice);

                bool success = false;
                for (size_t i = 0; i < available.size(); ++i)
                {
                    if (strchoice == available[i])
                    {
                        available[i] = "none";
                        success = true;
                        cout << "\033[32m" << "You successfully borrowed a book" << "\033[37m" << endl;
                        break; 
                    }
                }

                if (!success && strchoice != "return")
                {
                    cout << "\033[31m" << "There is no such book. Try again" << "\033[37m" << endl;
                }
            } while (strchoice != "return");
        }
        else if (choice == 3)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string strchoice2;
            do
            {
                cout << "Enter the name of a book you want to return or type <<return>> to quit: ";
                getline(cin, strchoice2);

                bool success = false;
                for (size_t i = 0; i < books.size(); ++i)
                {
                    if (strchoice2 == books[i] && available[i] == "none")
                    {
                        available[i] = strchoice2;
                        success = true;
                        cout << "\033[32m" << "You successfully returned the book" << "\033[37m" << endl;
                        break; 
                    }
                }

                if (!success && strchoice2 != "return")
                {
                    cout << "\033[31m" << "The book doesn't belong to our library or is already available" << "\033[37m" << endl;
                }
            } while (strchoice2 != "return");
        }
        else if (choice == 4)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string strchoice3;
            do
            {
                cout << "Enter the name of a book you want to check on availability: ";
                getline(cin, strchoice3);

                bool success = false;
                for (const auto& book : available)
                {
                    if (book == strchoice3)
                    {
                        success = true;
                        cout << "\033[32m" << "The book is available" "\033[37m" << endl;
                        break; 
                    }
                }

                if (!success && strchoice3 != "return")
                {
                    cout << "\033[31m" << "The book isn't available" << "\033[37m" << endl;
                }
            } while (strchoice3 != "return");
        }
        else if (choice == 5)
        {
            cout << "\033[36m" << "Powered by Daniil Shevchenko. Goodbye" << "\033[37m";
            system("pause"); 
            break;
        }
        else
        {
            cout << "\033[31m" << "Invalid choice. Please try again." << "\033[37m" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
