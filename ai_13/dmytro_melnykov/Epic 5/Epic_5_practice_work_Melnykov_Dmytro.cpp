#include <iostream> 
#include <fstream> 
#include <string> 
 
using namespace std; 
 
enum class fileresult { Success, Failure }; // клас для встановлення саксес або фейл
 
fileresult text_to_file(const string& name, const string& content) { //функція для вмісту 
    if (name.empty() || content.empty()) { 
        return fileresult::Failure; 
    } 
 
    ofstream file(name, ios::out); //якщо файл не відкр то помилка
    if (!file.is_open()) { 
        return fileresult::Failure; 
    } 
 
    file << content; //виводить зміст у файл
 
    return fileresult::Success; 
} 
 
int main() { 
    string filename = "classpractice.txt"; 
    string content; 
 
    cout << "Enter content to write to the file: "; 
    getline(cin, content); 
 
    fileresult result = text_to_file(filename, content); 
 
    if (result == fileresult::Success) { 
        cout << "Write to file successful." << endl; 
    } else { 
        cout << "Failed to perform file operation." << endl; 
    } 
 
    return 0; 
}