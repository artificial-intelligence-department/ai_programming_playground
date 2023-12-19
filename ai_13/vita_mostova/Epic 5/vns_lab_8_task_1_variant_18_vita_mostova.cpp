#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
struct Book{
    string title;
    string author;
    int year;
    int pages;

};
void write_to_file(const string& file,const Book& yourBook);
void print_file(const string& file);
bool insert_book_before(const string& file,const Book& newBook, const string& beforeBook);
void remove_first_three_lines(const string& file);
int main(){

    Book book1={"Harry Potter ","Joanne Rowling ",1997,319};
    Book book2={"Pride and Prejudice ","Jane Austen ",1813,432};
   Book book3= {"The Hobbit ","Tolkien ",1937,310};
    Book book4={"1984 ","George Orwell ",1949,328};
    Book book5={"The great Gatsby  ","Scott Fitzgerald ",1997,319};
     ofstream createFile("File.dat");

    if (createFile.is_open()) {
        std::cout << "Empty file 'File.dat' created successfully.\n";
        createFile.close();
    } else {
        cerr << "Error creating the file 'File.dat'.\n";
    }

write_to_file("File.dat",book1);
print_file("File.dat");
write_to_file("File.dat",book2);
write_to_file("File.dat",book3);
write_to_file("File.dat",book4);
write_to_file("File.dat",book5);
print_file("File.dat");
remove_first_three_lines("File.dat");
print_file("File.dat");
Book book6={"Princess Diary   ","Meg Cabot  ",2000,200};
   insert_book_before("File.dat",book6,book4.title);
   print_file("File.dat");



    return 0;
}
void write_to_file(const string& file, const Book& yourBook){
ofstream myFile(file, ios::app); //файл відкритий в режимі додавання
if(!myFile){
    cout<<"This file could not be opened for writing:(\n";
return;}
myFile<<yourBook.title<<' '<<yourBook.author<<' '<<yourBook.year<<' '<<yourBook.pages<<endl;
cout<<"Writ was successful\n";
myFile.close();}
bool insert_book_before(const string& file, const Book& newBook, const string& beforeBook) {
    ifstream fileToRead(file);
    if (!fileToRead) {
        cout << "This file could not be opened for reading:(" << endl;
        return 0;
    }

    ofstream fileTemporary("temp.dat");
    if (!fileTemporary) {
        cout << "This file could not be opened for writing:(" << endl;
        return 0;
    }

    string line;
    bool found = false;

    while (getline(fileToRead, line)) {
        istringstream iss(line);
        string currentTitle;
        iss >> currentTitle;

        if (currentTitle == beforeBook) {
            fileTemporary << newBook.title << "\t" << newBook.author << "\t" << newBook.year << "\t" << newBook.pages << endl;
            found = true;
        }

        fileTemporary << line << endl;
    }
if (!found) {
        cout << "Book not found in the file." << endl;
        return 0;
    }
    fileToRead.close();
    fileTemporary.close();

    

    remove(file.c_str());
    rename("temp.dat", file.c_str());

    cout << "New book inserted successfully.\n";
    return true;
}


/*void print_file(const string& file){
    ifstream readFile(file); //створюємо обєкт класу мійфайл для зчитування//in автоматично в ifstream
    if(!readFile){
        cout<<"This file can not be opened:(\n";
    return;}
    Book bookHere;
    while(readFile>>bookHere.title>>bookHere.author>>bookHere.year>>bookHere.pages){
        cout<<"Title: "<<bookHere.title<<" Author: "<<bookHere.author<<" Year of publication: "<<bookHere.year<<" Number of pages: "<<bookHere.pages<<"\n";
    }
    readFile.close();
    }*/
    void print_file(const string& file) {
    ifstream readFile(file); // створюємо об'єкт класу мійфайл для зчитування // in автоматично в ifstream
    if (!readFile) {
        cerr << "Error opening the file: " << file << endl;
        return;
    }

    Book bookHere;
    while (readFile >> bookHere.title >> bookHere.author >> bookHere.year >> bookHere.pages) {
        cout << "Title: " << bookHere.title << " Author: " << bookHere.author << " Year of publication: " << bookHere.year << " Number of pages: " << bookHere.pages << "\n";
    }

    if (readFile.eof()) {
        cout << "End of file reached." << endl;
    } else if (readFile.fail()) {
        cerr << "Error reading data from the file: " << file << endl;
    }

    readFile.close();
}




void remove_first_three_lines(const string& file){
        ifstream myFile(file);
        if(!myFile){
            cout<<"This file can not be opened :(\n";
            return;
        }
        vector<Book> elements; //рядки які треба зберегти після видалення

        Book book; // te erase
        for (int i = 0; i < 3 && myFile >> book.title >> book.author >> book.year >> book.pages; ++i) {
        // Пропускаємо перші три рядки
    }

    // Зчитуємо залишок рядків
    while (myFile >> book.title >> book.author >> book.year >> book.pages) {
        elements.push_back(book);
    }

    myFile.close();

    // Перезаписуємо файл з залишком рядків
    ofstream myFileWrite("file.dat"); // фвйл буде очищений перед відкриттям для запису
    if (!myFileWrite) {
        cout << "This file could not be opened for writing:(" << endl;
        return;
    }

    for (const Book& b : elements) {
        myFileWrite << b.title << " "<<b.author<<" "<<b.year<<" "<<b.pages<<"\n";
    }

    myFileWrite.close();
    remove(file.c_str());
    rename("file.dat",file.c_str());

    cout << "First three lines removed successfully." << endl;
}


   