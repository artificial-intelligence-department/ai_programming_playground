// ConsoleApplication106.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
enum Status
{
    Success,
    Failure
};
Status filewriting(string name, string input)
{
    ofstream out(name);
    if (!out)
    {
        cerr << "Can't open file for writing" << endl;
        return Failure;
    } 
    else
    {
        out << input << endl;
        cout << "Operation was completed successffully!" << endl;
        return Success;
    }
}
Status filecopying(string file_from, string file_to)
{
    ifstream outof(file_from);
    ofstream into(file_to);
    if (!outof)
    {
        cerr << "Can't open file for reading" << endl;
        return Failure;
    }
    else if (!into)
    {
        cerr << "Can't open file for writing" << endl;
        return Failure;
    }
    else
    {
        vector<string> text;
        text.resize(100);
        string str;
        cout << "The text in the file is:" << endl;
        int j = 0;
        while (getline(outof, str))
        {
            cout << str << endl;
            text[j] = str;
            j++;

        }
        for (int i = 0; i < j; i++)
        {
            into << text[i] << endl;
        }
        cout << "Operation was completed successfully";
        return Success;
    }
}
int main()
{
    cout << "Part #1" << endl;
    string a;
    getline(cin, a);
    filewriting("myfile0.txt", a);
    cout << "Part #2" << endl;
    filecopying("myfile1.txt", "myfile2.txt");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
