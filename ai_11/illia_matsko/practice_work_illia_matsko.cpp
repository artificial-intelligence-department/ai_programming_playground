#include <iostream>
using namespace std;

#define GREEN   "\033[1m\033[32m"
#define RED     "\033[1m\033[31m"
#define RESET   "\033[0m"

struct book
{
    string name;
    int quantity;
    string status;
};

int find(vector<book>& library, string bookName)
{
    for(int i=0; i<library.size(); i++)
    {
        if(library[i].name == bookName)
        {
            return i;
        }
    }

    return -1;
}

void takeBook(vector<book>& library, string bookName, int& owe)
{
    int found = find(library, bookName);
    book bookToTake;

    if(found != -1)
    {
        bookToTake = library[found];
        if(bookToTake.status == "available")
        {
            owe++;
            bookToTake.quantity--;
            bookToTake.status = "taken";
            library[found] = bookToTake;

            cout << "Take your book! Enjoy reading!";
            return;
        } else {
            cout << "You've already taken this book!";
            return;
        }
    } else {
        cout << RED << "There is no book with this name :(" << RESET;
    }
}

void addBook(vector<book>& library, string bookName, int& owe)
{
    int found = find(library, bookName);
    book bookToAdd;

    if(found != -1)
    {
        bookToAdd = library[found];
        bookToAdd.quantity++;

        if(bookToAdd.status == "taken")
        {
            owe--;
            bookToAdd.status = "available";
            library[found] = bookToAdd;

            cout << GREEN << "Thanks for returning book!" << RESET;
            return;
        } else {
            library[found] = bookToAdd;

            cout << "Thanks for bringing '" << bookName << "' in the library!";
            return;
        }
    }

    bookToAdd.name = bookName;
    bookToAdd.quantity = 1;
    bookToAdd.status = "";
    library.push_back(bookToAdd);
    cout << "Thanks for bringing '" << bookName << "' in the library!";
}

void printMenu()
{
cout << "================================================ \n"
        "What do you want to do? \n"
        "1 - Take book \n"
        "2 - Add/return book \n"
        "3 - Book catalog \n"
        "4 - Borrowed books \n";
}

void printOwed(vector<book>& library, int owe)
{
    if(owe == 0)
    {
        cout << "You don't owe any books :)";
        return;
    }

    cout << "You owe: " << endl;
    for(book book : library)
    {
        if(book.status == "taken")
        {
            if(owe == 1)
            {
                cout << "'" << book.name << "';";
                return;
            } else {
                cout << "'" << book.name << "', ";
                owe--;
            }
        }
    }
}

void printLibrary(vector<book>& library, int books)
{
    if(library.empty() || books == 0)
    {
        cout << "The library is empty :(";
        return;
    }

    int amount = 0, counter = 1;

    cout << "Library:" << endl;
    for(book book : library)
    {
        if(book.quantity > 0)
        {
            amount += book.quantity;
            cout << counter << ". '" <<  book.name << "' - " << book.quantity << endl;
            counter++;
        }
    }
    cout << "=== There " << (amount == 1 ? "is " : "are ")  << GREEN << amount << RESET << (amount == 1 ? " book" : " books") <<  " in the library ===";
}

int main()
{
    vector<book> library = {
            {"Harry Potter",          7,      "available"},
            {"The Hobbit",            2,      "available"},
            {"Pride and Prejudice",   4,      "available"},
            {"1984",                  1,      "available"},
            {"The Alchemist",         3,      "available"},
            {"The Lord of the Rings", 5,      "available"},
            {"The Great Gatsby",      9,      "available"},
            {"The Da Vinci Code",     1,      "available"},
    };

    string choice, name;
    int owe = 0, books = library.size();

    while(true)
    {
        start:
        printMenu();
        cout << GREEN << "Your choice: " << RESET;
        cin >> choice;

        if(choice == "1")
        {
            cout << "Type name of the book: ";
            cin.ignore();
            getline(cin, name);
            takeBook(library, name, owe);
            books--;
        } else if(choice == "2")
        {
            cout << "Type name of the book: ";
            cin.ignore();
            getline(cin, name);
            addBook(library, name, owe);
            books++;
        } else if(choice == "3")
        {
            printLibrary(library, books);
        } else if(choice == "4")
        {
            printOwed(library, owe);
        } else {
            cout << RED << "Error: Choose one of the proposed options!" << RESET << endl;
            goto start;
        }

        cout << endl << "Do you want to continue?(" << GREEN << "Y" << RESET << "/" << RED << "N" << RESET << ")" << endl;
        cin >> choice;

        if(choice == "N") break;
    }

    cout << "Bye, have a nice day!!!";
    return 0;
}














