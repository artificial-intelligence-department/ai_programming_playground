#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256];
    cout << "Введіть рядок: ";
    gets(s);

    int maxLength = 0;
    int currentLength = 0;
    int length = strlen(s);

    for (int i = 0; i <= length; i++)
    {
        if (s[i] != ' ' && s[i] != '\0')
        {
            currentLength++;
        }
        else
        {
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
            }
            currentLength = 0;
        }
    }
    cout << "Довжина найдовшого слова: " << maxLength << endl;

    return 0;
}
