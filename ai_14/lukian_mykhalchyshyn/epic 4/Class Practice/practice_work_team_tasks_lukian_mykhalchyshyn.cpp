#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string & str, int start, int end)
{
    if (start >= end) // непарна довжина
    {
    return true;
    }
    
    return (str[start] == str[end]) && isPalindrome (str, start+1, end-1 ); // порівнюєм початкову і кінцеву позицію
}

bool isPalindrome (int num)
{
    string numstr = to_string(num); //зміна num на рядок

    return isPalindrome (numstr, 0, numstr.length()-1);
}

int main()
{
    string word;
    int number;

    cout << "Введіть одне слово: ";
    cin >> word;

    cout << "Введіть число: ";
    cin >> number;
    cout << endl;

    if (isPalindrome(word, 0, word.length()-1)) // початкова і кінцева пизиція порівняння
    {
        cout << word << " (є паліндромом)\n";
    }
    else
    {
        cout << word << " (не є паліндромом)\n";
    }

    if (isPalindrome(number))
    {
        cout << number << " (є паліндромом)\n";
    }
    else
    {
        cout << number << " (не є паліндромом)\n";
    }


    return 0;
}