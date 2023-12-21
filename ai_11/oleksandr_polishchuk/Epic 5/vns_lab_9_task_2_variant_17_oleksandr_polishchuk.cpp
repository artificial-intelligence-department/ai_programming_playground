#include <iostream>
#include <string.h>

using namespace std;

static int starts_with_a(const char** s, char* w)
{
    const char* p = *s;
    char* t = w;
    if (*p && (*p == 'a' || *p == 'A'))
    {
        while (*p != '\n' && (w - t < 512))
        {
            *w++ = *p++;
        }
        *w = '\0';
        *s = p;
    }
    return (w != t);
}

int main()
{
    char line[512];
    char *token;
    const char *ptr;

    int N1, N2, count = 0;
    cin >> N1 >> N2;
    
    FILE* fp1;
    if ((fp1 = fopen("F1.txt", "r")) == 0)
    {
        perror("\n помилка при відкритті файлу");
        exit(0);
    }
    
    FILE* fout = fopen("F2.txt", "wt+");
    if (!fout)
    {
        perror("\n помилка при відкритті файлу");
        exit(0);
    }

    int current = 0;
    while ((ptr = fgets(line, sizeof(line), fp1)) != NULL)
    {
        current++;

        if (current >= N1 && current <= N2)
        {
            if (starts_with_a(&ptr, line))
            {
                fprintf(fout, "%s\n", line);
            }
        }
        if (current > N2 + 3)
        {
            fputs(line, fout);
        }
    }

    fclose(fp1);
    
    fclose(fout);

    fout = fopen("F2.txt", "r");
    if (!fout)
    {
        perror("\n помилка при відкритті файлу");
        exit(0);
    }
    
        token = strtok(line, " ");
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            count++;
        }
    cout << "Слів у останньому рядку F2: " << count << endl;

    fclose(fout);
    return 0;
}
