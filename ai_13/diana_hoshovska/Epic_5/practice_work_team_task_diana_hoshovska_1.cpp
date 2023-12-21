#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpResult { Success, Failure }; //розібрати детальніше про енам
FileOpResult write_to_file(const char *Name, const char *content){
    ofstream file(Name, ios::binary); //відкриваємо для запису у файл

    if (!file.is_open()){ //файл не відкрився
        cerr << "An error has occured, please try again." << endl;
        return Failure;}
    file << content;

    if(file.fail()){ //файл не записався
        cerr << "An error has occured, please try again." << endl; 
        file.close();
        return Failure;
    }

    file.close();
    return Success;
}

int main(){
    string file = "my_file", content;
    cout << "Enter data to write in file: ";
    getline(cin, content);
    FileOpResult res = write_to_file(file.c_str(), content.c_str()); //розвідати, шо таке c_str

    if (res == Success){
        cout << "\nAn operation is proceed successfully";
    }
    else{
        cout << "\nSomething went wrong, please try again.";
    }
    return 0;
}