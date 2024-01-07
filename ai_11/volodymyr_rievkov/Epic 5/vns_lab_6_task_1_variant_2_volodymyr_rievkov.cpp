#include<iostream>
#include<string.h>
using namespace std;

const char special_chars[] = "aeiou";

void fill_string(char string[])
{
    cout << "Enter string (1-255 chars): ";
    // gets(string);
}

bool is_size_problems_with_str(char string[], int size)
{
    if(strlen(string) < 1 || strlen(string) > size - 1)
    {
        cout << "Entered string don't reply size rules";
        cout << endl << endl;
        return true;
    }
    return false;
}

bool is_word_special(char* string)
{
    bool result = true;
    for(int i = 0; i < strlen(string); i++)
    {
        if(!result)
        {
            break;
        }
        for(int y = 0; y < strlen(special_chars); y++)
        {
            if(string[i] == special_chars[y])
            {
                result = false;
                break;
            }
        }
    }
    return result;
}

void print_special_words(char string[])
{
    char* token;
    token = strtok(string, " ");
    if(is_word_special(token))
    {
        puts(token);
        cout << endl;
    }
    while(token != NULL)
    {
        token = strtok(NULL, " ");
        if(token != NULL && is_word_special(token))
        {
            if(token[strlen(token) - 1] == '.')
            {
                token[strlen(token) - 1] = ' ';
            }
            puts(token);
            cout << endl;
        }
    }
}

int main()
{
    const int size = 255;
    char text[size];
    fill_string(text);
    if(is_size_problems_with_str(text, size))
    {
        return 0;
    }
    print_special_words(text);
}