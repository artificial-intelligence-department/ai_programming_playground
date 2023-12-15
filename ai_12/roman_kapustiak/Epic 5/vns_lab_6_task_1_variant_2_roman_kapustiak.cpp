#include <iostream>
#include <string.h>

using namespace std;

const char vowels[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

bool searchVowels(char *ch);

int main()
{
    char s[256];
    char *token; // temporary buffer

    gets_s(s, 255);

    token = strtok(s, " ");

    do
    {
        if(!(searchVowels(token)))
        {
            cout << token << " ";
            if(token[strlen(token)-1] == '.')
            {
                printf("\b \b");
                printf("\b \b");
            }
        }
        token = strtok(NULL, " ");
    }
    while (token);

    return 0;
}
bool searchVowels(char *ch)
{
    while(*ch != '\0')
    {
        for(const auto vowel : vowels)
        {
            if(vowel == *ch)
            {
                return true;
            }
        }

        ch++;
    }

    return false;
}
