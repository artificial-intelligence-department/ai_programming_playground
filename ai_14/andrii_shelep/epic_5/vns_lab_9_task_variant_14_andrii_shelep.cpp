#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void form(){
    fstream f("file1.txt", fstream::out);
    string line;
    for(int i = 0; i < 10; i++){
        getline(cin, line);
        f << line << endl;
    }
    f.close();
}

void printFile(const char* name){
    fstream f(name, fstream::in);

    if(f.is_open()){
        string line;
        while (!f.eof()){
            line = "";
            getline(f, line);
            cout << line << endl;
        }

        f.close();
    } else{
        cout << "file does not exist" << endl;
        return;
    }
};

void copyLine(int n1, int n2){
    fstream f1("file1.txt", fstream::in);
    fstream f2("file2.txt", fstream::out | fstream::app);

    if(f1.is_open() && f2.is_open()){
        string line;
        int index=0;
        while(getline(f1, line)){
            ++index;
            if(index >= n1 && index <= n2){
                if((line.find('A')==string::npos)&&(line.find('a')==string::npos)){
                    f2 << line << endl;
                }
            }
        }
        f1.close();
        f2.close();
    } else{
        cout << "error" << endl;
        return;
    }
};

void golos(){
    fstream f("file2.txt", fstream::in);

    if(f.is_open()){
        string line;
        int count, index = 1;
        int max_count = 0, max_index = 1;
        while (!f.eof()){
            count = 0;
            line = "";
            getline(f, line);
            for(int i = 0; i < line.size(); i++){
                line[i] = tolower(line[i]);
                if(line[i] == 'a' || line[i] == 'e' || line[i] == 'u' || line[i] == 'i' || line[i] == 'o'){
                    count++;
                }
            }
            if(count >= max_count){
                max_count = count;
                max_index = index;
            }
            index++;
        }
        cout << max_index << endl;
        f.close();
    } else{
        cout << "file does not exist" << endl;
        return;
    }
};

int main(){
    form();
    cout << endl << "created file:" << endl;
    printFile("file1.txt");

    int N1, N2;
    cout << "enter the number of lines:" << endl;
    cin >> N1 >> N2;

    copyLine(N1, N2);
    printFile("file2.txt");

    golos();

    fstream f2("file2.txt", fstream::out | fstream::trunc);
    f2.close();

    return 0;
}