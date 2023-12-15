#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ofstream f1("F1.txt");
    string deletedLine = "";
    const int countRow=10;
    for (int i = 1; i <= countRow; i++) {
        f1 << "Row " << i<< " ready"<<endl; 
    }
    f1.close();
    ifstream f1Read("F1.txt");
    ofstream f2("F2.txt"); 
    for (int i = 0; i < 3; i++) {
        char temp[256];
        f1Read.getline(temp, sizeof(temp));     
    }
    char line[255];
    string lastLine;
    int i=4;
    while (f1Read.getline(line, sizeof(line))){ 
        f2 << line << endl;
        lastLine+=line;
        lastLine += '\n';
    }
    f1Read.close();
    f2.close();
int lastSpace = 0;
for(int i=0; i<lastLine.length(); i++){
    if(lastLine[i]==' '){
        lastSpace=i+2;
    }
}
    cout<<lastLine.length()-lastSpace;
    return 0;
}
