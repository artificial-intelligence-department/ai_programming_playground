#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class FileOPResult
{
    SUCCESS,
    FAILURE,
};

FileOPResult write_to_file(char* file_name , string& text){
    ofstream file(string(file_name) + ".txt");
    if (!file.is_open())
    {
        return FileOPResult::FAILURE;
    }
    else{
        file << text;
        file.close();
        return FileOPResult::SUCCESS;
    }
}
FileOPResult copy_file(char *file_name, char *file_to){
    ifstream file(string(file_name) + ".txt");
    ofstream cpfile(string(file_to) + ".txt");

    if (!file.is_open() || !cpfile.is_open())
    {
        return FileOPResult::FAILURE;
    }
    else{
        string line;
        while(getline(file , line)){
            cpfile << line << endl;
        }
        file.close();
        cpfile.close();
        return FileOPResult::SUCCESS;
    }
}   

int main(){

    ofstream file;

    char file_name[50] , file_to[50];
    cout << "Enter file name u wanna copy from: ";
    cin >> file_name;
    cout << "\nEnter file name u wanna copy to:";
    cin >> file_to;

    cin.ignore();

    cout << "\nEnter text u wanna write to file: " << endl;
    string text;
    string line;
    getline(cin , text);

    FileOPResult result = write_to_file(file_name , text);

    FileOPResult resilt = copy_file(file_name , file_to);

    if(result == FileOPResult::SUCCESS){
        cout << "SUCCESS";
    }
    else{
        cout << "FAILURE";
    }


// size_t textLength = text.length();
//         for(size_t i = 0 ; i < text.length(); i++){
//             file.put(text[i]);
//         }
// string text;
// getline(cin , text);
// file << text;
    return 0;
}