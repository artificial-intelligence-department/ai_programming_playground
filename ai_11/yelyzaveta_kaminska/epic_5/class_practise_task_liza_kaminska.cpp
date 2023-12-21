#include <iostream> 
#include <fstream> 
#include <string> 
 
using namespace std; 
enum FileOpResult { Success, Failure}; 
FileOpResult write_to_file(char *name, char *content){ 
    ofstream wf(name, ios::out | ios::binary); 
    if(!wf){ 
        cout <<"Cannot open the file."; 
        return Failure; 
    } 
    wf.write((char *) &content, sizeof(FileOpResult)); 
    wf.close(); 
    if(!wf.good()) { 
        cout << "Error occurred at writing time!" << endl; 
        return Failure; 
    } 
    return Success; 
} 
int main(){ 
    char* filename = "example.txt"; 
    char content[256]; 
    cout << "Enter the content to write to the file: "; 
    cin.getline(content,256); 
    FileOpResult result = write_to_file(filename, content); 
 
    if (result == Success) { 
        std::cout << "Success: File created and content written successfully."<< endl; 
    } else { 
        std::cout << "Operation failed." << endl; 
    } 
 
    return 0; 
}
