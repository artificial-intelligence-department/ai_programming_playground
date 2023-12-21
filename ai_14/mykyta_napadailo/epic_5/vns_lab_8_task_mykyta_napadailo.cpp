#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Book {
    char name[30];
    char author[30];
    int year;
    int pages;
};
void FillFile(vector<Book> books, string FileName);
void DeleteThreeBooks(vector<Book> &books, const char* FileName);
bool AddBook(const char* FileName);
void PrintFile(const char* FileName);

int main()
{
   vector<Book> books = {
        {"1984\t", "Orwell\t", 1948, 312},
        {"Meditations", "Marcus Aurelius", 175, 180},
        {"Faust\t", "Goethe\t", 1808, 416},
        {"Hamlet\t", "Shakespear", 1600, 238},
        {"Metamorphosis", "Kafka\t", 1915, 160}};

    FillFile(books, "file1.bin");
    PrintFile("file1.bin");
    DeleteThreeBooks(books, "file1.bin");
    if (!AddBook("file1.bin")) return 1;
    PrintFile("file1.bin");

    return 0;
}


void FillFile(vector<Book> books, string FileName)
{
    ofstream fout(FileName);
    if (!fout)
    {
        cerr << "An error occurred while opening/creating the file" << endl;
        return;
    }
    for (const Book b : books)
    {
        fout << b.name << "\t" << b.author << "\t" << b.year << "\t" << b.pages << endl;
    }
    fout.close();
}

void DeleteThreeBooks(vector<Book> &books, const char* FileName)
{
    if (books.size() >= 3)
    {
        books.erase(books.begin(), books.begin() + 3);
    }
    ofstream fout("temp.bin");
    if (!fout)
    {
        cerr << "An error occurred while deleting first 3 books" << endl;
        return;
    }
    for (const Book b : books)
    {
        fout << b.name << "\t" << b.author << "\t" << b.year << "\t" << b.pages << endl;
    }
    fout.close();
    remove(FileName);
    rename("temp.bin", FileName);
}

bool AddBook(const char* FileName)
{
    Book newbook;
    cout << "Enter the information about a book you want to add:\n";
    cout << "Title: ";
    cin >> newbook.name;
    cout << "Author: ";
    cin >> newbook.author;
    cout << "Year: ";
    cin >> newbook.year;
    cout << "Pages: ";
    cin >> newbook.pages;

    string beforeBook;
    cout << "Before which book do you want to insert a new one?\n";
    cin >> beforeBook;

    ifstream fin1(FileName);
    if (!fin1)
    {
        cerr << "An error occurred while reading data from the file" << endl;
        return false;
    }
    ofstream fout2("temp.bin");
    if (!fout2)
    {
        cerr << "An error occurred while writing data into the file" << endl;
        return false;
    }
    string line;
    bool found = false;
    while (getline(fin1, line))
    {
        istringstream iss(line);
        string w;
        iss >> w;
        if (w == beforeBook)
        {
            fout2 << newbook.name << "\t" << newbook.author << "\t" << newbook.year << "\t" << newbook.pages << endl;
            found = true;
        }
        fout2 << line << endl;
    }
    if (!found)
    {
        cerr << "This book doesn't exist." << endl;
        return false;
    }
    fin1.close();
    fout2.close();

    remove(FileName);
    rename("temp.bin", FileName);
    return true;
}

void PrintFile(const char* FileName)
{
    ifstream fin(FileName);
    if (!fin)
    {
        cerr << "An error occurred while printing the file's content" << endl;
        return;
    }
    string str;
    while (getline(fin, str))
    {
        cout << str << endl;
    }
    fin.close();
}