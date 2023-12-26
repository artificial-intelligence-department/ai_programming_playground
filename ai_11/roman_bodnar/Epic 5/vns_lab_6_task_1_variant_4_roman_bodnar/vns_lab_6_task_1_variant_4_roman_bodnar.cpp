#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int max_size = 255;

int main()
{
    // room for '\0'
    char str[max_size + 1];
    printf("Enter string: ");
    fgets(str, max_size, stdin);

    vector<char*> words;
    char* word = strtok(str, " \n");
    while (word != NULL)
    {
        words.push_back(word);
        word = strtok(NULL, " \n");
    }

    for (int i = 0; i < words.size(); i++)
        if (strcmp(words[0], words[i]) == 0 && i != 0)
            printf("%s ", words[i]);

    return 0;
}