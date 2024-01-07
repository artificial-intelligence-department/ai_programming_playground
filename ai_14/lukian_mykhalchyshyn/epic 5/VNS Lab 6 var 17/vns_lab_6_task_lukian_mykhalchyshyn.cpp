#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Введіть текст рядка: ";
    char simvol;
    string word; 

    while (cin.get(simvol))
    {
        if (simvol == ' ' || simvol == '\n')
        {
            sort (word.begin(), word.end());
            cout << word << " ";
            word.clear();
        }
        else 
        {
            word += simvol;
        }
        if (simvol == '\n')
        {
            break;
        }
    }

    return 0;
}