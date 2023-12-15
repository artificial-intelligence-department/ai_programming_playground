#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult{
    Success,
    Failure
};

FileOpResult write_to_file(const char *name, char *content){
    ofstream F(name);
    if(F.is_open()){
        cout << "opened successfully!" << endl;
        F << content;
        F.close();
        if(!F.is_open()){
            cout << "closed successfully!" << endl;
            return Success;
        }
        else{
            cout << "problem in closing!" << endl;
            return Failure;
        }
    }
    else{
        cout << "problem in opening!" << endl;
        return Failure;
    }
}

int main(){
    const char *name = "text.txt";
    char content[200];
    char answer[5];
    
    do{
    cout << "input: ";
    cin.ignore();
    cin.getline(content, sizeof(content));
    FileOpResult result = write_to_file(name, content);

    if(result == Success){
        ifstream file1(name);
        string line;
        while(getline(file1, line)){
            cout << line << endl;
        }
        file1.close();
        cout << "successfully printed!" << endl;
        cout << "do u want to continue? ";
        cin >> answer;
    }
    else{
        cout << "do u want to try one more time? ";
        cin >> answer;
    }
    
    }while(strcmp(answer, "yes") == 0);
    
    cout << "bye!" << endl;

    return 0;
}