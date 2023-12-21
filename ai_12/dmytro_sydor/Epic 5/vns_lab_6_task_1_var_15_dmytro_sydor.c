
#include <stdio.h>
#include <string.h>

void findMostOftenWord(char *s);

int main()
{
    char s[255];

    printf("Введіть рядок < 255 символів \n");
    gets(s);
    findMostOftenWord(s);
}

void findMostOftenWord(char *s)
{
    char words[255][255];
    int mostOften[255] = {0};
    int wCount = 0;

    char *token = strtok((char *)s, " ");
    while (token != NULL && wCount < 255)
    {
        strcpy(words[wCount++], token);
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < wCount; i++)
    {
        for (int j = 0; j < wCount; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                mostOften[i]++;
            }
        }
    }
    int max = 0;
    for (int i = 1; i < wCount; i++)
    {
        if (mostOften[i] > mostOften[max])
        {
            max = i;
        }
    }
    printf("Найчастіше зустрічається слово: %s\n", words[max]);
}
