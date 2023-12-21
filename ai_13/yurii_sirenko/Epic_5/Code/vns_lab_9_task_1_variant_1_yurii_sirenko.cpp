#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main() 
{
    ofstream outF1("F1.txt");
    for(int i = 0;i<20;i++)
    {
        outF1<<"Line"<<i<<"\n";
    }
    outF1.close();

    ifstream inFile("F1.txt");
    ofstream outF2("F2.txt");

    string line;
    for(int lineIt=1;getline(inFile, line);lineIt++)
    {
        if(lineIt % 2 == 0)
        {
            outF2<<line<<"\n";
        }
    }
    inFile.close();
    outF2.close();

    streampos fileSize;
    inFile.open("F1.txt");
    inFile.seekg(0, ios::end);
    fileSize = inFile.tellg();
    inFile.close();
    cout << "File size of F1: " << fileSize << " b\n";

    inFile.open("F2.txt");
    inFile.seekg(0, ios::end);
    fileSize = inFile.tellg();
    inFile.close();
    cout << "File size of F2: " << fileSize << " b\n";
}
