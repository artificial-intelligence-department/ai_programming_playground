#include <iostream>
#include <cctype>
#include <string.h>

using namespace std;

int main()
{
    int k = 0, l = 0;
    char str[256];
    char *token;
    char *token1;
    char input[256];
    bool swapped;

    puts("Input string: ");
    gets(str);

    char toSort[255][255];
    char notToSort[255][255];
    token = strtok(str, " ");

    while (token != NULL)
    {   
        
        if (token != NULL && isalpha(token[0]))
        {
            strcpy(toSort[k], token);
            k++;
        }
        else if(token != NULL)
        {
            strcpy(notToSort[l], token);
            l++;
        }
        token = strtok(NULL, " ");
 
    }
    
    for (int i = 0; i < k - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < k - i - 1; j++)
        {
            if (strcmp(toSort[j], toSort[j+1]) > 0)
            {
                char temp[25];
                strcpy(temp, toSort[j]);
                strcpy(toSort[j], toSort[j+1]);
                strcpy(toSort[j+1], temp);

            }
        }
    }
    char finalStr[255];
    for(int i = 0; i < k; i++)
    {
        strcat(finalStr, toSort[i]);
        strcat(finalStr, " ");
    
    }

    for(int i = 0; i < l; i++)
    {

        strcat(finalStr, notToSort[i]);
        strcat(finalStr, " ");
    }
    
    puts(finalStr);

    return 0;
}
