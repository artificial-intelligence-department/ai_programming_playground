// ConsoleApplication97.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
    char input[256];
    gets_s(input);
    int minlength = 256;
    int k = 0;
    for (int i = 0; i < 256; i++)
    {
        if (input[i] != NULL)
        {
            if (input[i] != ' ' && input[i] != '.' && input[i] != NULL)
            {
                k++;
            }
            if (input[i] == ' ' || input[i] == '.' || input[i] == NULL)
            {
                if (k < minlength && k != 0)
                {
                    minlength = k;
                }
                k = 0;
            }
        }
    }
    int maxlength = 0;
    int j = 0;

    for (int i = 0; i < 256; i++)
    {
        if (input[i] != NULL) {
            if (input[i] != ' ' && input[i] != '.' && input[i] != NULL)
            {
                j++;
            }
            if (input[i] == ' ' || input[i] == '.' || input[i] == NULL)
            {
                if (j > maxlength)
                {
                    maxlength = j;
                }
                j = 0;
            }
        }

    }
    cout << "The shortest word has " << minlength << " letters" << endl;
    cout << "The longest word has " << maxlength << " letters" << endl;

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