//#include <iostream>
//using namespace std;
//
//struct book
//{
//    bool presance;
//    string name;
//};
//
//int find(vector<book>& library, string bookName)
//{
//    book book;
//
//    for(int i=0; i<library.size(); i++)
//    {
//        book = library[i];
//        if(book.name == bookName)
//        {
//            return i;
//        }
//    }
//
//    return -1;
//}
//
//void takeBook(vector<book>& library, string bookName)
//{
//    int found = find(library, bookName);
//    book bookToTake, presCheck;
//
//    if(found != -1)
//    {
//        presCheck = library[found];
//        if(presCheck.presance)
//        {
//            bookToTake.presance = false;
//            bookToTake.name = bookName;
//            library[found] = bookToTake;
//            cout << "You can take your book!";
//            return;
//        }
//    }
//
//    cout << "There is no book with this name(((";
//}
//
//void addBook(vector<book>& library, string bookName)
//{
//    int found = find(library, bookName);
//    book bookToAdd, presCheck;
//
//    if(found != -1)
//    {
//        presCheck = library[found];
//        if(!presCheck.presance)
//        {
//            bookToAdd.presance = true;
//            bookToAdd.name = bookName;
//            library[found] = bookToAdd;
//            cout << "Thanks for returning book!";
//            return;
//        }
//    }
//
//    bookToAdd.name = bookName;
//    bookToAdd.presance = true;
//    library.push_back(bookToAdd);
//    cout << "Thanks for bringing '" << bookName << "' in the library!";
//}
//
//void printMenu()
//{
//    cout << "==============================" << endl;
//    cout << "What do you want to do?" << endl;
//    cout << "1 - Take book" << endl;
//    cout << "2 - Add/return book" << endl;
//    cout << "3 - Check books in the library" << endl;
//    cout << "4 - Leave" << endl;
//}
//
//void printLibrary(vector<book>& library)
//{
//    int count = 0;
//
//    for(int i=0; i<library.size(); i++)
//    {
//        book book = library[i];
//        if(book.presance)
//        {
//            cout << book.name << endl;
//            count++;
//        }
//    }
//    cout << "=== There are " <<  count << " books in the library ===";
//}
//
//int main()
//{
//    vector<book> library = {
//            {true, "Harry Potter"},
//            {true, "The Hobbit"},
//            {true, "Pride and Prejudice"},
//            {true, "1984"},
//            {true, "The Alchemist"},
//            {true, "The Lord of the Rings"},
//            {true, "The Great Gatsby"},
//            {true, "The Da Vinci Code"},
//    };
//
//    string choice, name;
//
//    while(true)
//    {
//        start:
//        printMenu();
//        cin >> choice;
//
//        if(choice == "1")
//        {
//            cout << "Type name of the book: ";
//            cin.ignore();
//            getline(cin, name);
//            takeBook(library, name);
//        } else if(choice == "2")
//        {
//            cout << "Type name of the book: ";
//            cin.ignore();
//            getline(cin, name);
//            addBook(library, name);
//        } else if(choice == "3")
//        {
//            printLibrary(library);
//        } else if(choice == "4")
//        {
//            break;
//        } else {
//            cout << "Error: Type one of the proposed answers!" << endl;
//            goto start;
//        }
//
//
//        cout << endl << "Do you want to continue?(Y/N)" << endl;
//        cin >> choice;
//        if(choice == "N")
//        {
//            break;
//        } else {
//            goto start;
//        }
//    }
//
//    cout << "Have a nice day!!!";
//    return 0;
//}





//#define RESET   "\033[0m"
//#define BLACK   "\033[30m"      /* Black */
//#define RED     "\033[31m"      /* Red */
//#define GREEN   "\033[32m"      /* Green */
//#define YELLOW  "\033[33m"      /* Yellow */
//#define BLUE    "\033[34m"      /* Blue */
//#define MAGENTA "\033[35m"      /* Magenta */
//#define CYAN    "\033[36m"      /* Cyan */
//#define WHITE   "\033[37m"      /* White */
//#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
//#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
//#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
//#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
//#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
//#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
//#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
//#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */




