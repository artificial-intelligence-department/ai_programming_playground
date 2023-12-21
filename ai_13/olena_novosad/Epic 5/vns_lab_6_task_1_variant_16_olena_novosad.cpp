#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

void findAndPrintOriginalWords(char str[])
{
    char *token;
    vector<string> words;
    vector<bool> unique;

    token = strtok(str, " ");
    words.push_back(string(token));
    unique.push_back(true);

    while (token)
    {
        token = strtok(NULL, " ");
        if (token)
        {
            words.push_back(string(token));
            unique.push_back(true);
        }
    }

    for (int i = 0; i < words.size() - 1; i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if (words[i] == words[j])
            {
                unique[i] = false;
                unique[j] = false;
            }
        }
    }
    
    for (int i = 0; i < words.size(); i++)
    {
        if (unique[i])
        {
            printf("%s\n", words[i].c_str());
        }
    }
}

int main()
{
    char s[255];
    gets(s);
    findAndPrintOriginalWords(s);
}