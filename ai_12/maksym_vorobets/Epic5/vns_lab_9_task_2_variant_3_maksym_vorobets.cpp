#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream f1("F1.txt");
    if (!f1.is_open()) {
        cout << "Помилка" << endl;
    }
    for (int i = 0; i < 10; ++i) {
        string rad;
        getline(cin, rad);
        f1 << rad << '\n';
    }
    f1.close();
    ifstream f1_read;
    ofstream f2;
    f1_read.open("F1.txt");
    f2.open("F2.txt");
    if (!f1_read.is_open() && !f2.is_open()) {
        cout<<"Помилка"<<endl;
    }else{
        string line;
        while (getline(f1_read, line)) {
            if (!line.empty() && line.front() == line.back()) {
                f2 << line << '\n';
            }
        }}
        f1_read.close();
        f2.close();
        ifstream f2_read;
        f2_read.open("F2.txt");
        if (!f2_read.is_open()) {
            cout<<"Помилка"<<endl;
        }else{
            f2_read.seekg(0, ios::end);
            int r = f2_read.tellg();
            

            cout << "Кількість символів в F2: " << r << endl;
        } 
        f2_read.close();
    return 0;
}

