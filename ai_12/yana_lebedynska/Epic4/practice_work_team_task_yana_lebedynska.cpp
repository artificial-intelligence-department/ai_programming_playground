#include <iostream>
#include <string>
using namespace std;

bool isPalindrom(const string& WORD, int start, int end)
{
    if(WORD[start] != WORD[end])
    {
        return false;
    }

    
    if(start == end)
    {
        return true;
    }

    return isPalindrom(WORD, start + 1, end - 1);
}

bool isPalindrom(int number)
{
    string numberSTR = to_string(number);

    return isPalindrom(numberSTR, 0, numberSTR.length() - 1);
}

int main()
{
    string LINE;
    int NUM;

    cout << "Enter the word or you want to check: ";
    cin >> LINE;
    cout << "Enter the number you want to check: ";
    cin >> NUM;

    if(isPalindrom(LINE, 0, LINE.length() - 1))
    {
        cout << "Yes, the word " << LINE << " is palidrom!" << endl;
    }
    else
    {
        cout << "No, the word " << LINE << " isn't palindrom!" << endl;
    }

    if(isPalindrom(NUM))
    {
        cout << "Yes, the number " << NUM << " is palindrom!";
    }
    else
    {
        cout << "No, the number " << NUM << " isn't palindrom!";
    }

    return 0;
}
