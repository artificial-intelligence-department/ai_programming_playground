// ConsoleApplication60.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    getline(cin, S);
    string S2;
    S2 = "";
    long size = S.size();
    long index = 0;
    
    while (index < size)
    {
        long count = 1;
        long index2 = index;
        while (S[index2] == S[index2+1])
        {
            count++;
            index2++;
        }
        string COUNT = to_string(count);
        char Element = S[index];
        if (count > 1)
        {
            S2 = S2 + Element + COUNT;
        }
        else
        {
            S2 = S2 + Element;
        }
        index = index + count;
    }
    cout << S2;
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
