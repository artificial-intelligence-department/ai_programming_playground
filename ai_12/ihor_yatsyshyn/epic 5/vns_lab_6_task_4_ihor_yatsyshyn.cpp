#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char string[256];
    int counter = 0;

    cout << "Enter your string: ";
    gets(string);

    char *word = strtok(string, " ");
    char *first = word;

    while(word != NULL)
    {
        word = strtok(NULL, " ");

        if(word != NULL && strcmp(word, first) == 0)
        {
            cout << word << endl;
            counter++;
        }
    }

    cout << "Total: " << counter << " words";

    return 0;
}