#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    const int max = 256;
    char text[max];
    char letters[max] = "";
    char numbers[max] = "";
    char editedText[max] = "";
    //gets(text);
    cin.getline(text, max);
    for (int i = 0; i < strlen(text); ++i)
    {
        if(isalpha(text[i]) || text[i] == ' ' && isalpha(text[i - 1]))
        {
            char l[2] = {text[i]};
            strcat(letters, l);
        }
        else
        {
            char n[2] = {text[i]};
            strcat(numbers, n);
        }
    }

    strcat(editedText, letters);
    strcat(editedText, numbers);

    puts(editedText);

    return 0;
}