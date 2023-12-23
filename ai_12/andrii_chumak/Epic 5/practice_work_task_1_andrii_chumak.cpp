#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <fstream>

using namespace std;

int main() {
    // DONE!
    // Робота з текстовими файлами
    /* Файл "file_from.txt" має дві цілі:
    1. Внести в цей файл дані
    2. Вивести дані з цього файлу і внести їх в інший файл */
    fstream fs;
    fs.open("file_from.txt", fstream::in | fstream::out | fstream::app);
        string content;
    if( !fs.is_open() ) {
        cout << "Failure \n";
    } else {
        cout << "Success" << endl;
        cout << "Please, enter some information in your file" << endl;
        cin >> content;
        fs << content << endl;
        while ( fs.eof() ) {
            fs >> content;
        }
        fs.close();
    }

    // Файл "file_to.txt" приймає дані з іншого файлу
    ofstream oFile;
    oFile.open("file_to.txt");
    if( !oFile.is_open() ) {
        cout << "Failure \n";
    } else {
        cout << "Success \n";
        oFile << content;
    }
        fs.close();
        
    return 0;
}
