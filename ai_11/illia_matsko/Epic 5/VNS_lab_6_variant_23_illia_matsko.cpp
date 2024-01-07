#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char str[256];

    cin.getline(str, 256);
//    gets(str);

    int count = 0, min = 256;
    for(int i = 0; i < 256; i++)
    {
        if(str[i] != ' ')
        {
            count++;
        } else {
            if(count < min)
            {
                min = count;
            }
            count = 0;
        }
    }

    cout << min;
}