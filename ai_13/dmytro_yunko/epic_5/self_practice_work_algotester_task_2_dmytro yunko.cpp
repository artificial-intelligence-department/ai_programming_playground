#include <cstdio>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;


struct Book {
    string title;
    bool status;
};
string serialize(const Book& book) {
    stringstream ss;
    ss << book.title << '\n' << book.status;
    return ss.str();
}


Book deserialize(const string& str) {
    stringstream ss(str);
    Book book;
    getline(ss, book.title);
    ss >> book.status;
    return book;
}

void writeEachBookToFile(fstream &file, const vector<Book>& books)
{   
    file.close();
    file.open("books.bin", ios::out | ios::binary | ios::trunc);
    for (const Book &book : books) {
            string str = serialize(book);
        
        size_t len = str.size();
        file.write((char*)&len, sizeof(size_t));
    
        file.write(str.c_str(), len);
        }
    
}



int main() {

    vector<Book> books = {{"Harry Potter", true}, {"The Hobbit", true}, {"Pride and Prejudice", true}, {"1984", true}};
    int selection;
    string titleName;
    char continueSelection;

    
    fstream file;

   
    file.open("books.bin", ios::in | ios::binary);

   
    if (!file.is_open()) {
        
        
        file.open("books.bin", ios::out | ios::binary);
        writeEachBookToFile(file,books);
        file.close();
        file.open("books.bin", ios::in | ios::out | ios::binary);
    }else {
        
        books.clear();
        
        while (file.peek() != EOF ) {
            size_t size;
            file.read((char*)&size, sizeof(size_t));
            
            string str(size, ' ');
            file.read(&str[0], size);
            Book book = deserialize(str);
            books.push_back(book);
        }
    }

    do {
        cout << "Library Management\n";
        cout << "1. List all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Enter your selection: ";
        cin >> selection;

        switch(selection) {
            case 1: 
                for (int i = 0; i < books.size(); i++) {
                    cout << i + 1 << ". " << books[i].title << (books[i].status ? " (Available)" : " (Borrowed)") << "\n";
                }
                break;
            case 2:
                cin.ignore();
                cout << "Enter book name to borrow: ";
                getline(cin, titleName);

                for (const auto &book : books) {
                    if (book.title == titleName) {
                        int index = &book - &books[0];
                        if (books[index].status) {
                            books[index].status = false;
                            cout << "Book borrowed successfully!\n";
                            
                            
                        } else {
                            cout << "Book is already borrowed.\n";
                        }
                        break;
                    }
                }
                break;
            case 3:
                cin.ignore();
                cout << "Enter book name to return: ";
                getline(cin, titleName);

                for (const auto &book : books) {
                    if (book.title == titleName) {
                        int index = &book - &books[0];
                        if (!books[index].status) {
                            books[index].status = true;
                            cout << "Book returned successfully!\n";
                            
                            
                        
                        } else {
                            cout << "Book wasn't borrowed.\n";
                        }
                        break;
                    }
                }
                break;
            case 4:
                writeEachBookToFile(file,books);
                cout << "Goodbye!";
                file.close(); 
                return 0;
            default:
                cout << "Invalid selection.\n";
        }

        do {
            cout << "Do you want to perform another operation? (Y/N): ";
            cin >> continueSelection;
        } while (continueSelection != 'Y' && continueSelection != 'N' && continueSelection != 'y' && continueSelection != 'n');

    } while (continueSelection == 'Y' || continueSelection == 'y');

    cout << "Goodbye!";



    
    
    writeEachBookToFile(file,books);
    file.close(); 
    return 0;
}