//#include <iostream>
//using namespace std;
//
//#define GREEN   "\033[1m\033[32m"
//#define RED     "\033[1m\033[31m"
//#define RESET   "\033[0m"
//
//struct book
//{
//    string name;
//    int quantity;
//    bool presence;
//    string status;
//};
//
//int find(vector<book>& library, string bookName)
//{
//    for(int i=0; i<library.size(); i++)
//    {
//        if(library[i].name == bookName)
//        {
//            return i;
//        }
//    }
//
//    return -1;
//}
//
//void takeBook(vector<book>& library, string bookName, int& owe)
//{
//    int found = find(library, bookName);
//    book bookToTake;
//
//    if(found != -1)
//    {
//        bookToTake = library[found];
//        if(bookToTake.status == "available")
//        {
//            owe++;
//            if(--bookToTake.quantity == 0)
//            {
//                bookToTake.presence = false;
//            }
//            bookToTake.status = "taken";
//            library[found] = bookToTake;
//
//            cout << "Take your book! Enjoy reading!";
//            return;
//        } else {
//            cout << "You've already taken this book!";
//            return;
//        }
//    } else {
//        cout << RED << "There is no book with this name :(" << RESET;
//    }
//}
//
//void addBook(vector<book>& library, string bookName, int& owe)
//{
//    int found = find(library, bookName);
//    book bookToAdd;
//
//    if(found != -1)
//    {
//        bookToAdd = library[found];
//        bookToAdd.quantity++;
//        bookToAdd.presence = true;
//
//        if(bookToAdd.status == "taken")
//        {
//            owe--;
//            bookToAdd.status = "available";
//            library[found] = bookToAdd;
//
//            cout << GREEN << "Thanks for returning book!" << RESET;
//            return;
//        } else {
//            library[found] = bookToAdd;
//
//            cout << "Thanks for bringing '" << bookName << "' in the library!";
//            return;
//        }
//    }
//
//    bookToAdd.name = bookName;
//    bookToAdd.quantity = 1;
//    bookToAdd.presence = true;
//    bookToAdd.status = "";
//    library.push_back(bookToAdd);
//    cout << "Thanks for bringing '" << bookName << "' in the library!";
//}
//
//void printMenu()
//{
//    cout << "================================================ \n"
//            "What do you want to do? \n"
//            "1 - Take book \n"
//            "2 - Add/return book \n"
//            "3 - Book catalog \n"
//            "4 - Borrowed books \n";
//}
//
//void printOwed(vector<book>& library, int owe)
//{
//    if(owe == 0)
//    {
//        cout << "You don't owe any books :)";
//        return;
//    }
//
//    cout << "You owe: " << endl;
//    for(book book : library)
//    {
//        if(book.status == "taken")
//        {
//            if(owe == 1)
//            {
//                cout << "'" << book.name << "';";
//                return;
//            } else {
//                cout << "'" << book.name << "', ";
//                owe--;
//            }
//        }
//    }
//}
//
//void printLibrary(vector<book>& library, int books)
//{
//    if(library.empty() || books == 0)
//    {
//        cout << "The library is empty :(";
//        return;
//    }
//
//    int amount = 0, counter = 1;
//
//    cout << "Library:" << endl;
//    for(book book : library)
//    {
//        if(book.presence)
//        {
//            amount += book.quantity;
//            cout << counter << ". '" <<  book.name << "' - " << book.quantity << endl;
//            counter++;
//        }
//    }
//    cout << "=== There " << (amount == 1 ? "is " : "are ")  << GREEN << amount << RESET << (amount == 1 ? " book" : " books") <<  " in the library ===";
//}
//
//int main()
//{
//    vector<book> library = {
//            {"Harry Potter",          7,    true,    "available"},
//            {"The Hobbit",            2,    true,    "available"},
//            {"Pride and Prejudice",   4,    true,    "available"},
//            {"1984",                  1,    true,    "available"},
//            {"The Alchemist",         3,    true,    "available"},
//            {"The Lord of the Rings", 5,    true,    "available"},
//            {"The Great Gatsby",      9,    true,    "available"},
//            {"The Da Vinci Code",     1,    true,    "available"},
//    };
//
//    string choice, name;
//    int owe = 0, books = library.size();
//
//    while(true)
//    {
//        start:
//        printMenu();
//        cout << GREEN << "Your choice: " << RESET;
//        cin >> choice;
//
//        if(choice == "1")
//        {
//            cout << "Type name of the book: ";
//            cin.ignore();
//            getline(cin, name);
//            takeBook(library, name, owe);
//            books--;
//        } else if(choice == "2")
//        {
//            cout << "Type name of the book: ";
//            cin.ignore();
//            getline(cin, name);
//            addBook(library, name, owe);
//            books++;
//        } else if(choice == "3")
//        {
//            printLibrary(library, books);
//        } else if(choice == "4")
//        {
//            printOwed(library, owe);
//        } else {
//            cout << RED << "Error: Choose one of the proposed options!" << RESET << endl;
//            goto start;
//        }
//
//        cout << endl << "Do you want to continue?(" << GREEN << "Y" << RESET << "/" << RED << "N" << RESET << ")" << endl;
//        cin >> choice;
//
//        if(choice == "N") break;
//    }
//
//    cout << "Bye, have a nice day!!!";
//    return 0;
//}