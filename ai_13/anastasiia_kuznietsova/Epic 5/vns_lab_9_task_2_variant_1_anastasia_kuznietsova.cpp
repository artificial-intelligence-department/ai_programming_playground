#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool digit(const string& line) 
{
    for (char num : line) 
    {
        if (isdigit(num)) 
        {
            return true;
        }
    }
return false;
}

int main() 
{
    ofstream firstfile("F1.txt");

    if (!firstfile) 
    {
        cerr<<"Unable to open the F1.txt"<<"\n";
        exit(1);
    }

    firstfile<<"Anastasia\n";
    firstfile<<"Kuznietsova\n";
    firstfile<<"Volodumurivna\n";
    firstfile<<"03032006\n";
    firstfile<<"17_years_old\n";
    firstfile<<"Like_cats\n";
    firstfile<<"Freshman\n";
    firstfile<<"AI-13\n";
    firstfile<<"Lviv_Politechnic\n";
    firstfile<<"I_have_Yoda\n";

    firstfile.close();
    ifstream printfirst("F1.txt");
    string words;

    if (!printfirst) 
    {
        cerr<<"Unable to open the F1.txt"<<"\n";
        exit(2);
    }
    while (printfirst>>words) 
    {
        cout<<words<<"\n";
    }
    cout<<"\n";
    printfirst.close();

    ifstream openfile("F1.txt");
    if (!openfile) 
    {
        cerr<<"Unable to open the F1.txt"<<"\n";
        exit(3);
    }

    ofstream secondfile("F2.txt");
    if (!secondfile) 
    {
        cerr << "Unable to open F2.txt" << endl;
        exit(4);
    }

    string line;

    while (getline(openfile, line))
    {
        if(!digit(line))
        {
            secondfile<<line<<"\n"; 
        }
    } 
    openfile.close();
    secondfile.close();

    ifstream printsecond("F2.txt");
    string end;
    int A = 0;
    if (!printsecond) 
        {
            cerr << "Unable to open F2.txt" << endl;
            exit(5);
        }
    while (printsecond>>line) 
        {
            cout<<line<<"\n";
        if (line[0]=='A')
            {
                A++;
            }
        }
    cout<<"\n";
    printsecond.close();
    cout<<A<<"\n";

    return 0;
}
