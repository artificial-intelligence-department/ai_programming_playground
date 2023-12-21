#include <iostream>
#include <vector>
#include <string>
using namespace std;
void exit() { exit(0); }
int main()
{
    vector<string> books = {"Harry Potter", "The Shining", "Lord of the rings", "Sherlock Holmes", "1984", "The picture of Dorian Gray", "Kobzar", "The thing"};
    vector<bool> availability = {true, true, true, true, true, true, true, true};
    int number = books.size();
    int action;

linkmenu:

    cout << "L I B R A R Y \n";
    cout << "Choose the action (write only number): \n";
    cout << "1: Show all books \n";
    cout << "2: Take a book \n";
    cout << "3: Give a book back \n";
    cout << "4: quit \n";

    cin >> action;

    if (action == 1)
    {

        for (string word : books)
        {

            cout << word << endl;
        }
        goto yesno;
    }
    else if (action == 2)
    {

        cout << "Choose the book you'd like to borrow: ";
        cin.ignore();

        string bookborrow;
        getline(cin, bookborrow);

        bool available = false;

        for (int i = 0; i < number; ++i)
        {
            if (books[i] == bookborrow && availability[i])
            {

                availability[i] = false;
                books.erase(books.begin() + i);
                availability.erase(availability.begin() + i);
                available = true;
                break;
            }
        }
    }
    else if (action == 3)
    {
        cout << "What book would you like to give back?\n";
        cin.ignore();
        string bookback;
        getline(cin, bookback);

        books.push_back(bookback);
        availability.push_back(true);
        number++;

        cout << "You have returned: " << bookback << endl;
    }
    else if (action == 4)
    {
        cout << "\nGoodbye! \n";

        exit();
    }
    else
    {
        cout << "Wrong input" << endl;
        goto linkmenu;
    }

yesno:
    cout << "\nWould you like to continue? (yes/no) \n";

    string answer;

    cin >> answer;

    if (answer == "yes")
    {

        goto linkmenu;
    }
    else if (answer == "no")
    {

        cout << "\nGoodbye! \n";

        exit();
    }

    else if (answer != "yes" || "no")
    {
        cout << "You have to write yes or no" << endl;
        goto yesno;
    }

    return 0;
}