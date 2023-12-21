#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define BUFSIZE 512
#define BUFWORD 64
#define LINES_COUNT 10

using namespace std;

char input[LINES_COUNT][BUFSIZE] = {"Amidst the bustling digital landscape, I celebrate one year of serving as your virtual assistant.\n",
    "Exploring a myriad of topics with you has been an enlightening journey over the past year.\n",
    "Venturing into the depths of knowledge, our interactions have been both dynamic and rewarding.\n",
    "As I reflect on the past 12 months, I'm grateful for the diverse questions and conversations that have shaped my understanding.\n",
    "Navigating through various inquiries, I've appreciated the diverse range of subjects you've brought to our conversations.\n",
    "Always ready to assist, I appreciate the trust you've placed in me for answering queries and providing information.\n",
    "Unraveling the complexities of different fields together has been a fascinating experience.\n",
    "Adapting and evolving, I look forward to more interactions and learning experiences in the upcoming years.\n",
    "Grasping the intricacies of your queries, I'm excited to continue our engaging discussions in the future.\n",
    "Acknowledging your role in this journey, thank you for making the past year full of curiosity, discovery, and growth.\n"};

void formFile(const char *file);
void printFile(const char *file, int linesCount);
int copyFileWithChar(const char *sourceFile, int linesCount, const char *newFile, char ch);
int fileWordsCount(const char *file, int linesCount);

int main()
{
    int newLinesCount, wordsCount;

    formFile("F1.txt");

    newLinesCount = copyFileWithChar("F1.txt", LINES_COUNT, "F2.txt", 'A');

    printFile("F2.txt", newLinesCount);

    wordsCount = fileWordsCount("F2.txt", newLinesCount);

    cout << "There are " << wordsCount <<  " words in the file F2.txt\n";

    return 0;
}
void formFile(const char *file)
{
    FILE* fin = fopen(file, "wt+");

    for(int i = 0; i < LINES_COUNT; i++)
    {
        fputs(input[i], fin);
    }
    fclose(fin);
    return;
}
void printFile(const char *file, int linesCount)
{
    FILE* fo = fopen(file, "rt");
    char line[BUFSIZE];

    if(fo == NULL)
    {
        exit(1);
    }

    while(linesCount--)
    {
        fgets(line, BUFSIZE, fo);
        cout << line;   
    }

    fclose(fo);
    return;
}
int copyFileWithChar(const char *sourceFile, int linesCount, const char *newFile, char ch)
{
    FILE* fo = fopen(sourceFile, "rt");
    FILE* fin = fopen(newFile, "wt+");
    char line[BUFSIZE];
    int newLinesCount = linesCount;

    if(fo == NULL)
    {
        printf("Error open file!!!\n");
        exit(1);
    }

    while(linesCount--)
    {
        fgets(line, BUFSIZE, fo);

        if(line[0] == ch)
        {
            fputs(line, fin);
            newLinesCount--;
        }
    }

    fclose(fo);
    fclose(fin);

    return newLinesCount;
}
int fileWordsCount(const char *file, int linesCount)
{
    FILE* fo = fopen(file, "rt");
    char line[BUFSIZE];
    char *ptr;
    int n = 0;

    if(fo == NULL)
    {
        printf("Error open file!!!\n");
        exit(1);
    }

    while(linesCount--)
    {
        fgets(line, BUFSIZE, fo);
        n++;
        ptr = line;

        while(*ptr != '\n')
        {
            if (*ptr == ' ')
            {
                n++;
            }
            
            ptr++;
        }
    }

    fclose(fo);

    return n;
}
