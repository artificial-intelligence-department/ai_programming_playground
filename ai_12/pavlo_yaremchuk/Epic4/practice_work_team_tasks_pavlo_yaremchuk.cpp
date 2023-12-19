#include <iostream>
#include <string>
using namespace std;

int n = 0;
bool isPalindrome(const string& str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    else if (str[start] == str[end])
    {
        return isPalindrome(str, start + 1, end - 1);
    }
    else
    {
        return false;
    } 
}

bool isPalindrome(int number)
{
    string Num = to_string(number);
    int M = Num.size() - 1;
    return isPalindrome(Num, 0, M);
}

int main()
{
    cout << "Введіть, що ви хочете перевірити на паліндром (word a6o number): ";
    string w, v1 = "word", v2 = "number";
    cin >> w;
    if (w == v1)
    {
        cout << "Введіть слово: ";
        string a;
        cin >> a;
        int N = a.size() - 1;
        if (isPalindrome(a, 0, N))
        {
            cout << "Слово ''" << a << "'' є паліндромом";
        }
        else
        {
            cout << "Слово ''" << a << "'' не є паліндромом";
        }
    }
    else if (w == v2)
    {
        cout << "Введіть число: ";
        string b;
        cin >> b;
        int H = b.size() - 1;  
        if (isPalindrome(b, 0, H))
        {
            cout << "Число ''" << b << "'' є паліндромом";
        }
        else
        {
            cout << "Число ''" << b << "'' не є паліндромом";
        }
    }
    return 0;
}