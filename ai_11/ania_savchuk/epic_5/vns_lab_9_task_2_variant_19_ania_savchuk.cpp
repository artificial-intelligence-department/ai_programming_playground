#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void write(string name, string content){
    ofstream file(name, ios::out);
    if(!file.is_open()){
        cout << "Cannot open this file" << endl;
    }
    file << content;
    file.close();
}

void copy_file(string file_from, string file_to){
    ifstream ff(file_from, ios::in | ios::binary); // файл-джерело (читання)
    if(!ff.is_open()){
        cout << "Cannot open source file!" << endl;
    }

    ofstream ft(file_to, ios::out | ios::binary); //файл-призначення (запис)
    if(!ft.is_open()){
        cout << "Cannot open this file";
    }

    string first_word;
    if (!(ff >> first_word)) {
        cout << "Error: Input file is empty." << endl;
    }else {
        // Конвертуємо слово до нижнього регістру
        for(int i = 0; i < first_word.length(); i++) {
            first_word[i] = tolower(first_word[i]);
        }
    }
    ff.ignore(1024, '.');
    string line;
    while (getline(ff, line, '.')) {
        string result = line;
        stringstream ss(line);
        vector<string> words;

        // Розділити рядок на слова
        while (ss >> line) {
            // Конвертуємо всі слова до нижнього регістру
            for(int i = 0; i < line.length(); i++) {
                line[i] = tolower(line[i]);
            }
            words.push_back(line);
        }
        // Перевірити, чи жодне слово не збігається з першим
        if (find(words.begin(), words.end(), first_word) == words.end()) {
            ft << result << '.' ;
        }
    }
    ff.close();
    ft.close();

}

int main(){
    string name;
    string content;

    cout << "Enter fillename: ";
    cin >> name;
    cout << "Enter content: ";
    cin.ignore();
    getline(cin, content);
    write (name, content);
    cout << "Content saved successfully" << endl;

    string file_to_copy;
    cout << "Enter name copy file: ";
    getline(cin, file_to_copy);
    copy_file(name, file_to_copy);
    cout << "Lines without the first word copied to "<< file_to_copy << endl;
    
    ifstream ft(file_to_copy);
    string first_line;
    getline(ft, first_line);
    
    int counter = 0;
    string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    
   for (size_t i = 0; i < first_line.length() && first_line[i] != '.'; i++){
        char c = first_line[i];
        if( consonants.find(c) != string::npos){
            counter++;
        }else if(consonants.find(c) == '.'){
            break;
        }
    } 

    cout << "Number of consonants in the first line: " << counter;

    ft.close();
    return 0;
 }

