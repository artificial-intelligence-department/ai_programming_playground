#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char list[100000];
    scanf_s("%s", list);
    int length = strlen(list);//розмір ліста
    
    char temp = list[0];
    int count = 1;

    for (int i = 1; i <= length; i++)
    {
        if (list[i] == temp)
        {
            count++;
        }
        else
        {
            cout << temp;
            if (count > 1)
            {
                cout << count;
            }
            
            temp = list[i];
            count = 1;
        }
    }

    return 0;
}
