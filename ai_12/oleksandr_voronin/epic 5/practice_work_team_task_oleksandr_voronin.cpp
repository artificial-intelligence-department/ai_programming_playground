#include <iostream>
#include <fstream>


using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    ofstream fl(name);

    if (!fl.is_open()) {
        return Failure;
    }
    fl << content << endl;
    fl.close();

    return Success;

}


int main(){
    const char *file_name = "file.txt";
    char content[200];

    cout << "Enter content to write into file: ";
    cin.getline(content,200);

  FileOpResult result = write_to_file(file_name, content);

    if(result == Success)
    {
        ifstream fl(file_name);
        string line;
        while(getline(fl, line)){
            cout << line << endl;
        }
        fl.close();
        cout << "successfully printed!" << endl;
    }   
}