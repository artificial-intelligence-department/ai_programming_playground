#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void filetofile(const std::string& inputFile, const std::string& outputFile) {
    ifstream F1(inputFile);
    ofstream F2(outputFile);

    if (!(F1.good())&&!(F2.good())) {
        cout << "error\n";
        return;
    }

    string line;
    int lineNumber = 1;
    while (getline(F1, line)) {
        if (lineNumber % 2 == 0) {
            F2 << line <<endl;
        }
        lineNumber++;
    }

    F1.close();
    F2.close();
}
void size_in_bites(const std::string& inputFile, const std::string& outputFile){
    ifstream F1(inputFile);
    ifstream F2(outputFile);

    int sizeF1 = 0;
    int sizeF2 = 0;
    string str;

    if (!(F1.good())&&!(F2.good())) {
        cout << "error\n";
        return;
    }

    while(getline(F1, str)){
        if(str!=""){
            sizeF1 += size(str)+2;
        }
    }

    while(getline(F2, str)){
        if(str!=""){
            sizeF2 += size(str)+2;
        }
    }
    int sizechar = sizeof(char);
    cout<<"Size of first file: "<<sizeF1*sizechar<<"\nSize of second file: "<<sizeF2*sizechar;
}
int main(){
    string input[10] = {"line1\n","line2\n","line3\n","line4\n","line5\n","line6\n","line7\n","line8\n","line9\n","line10\n"} ;
    
    fstream F1("F1.txt");

    if(!(F1.good())){
        cout<<"Error!";
    }
    
    for(int i=0; i<10; i++){
        F1<<input[i];
    }

    fstream g("F1.txt");
    if(!(g.good())){
        cout<<"Error!";
    }

    string line;
    while(getline(g, line)){
        cout<<line<<"\n";
    }
    g.close();

    filetofile("F1.txt","F2.txt");
    
    size_in_bites("F1.txt","F2.txt");

    return 0;
}