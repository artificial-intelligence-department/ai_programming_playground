#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    // Менеджмент бібліотеки
    bool finishAct = true;
    while(finishAct) {
        // Перерахувати всі книги
        listBooksPoint:
        bool isListBooks = true;
        vector<string> books = {"book_1", "book_2", "book_3", "book_4", "book_5"};
        do {
        cout << "\n List all books: " << endl;
        for (int i = 0; i < books.size(); i++){
            cout << books[i] << "; ";
        }
        changeChoicePoint:
        cout << "\n Would do you like to change your choice? (yes, no)" << endl;
        string FirstQuestion;
        cin >> FirstQuestion;
        if (FirstQuestion == "yes") {
            goto listBooksPoint;
        } else if (FirstQuestion == "no") {
            isListBooks = false;
        } else {
            cout << "Sorry?" << endl;
            goto changeChoicePoint;
        }
        } while (isListBooks);
        // Дозволити взяти книгу (за наявності)
        vector<string> chosenBook;
        takeBookPoint:
        bool isTakeBook = true;
        do {
        cout << "What book would do you like to take?" << endl;
        string name;
        cin >> name;
        for (string allBooks : books) {
            if (name == allBooks) {
                cout << "Taken books: " << endl;
                chosenBook.push_back(name);
                for (int i = 0; i < chosenBook.size(); i++) {
                    cout << chosenBook[i] << "; ";
                }
                if ( name == books[0] ) {
                    books.erase( books.begin() );
                } else if ( name == books[1] ) {
                    books.erase( books.begin() + 1);
                } else if ( name == books[2] ) {
                    books.erase( books.begin() + 2);
                } else if ( name == books[3] ) {
                    books.erase( books.begin() + 3);
                } else if ( name == books[4] ) {
                    books.erase( books.begin() + 4);
                }
                cout << "\n Remaining book" << endl;
                for (int i = 0; i < books.size(); i++) {
                    cout << books[i] << "; ";
                }
                break;
            } else {
                cout << "Sorry but we don't have such a book" << endl;
            }
        }
        cout << "\n Would do you like to change your choice? (yes, no)" << endl;
        string SecondQuestion;
        cin >> SecondQuestion;
        if (SecondQuestion == "yes") {
            goto listBooksPoint;
        } else if (SecondQuestion == "no") {
            isTakeBook = false;
        } else {
            cout << "Sorry?" << endl;
            goto takeBookPoint;
        }
        } while (isTakeBook);

        // Дозволити повернення книги
        returnBookPoint:
        bool isReturnBook = true;
        do {
        cout << "What book would do you like to turn?" << endl;
        string returnedBook;
        cin >> returnedBook;
        if ( returnedBook == chosenBook[0] ) {
            books.push_back(returnedBook);
            chosenBook.erase( chosenBook.begin() );
        } else if ( returnedBook == chosenBook[1] ) {
            books.push_back(returnedBook);
            chosenBook.erase( chosenBook.begin() + 1);
        } else if ( returnedBook == chosenBook[2] ) {
            books.push_back(returnedBook);
            chosenBook.erase( chosenBook.begin() + 2);
        } else if ( returnedBook == chosenBook[3] ) {
            books.push_back(returnedBook);
            chosenBook.erase( chosenBook.begin() + 3);
        } else if ( returnedBook == chosenBook[4] ) {
            books.push_back(returnedBook);
            chosenBook.erase( chosenBook.begin() + 4);
        }
        cout << "Taken books: " << endl;
        for (int i = 0; i < chosenBook.size(); i++) {
            cout << chosenBook[i] << "; ";
        }
        cout << "\n All books: " << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << books[i] << "; ";
        }
        cout << "\n Would do you like to change your choice? (yes, no)" << endl;
        string ThirdQuestion;
        cin >> ThirdQuestion;
        if (ThirdQuestion == "yes") {
            goto takeBookPoint;
        } else if (ThirdQuestion == "no") {
            isReturnBook = false;
        } else {
            cout << "Sorry?" << endl;
            goto returnBookPoint;
        }
        } while (isReturnBook);
        // Чи залишатись у бібліотеці чи ні
        ComeBackPoint:
        cout << "Would do you like to stay? (yes, no)" << endl;
        string answer;
        cin >> answer;
        if (answer == "yes") {
            goto returnBookPoint;
        } else if (answer == "no") {
            finishAct = false;
        } else {
            cout << "Sorry?" << endl;
            goto ComeBackPoint;
        }
    } 
}