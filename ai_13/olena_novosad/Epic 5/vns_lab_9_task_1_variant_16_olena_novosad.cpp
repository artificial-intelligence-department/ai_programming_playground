#include <iostream>
#include <string.h>
#include <vector>
#define MAXLINE 10000 // максимальна довжина рядка

using namespace std;

void func1(int N1, int N2)
{
    char buf[MAXLINE];

    FILE *f1;
    if ((f1 = fopen("F1.txt", "r")) == NULL)
    {
        cout << "error during opening file F1.txt\n";
        return;
    }

    FILE *f2;
    if ((f2 = fopen("F2.txt", "w")) == NULL)
    {
        cout << "error during opening file F2.txt\n";

        fclose(f1);
        return;
    }

    int i = 0;
    while (fgets(buf, MAXLINE, f1) != NULL)
    {

        if (i >= N1 && i <= N2)
        {
            auto strLength = strlen(buf);
            if (strLength >= 2 &&
                buf[0] == 'A' &&
                ((buf[strLength - 1] == '\n' && buf[strLength - 2] == 'Z') || buf[strLength - 1] == 'Z'))
            {
                fputs(buf, f2);
            }
        }

        i++;
    }

    fclose(f1);
    fclose(f2);
}

void func2()
{
    FILE *f2;
    if ((f2 = fopen("F2.txt", "r")) == NULL)
    {
        cout << "error during opening file F2.txt\n";
        return;
    }

    char buf[MAXLINE];

    if (fgets(buf, MAXLINE, f2) != NULL)
    {
        char *token;
        vector<string> words;

        token = strtok(buf, ",-:.!? ");
        words.push_back(string(token));
        do
        {
            token = strtok(NULL, ",-:.!? ");
            if (token)
            {
                words.push_back(string(token));
            }
        } while (token);

        cout << "number of words in first string is equal " << words.size() << "\n";
    }

    fclose(f2);
}

int main()
{
    FILE *f1;
    if ((f1 = fopen("F1.txt", "w")) == NULL)
    {
        cout << "error during opening file F1.txt\n";
        return -1;
    }
    fputs("I was broken from a young age\n", f1);
    fputs("Taking my sulking to the masses\n", f1);
    fputs("AWriting my poems for the fewZ\n", f1);
    fputs("AThat look at me, took to me, shook to me, feeling meZ\n", f1);
    fputs("Singing from heartache from the pain\n", f1);
    fputs("Taking my message from the veins\n", f1);
    fputs("Speaking my lesson from the brain\n", f1);
    fputs("ASeeing the beauty through theZ\n", f1);
    fputs("Pain!\n", f1);
    fputs("You made me a, you made me a believer, believer\n", f1);
    fclose(f1);

    func1(0, 5);

    func2();

    return 0;
}
