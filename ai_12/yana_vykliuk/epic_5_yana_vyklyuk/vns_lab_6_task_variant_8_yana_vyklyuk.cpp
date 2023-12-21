#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

using namespace std;

void full_house_and_indicator(char *str)
{
    int length = strlen(str);
    int count = 0;

    while (count < length && isdigit((unsigned char)str[count]))
    {
        count++;
    }

    if(count == length)
    {
        str[0] = '\0';
    }
    else
    {
        memmove(str, str + count, length - count + 1);
    }
    
};

int main()
{
    char str[256];
    fgets(str, 255, stdin);
    
    char*token;

    token = strtok(str, " ");

    while(token != NULL)
    {
        full_house_and_indicator(token);
        cout << token << " ";
        token = strtok(NULL, " ");
    }

    cout << endl;

    return 0;
}
