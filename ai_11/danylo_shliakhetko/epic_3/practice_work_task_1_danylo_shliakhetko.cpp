#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
     vector<string> books = {"Kobzar", "The Lord of the Rings", "1984", "The Da Vinci Code"};
     vector<bool> booksAvailibility = {true, true, true, true};

     bool isExit = false;
     int action;
     int currentBook;

     do
     {
     Menu:
          cout << "- - - - Menu - - - -"
               << "\n";
          cout << "Actions: "
               << "\n";
          cout << "1 - Show books"
               << "\n";
          cout << "2 - Take a book"
               << "\n";
          cout << "3 - Return a book"
               << "\n";
          cout << "4 - Exit"
               << "\n";
          cout << "Enter your action: "
               << "\n";

          cin >> action;
          cout << "- - - - - - - - - -"
               << "\n";

          switch (action)
          {
          case 1:
               for (int i = 0; i < books.size(); i++)
               {
                    cout << i + 1 << " - \"" << books[i] << "\" - book is " << (booksAvailibility[i] ? "available" : "unavailable") << "\n";
               }
               break;

          case 2:
               cout << "Enter number of the book: ";
               cin >> currentBook;
               currentBook--;
               if (0 > currentBook && currentBook <= books.size())
               {
                    cout << "You entered invalid number"
                         << "\n";
               }
               else if (booksAvailibility[currentBook] == true)
               {
                    cout << "You have taken a book"
                         << "\n";
                    booksAvailibility[currentBook] = false;
                    goto ContinueMenu;
               }
               else if (booksAvailibility[currentBook] == false)
               {
                    cout << "It is already taken"
                         << "\n";
                    goto ContinueMenu;
               }
               goto Menu;
               break;

          case 3:
               cout << "Enter number of the book: ";
               cin >> currentBook;
               currentBook--;
               if (0 > currentBook && currentBook <= books.size())
               {
                    cout << "You entered invalid number"
                         << "\n";
               }
               if (booksAvailibility[currentBook] == false)
               {
                    cout << "You returned the book"
                         << "\n";
                    booksAvailibility[currentBook] = true;
                    goto ContinueMenu;
               }
               else if (booksAvailibility[currentBook] == true)
               {
                    cout << "The book is already here"
                         << "\n";
                    goto ContinueMenu;
               }

               goto Menu;
               break;

          case 4:
               isExit = true;
               break;

          default:
               cout << "You entered invalid number"
                    << "\n";
               break;
          }
          cout << "- - - - - - - - - -"
               << "\n";

     ContinueMenu:
          int isContinue;
          cout << "Continue? "
               << "\n";
          cout << "1 - Yes "
               << "\n";
          cout << "2 - No "
               << "\n";

          cin >> isContinue;

          switch (isContinue)
          {
          case 1:
               isExit = false;
               break;
          case 2:
               isExit = true;
               break;
          default:
               goto ContinueMenu;
               break;
          }
     } while (!isExit);

     cout << "See you later!"
          << "\n";

     return 0;
}