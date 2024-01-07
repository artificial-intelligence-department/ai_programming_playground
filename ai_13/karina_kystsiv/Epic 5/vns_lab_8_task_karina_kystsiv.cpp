#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct Book {
    char title[50];
    char author[30];
    int year;
    int pages;
};

void writeBookToBinaryFile(const string& filePath, const Book books[], int numBooks) {
    ofstream file(filePath, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(books), sizeof(Book) * numBooks);
    file.close();
    cout << "File successfully created." << endl;
}

void readBinaryFile(const string& filePath) {
    ifstream file(filePath, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    Book book;
    while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        cout << "Title: " << book.title << ", Author: " << book.author
             << ", Year: " << book.year << ", Pages: " << book.pages << endl;
    }

    file.close();
}

void deleteBooks(const string& filePath, int numBooksToDelete) {
    fstream file(filePath, ios::binary | ios::in | ios::out);
    if (!file.is_open()) {
        cerr << "Error opening file for deletion." << endl;
        return;
    }

    file.seekp(0, ios::end);
    streampos fileSize = file.tellp();
    file.seekp(0);

    Book* books = new Book[fileSize / sizeof(Book)];
    int numBooks = fileSize / sizeof(Book);

    file.read(reinterpret_cast<char*>(books), fileSize);

    if (numBooksToDelete >= numBooks) {
        cerr << "Cannot delete more books than available." << endl;
        delete[] books;
        file.close();
        return;
    }

    Book* remainingBooks = new Book[numBooks - numBooksToDelete];

    for (int i = numBooksToDelete; i < numBooks; ++i) {
        remainingBooks[i - numBooksToDelete] = books[i];
    }

    file.seekp(0);
    file.write(reinterpret_cast<const char*>(remainingBooks), sizeof(Book) * (numBooks - numBooksToDelete));

    file.close();
    file.open(filePath, ios::binary | ios::in | ios::out | ios::trunc);
    file.write(reinterpret_cast<const char*>(remainingBooks), sizeof(Book) * (numBooks - numBooksToDelete));

    delete[] books;
    delete[] remainingBooks;
    file.close();
    cout << numBooksToDelete << " elements deleted." << endl;
}

void addBookBeforeTitle(const string& filePath, const Book& newBook, const string& targetTitle) {
    ifstream file(filePath, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    Book book;
    ofstream tempFile("temp.dat", ios::binary);

    // Read and copy books to the temporary file until the target title is found
    while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (strcmp(book.title, targetTitle.c_str()) == 0) {
            tempFile.write(reinterpret_cast<const char*>(&newBook), sizeof(Book));
        }
        tempFile.write(reinterpret_cast<const char*>(&book), sizeof(Book));
    }

    file.close();
    tempFile.close();

    remove(filePath.c_str());
    rename("temp.dat", filePath.c_str());

    cout << "Book added before title: " << targetTitle << endl;
}

int main() {
    Book books[] = {
        {"Harry Potter", "J. K. Rowling", 1997, 400},
        {"A Song of Ice and Fire", "George Martin", 1996, 850},
        {"Little Prince", "Antoine de Saint-Exupery", 2020, 500},
        {"Murder on the Orient Express", "Agatha Christie", 1995, 250}
    };

    const string filePath = "books.dat";

    writeBookToBinaryFile(filePath, books, sizeof(books) / sizeof(Book));
    cout << "\nOriginal file content:\n";
    readBinaryFile(filePath);

    // Add a new book before the book with the specified title
    Book newBook = {"New Title", "New Author", 2023, 300};
    addBookBeforeTitle(filePath, newBook, "Little Prince");


    cout << "\nFile content after addition:\n";
    readBinaryFile(filePath);

   deleteBooks(filePath, 3);

   cout << "\nFile content after deletion:\n";
    readBinaryFile(filePath);

    return 0;
}