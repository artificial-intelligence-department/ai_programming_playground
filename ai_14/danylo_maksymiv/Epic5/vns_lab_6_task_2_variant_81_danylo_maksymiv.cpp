#include <iostream>
#include <cstring>
using namespace std;

void bubbleSortDescending(char arr[][255], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (strcmp(arr[j], arr[j + 1]) < 0) 
            { 
                char temp[255];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main() {
    const int MAX = 255;
    char str[MAX];
    char strmid[MAX];
    char strres[MAX][MAX];
    char sortedRes[MAX][MAX];  
    char *token;
    int i = 0, j = 0, k = 0;
    bool spaceFound = false;

    cout << "\nEnter string:\n\n";
    cin.getline(str, MAX, '.');

    for (; str[i] != '\0'; i++) 
    {
        if (str[i] != ' ') 
        {
            strmid[j] = str[i];
            j++;
            spaceFound = false;
        } 
        else 
        {
            if (!spaceFound) 
            {
                strmid[j] = ' ';
                j++;
                spaceFound = true;
            }
        }
    }
    strmid[j] = '\0';

    i = 0;
    j = 0;
    token = strtok(strmid, " ");
    while (token != NULL && i < MAX) 
    {
        strcpy(strres[i], token);
        token = strtok(NULL, " ");
        i++;
    }

    for (int m = 0; m < i; m++) 
    {
        if (isdigit(strres[m][0])) 
        {
            strcpy(sortedRes[k], strres[m]);
            k++;
        }
    }

    bubbleSortDescending(sortedRes, k);

    cout<<"\nSorted string:\n\n";
    for (int m = 0; m < k; m++) 
    {
        cout << sortedRes[m] << endl;
    }

    return 0;
}
