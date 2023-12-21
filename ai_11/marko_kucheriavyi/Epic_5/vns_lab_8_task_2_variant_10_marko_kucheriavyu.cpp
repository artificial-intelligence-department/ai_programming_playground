#include <iostream>
#include <fstream>
using namespace std;

struct information{
    string user;
    int size;
    string name;
    string author;
};

void write(string path, information data[3], int size){
    ofstream file;
    file.open(path, ios_base::app);

    for (int i = 0; i < size; i++){
        file << data[i].user << "; ";
        file << data[i].size << "; ";
        file << data[i].name << "; ";
        file << data[i].author << "\n";
    }
    file.close();
}

void read(string path){
    ifstream file;
    file.open(path);
    
    string line;
    while (getline(file, line)){
        cout << line << endl;
    }
    file.close();
}

void deletedata(string path, string lineToDelete){
    ifstream file;
    file.open(path);
    ofstream tempFile("temp.txt");

    string line;
    while (getline(file, line)){
        if (line != lineToDelete){
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    remove(path.c_str());
    rename("temp.txt", path.c_str());
}

void deleteAllData(string path){
    ofstream file(path, ios::trunc);
    cout << "\nFile content delete successfull";
    file.close();
}

int main(){
    information data[3] = {
        {"Marko", 1, "Shining", "Stephen King"},
        {"Andriy", 2, "Harry Potter", "Joahne Roaling"},
        {"Dima", 3, "Lord of the rings", "Tolkin"}
    };
    information dataToAdd[1] = {"Demian", 4, "The Hobbit", "Tolkin"};
    string path = "C:/Users/marko/Desktop/Study/Programming/Epic5/lab8.txt";

    deleteAllData(path);

    write(path, data, 3);
    cout << "After writing:" << endl;
    read(path);
    
    deletedata(path, "Andriy; 2; Harry Potter; Joahne Roaling");
    write(path, dataToAdd, 1);
    cout << "\nAfter changes:" << endl;
    read(path);

    return 0;
}