#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Book
{
    string name;
    string autor;
    int year;
    int pages;
};

Book RichDadPoorDad = {"RichDadPoorDad", "Avanasiy", 2007, 1312};

void form(Book book)
{
    ofstream f("file.bin", ios_base::binary | ios_base::app);
    if (!f.is_open())
    {
        cout << "Error opening the file." << endl;
    }
    else
    {
        f.write((char*)(&book), sizeof(book));
        f.close();
    }
}

void print()
{
    Book book;
    ifstream f("file.bin", ios_base::binary);
    if (!f.is_open())
    {
        cout << "Error opening the file." << endl;
    }
    else
    {
        while (f.read((char*)(&book), sizeof(book)))
        {
            cout << book.name << ":\n";
            cout << "Autor: " << book.autor << endl;
            cout << "Year: " << book.year << endl;
            cout << "Pages: " << book.pages << endl;
            cout << endl;
        }
        f.close();
    }
}

void del()
{
    ifstream f("file.bin", ios_base::binary);
    if (!f.is_open())
    {
        cout << "Error opening the file." << endl;
        return;
    }

    ofstream tempf("tempf.bin", ios_base::binary | ios_base::app);
    if (!tempf.is_open())
    {
        cout << "Error opening the temporary file." << endl;
        f.close();
        return;
    }

    int n = 1;
    Book book;

    while (f.read((char*)(&book), sizeof(book)) && n < 3)
    {
        n++;
    }

    while (f.read((char*)(&book), sizeof(book)))
    {
        tempf.write((char*)(&book), sizeof(book));
    }

    f.close();
    tempf.close();

    remove("file.bin");
    rename("tempf.bin", "file.bin");
}

void add(string nametoadd)
{
    ifstream f("file.bin", ios_base::binary);
    if (!f.is_open())
    {
        cout << "Error opening the file." << endl;
        return;
    }

    ofstream tempf("tempf.bin", ios_base::binary | ios_base::app);
    if (!tempf.is_open())
    {
        cout << "Error opening the temporary file." << endl;
        f.close();
        return;
    }

    Book book;
    bool bookAdded = false;

    while (f.read((char*)(&book), sizeof(book)))
    {
        if (book.name == nametoadd)
        {
            tempf.write((char*)(&RichDadPoorDad), sizeof(RichDadPoorDad));
            bookAdded = true;
        }

        tempf.write((char*)(&book), sizeof(book));
    }

    f.close();
    tempf.close();

    if (!bookAdded)
    {
        cout << "Book not found for addition." << endl;
    }

    remove("file.bin");
    rename("tempf.bin", "file.bin");
}

int main()
{
    cout << "Forming:\n\n";
    Book Tora = {"Tora", "Damian", 1984, 666};
    Book Meinkampf = {"Meinkampf", "Danichka", 1939, 1488};
    Book It = {"It", "Vasya", 2000, 333};
    Book Bible = {"Bible", "Andriy", 0, 777};
    Book Koran = {"Koran", "Valodya", 1, 5};

    form(Tora);
    form(Meinkampf);
    form(It);
    form(Bible);
    form(Koran);
    print();
    del();
    cout << "After delete:\n\n";
    print();

    string addname;
    cout << "Enter name of book before which you want to add:\n";
    cin >> addname;

    add(addname);

    cout << "After addition:\n\n";
    print();
    remove("file.bin");
    return 0;
}
