#include <iostream>
using namespace std;

void isPalindrom(string input, int start, int end)
{
    if(input[start] != input[end])
    {
        cout << input << " is not a palindrom";
        return;
    } else if(start > end)
    {
        cout << input << " is a palindrom";
        return;
    }

    isPalindrom(input, start+1, end-1);
}

int main()
{
    start:
    string choice;
    cout << "What do you want to check?(number/string)\n";
    cin >> choice;

    if(choice == "string")
    {
        string input;
        cout << "Enter your string: ";
        cin >> input;

        isPalindrom(input, 0, input.size()-1);
    } else if(choice == "number")
    {
        int input;
        cout << "Enter your number: ";
        cin >> input;

        string inputStr = to_string(input);
        isPalindrom(inputStr, 0, inputStr.size()-1);
    } else{
        cout << "Choose 'string' or 'number'!";
        goto start;
    }

    return 0;
}