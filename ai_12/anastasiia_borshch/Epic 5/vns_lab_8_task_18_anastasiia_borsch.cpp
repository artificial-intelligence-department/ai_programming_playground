#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Book {
    string name;
    string author;
    int year;
    int pages;
};

void fillFile(const vector<Book>& books, const string& fileName);
void deleteBooks(vector<Book>& books, const string& fileName);
bool addBook(const string& fileName);
void printFile(const string& fileName);

int main() {
    vector<Book> books = {
        {"1984", "Orwell", 1948, 312},
        {"The Great Gatsby", "Fitzgerald", 1925, 578},
        {"War and Peace", "Leo Tolstoy", 1899, 416},
        {"Pride and Prejudice", "Jane Austen", 1813, 238},
        {"The Iliad", "Homer",1598, 160}
    };

    const string fileName = "file1.txt";

    fillFile(books, fileName);
    printFile(fileName);

    deleteBooks(books, fileName);
    if (!addBook(fileName)) return 1;
    printFile(fileName);
    return 0;
}
void fillFile(const vector<Book>& books, const string& fileName) {
    ofstream fout(fileName);
    if (!fout) {
        cerr << "Error occurred while opening the file" << endl;
        return;
    }
    for (const Book& b : books) {
        fout << b.name << "\t" << b.author << "\t" << b.year << "\t" << b.pages << endl;
    }

    fout.close();
}
void deleteBooks(vector<Book>& books, const string& fileName) {
    if (books.size() >= 3) {
        books.erase(books.begin(), books.begin() + 3);
    }

    ofstream fout("temp.bin");
    if (!fout) {
        cerr << "Error occurred while deleting first 3 books" << endl;
        return;
    }

    for (const Book& b : books) {
        fout << b.name << "\t" << b.author << "\t" << b.year << "\t" << b.pages << endl;
    }

    fout.close();
    remove(fileName.c_str());
    rename("temp.bin", fileName.c_str());
}

bool addBook(const string& fileName) {
    Book newbook;
    cout << "Enter the information about a book you want to add:\n";
    cout << "Title: ";
    cin.ignore();
    getline(cin, newbook.name);

    cout << "Author: ";
    getline(cin, newbook.author);

    cout << "Year: ";
    cin >> newbook.year;

    cout << "Pages: ";
    cin >> newbook.pages;

    string beforeBook;
    cout << "Before which book do you want to insert new one?\n";
    cin.ignore(); 
    getline(cin, beforeBook);

    ifstream fin1(fileName);
    if (!fin1) {
        cerr << "Error occurred while reading data from the file" << endl;
        return false;
    }

    ofstream fout2("temp.bin");
    if (!fout2) {
        cerr << "Error occurred while writing data into the file" << endl;
        return false;
    }

    string line;
    bool found = false;

    while (getline(fin1, line)) {
        istringstream iss(line);
        string w;
        iss >> w;
        if (w == beforeBook) {
            fout2 << newbook.name << "\t" << newbook.author << "\t" << newbook.year << "\t" << newbook.pages << endl;
            found = true;
        }
        fout2 << line << endl;
    }

    if (!found) {
        cerr << "This book doesn't exist." << endl;
        return false;
    }

    fin1.close();
    fout2.close();

    remove(fileName.c_str());
    rename("temp.bin", fileName.c_str());
    return true;
}


void printFile(const string& fileName) {
    ifstream fin(fileName);
    if (!fin) {
        cerr << "Error occurred while printing the file's content" << endl;
        return;
    }

    string str;
    while (getline(fin, str)) {
        cout << str << endl;
    }

    fin.close();
}







  


