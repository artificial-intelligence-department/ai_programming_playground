#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char str[256];
    cout << "Enter your string:\n";
    gets_s(str, 256);
    vector<string> num_words;
    char* token = strtok(str, " .");
    while (token != NULL)
    {
        if (isdigit(token[0]))
        {
            num_words.push_back(token);
        }
        token = strtok(NULL, " .");
    }
    sort(num_words.begin(), num_words.end(), greater<string>()); 
    cout << "Here are the sorted words that start with numbers:\n";
    for (auto v : num_words)
    {
        cout << v << " ";
    }
}