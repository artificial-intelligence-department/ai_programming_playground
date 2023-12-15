#include <iostream>
using namespace std;

int main()
{
    const string books[] = {"Atomic Habits", "Meditations", "Lord of the Flies", "The Stranger"};
    bool available[] = {true, true, true, true}, resume = true;
    char cont;
    int scenario;
    
    while(resume == true)
    {
        Start:
            cout << "What do you want to do?\n1 - Take a book\n2 - Return a book\n3 - View all books\n4 - Exit\n";
            cin >> scenario;
            switch (scenario)
            {
                case 1:
                {
                    cout << "Choose a book you want to take:\n -Atomic Habits\n -Meditations\n -Lord of the Flies\n -The Stranger\nBack - Go to the main menu\n";
                    bool existing_book = false;
                    string book_choice;
                    cin.ignore();
                    getline(cin, book_choice);
                    cout << "================================\n";
                    if (book_choice == "Back") goto Start;
                    for (const auto book : books)
                    {
                        if (book == book_choice)
                        {
                            existing_book = true;
                            for (int i = 0; i < 4; i++)
                            {
                                if (book_choice == books[i] && available[i] == true)
                                {
                                    cout << "You took the book " << books[i] << "\nDon`t forget to return it!\n";
                                    cout << "================================\n";
                                    available[i] = false;
                                    break;
                                }
                                else if (book_choice == books[i] && available[i] == false)
                                {
                                    cout <<  "This book is already taken:(\n";
                                    cout << "================================\n";
                                    goto Start;
                                }
                            }
                        }   
                    }
                    if (existing_book == false) 
                    {
                        cout << "This book doesn`t exist\n";
                        cout << "================================\n";
                        goto Start;
                    }
                }
                break;
                
                case 2:
                {
                    cout << "Choose a book you want to return:\n 1 - Atomic Habits\n 2 - Meditations\n 3 - Lord of the Flies\n 4 - The Stranger\n 0 - Go to the main menu\n";
                    cout << "================================\n";
                    int option;
                    cin >> option;
                    if (option == 0) goto Start;
                    else if (option > 0 && option < 5)
                    {
                        if (available[option - 1] == false) 
                        {
                            available[option - 1] = true;
                            cout << "Thanks for returning the book!\n";
                            cout << "================================\n";
                        }
                        else
                        {
                            cout << "This book wasn't taken\n";
                            cout << "================================\n";
                            goto Start;
                        }
                    }
                    else
                    {
                        cout << "Invalid input\n";
                        cout << "================================\n";
                        goto Start;
                    }
                }
                break;

                case 3:
                {
                    cout << "Here are the books:\n ";
                    for (int i = 0; i < 4; i++) cout << books[i] << endl;
                    cout << "================================\n";
                }    
                break;

                case 4: 
                {
                    cout << "Are you sure you want to leave us?\n y - yes, n - no\n";
                    char yn;
                    cin >> yn;
                    if (yn == 'y') return 0;
                    else if (yn == 'n') goto Start;
                    else cout << "Invalid input\n";
                }
                break;    
            }
        do
        {
            cout << "Do you want to continue?\ny - yes, n - no\n";
            cin >> cont;
            if (cont == 'n') resume = false;
        } while (cont != 'y' && cont != 'n');   
    }
    return 0;
}