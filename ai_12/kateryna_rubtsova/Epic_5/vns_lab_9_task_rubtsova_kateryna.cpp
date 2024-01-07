#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    cout << "Введіть дані для файлу F1:" << endl;

    ofstream f1("F1.txt");
    if (!f1.is_open()) {
        cout << "Error.\n";
        return 0;
    }

    // Користувач вводить 10 рядків
    for (int i = 1; i <= 10; ++i) {
        string line;
        cout << "String " << i << ": ";
        getline(cin, line);
        f1 << line << endl;
    }

    f1.close();

    int K;
    cout<<"Enter K: ";
    cin>>K;
    ifstream f1_read("F1.txt");
    ofstream f2("F2.txt");

    string line;
    int curline = 0;
    while(getline(f1_read, line)){
        ++curline;
        if(curline >= K && curline < K+5){
            f2<<line<<endl;
        }
    }
    f1_read.close();
    f2.close();

    ifstream f2_read("F2.txt");
    string content;
    while (getline(f2_read, line)) {
        content += line + '\n';
    }

    int vc = 0;
    for(char v : content){
        if(v == 'A' || v == 'a' || v == 'E' || v == 'e' || v == 'I' || v == 'i' || v == 'O' || v == 'o' || v == 'U' || v == 'u' || v == 'Y' || v == 'y'){
            ++vc;
        }
    }
    cout << "Vowels in F2: "<< vc;
    f2_read.close();

    return 0;
}