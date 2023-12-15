// ConsoleApplication52.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
//linked list, stack, queue
using namespace std;
bool IsPalindrome(string word, int start, int end)
{
    if (start > end)
    {
        return true;
    }
    
    if (word[start] != word[end])
    {
        return false;
    }
    
    if (word[start] == word[end])
    {
        return IsPalindrome(word, start + 1, end - 1);
    }
}

bool IsPalindrome(int number, int start, int end)
{
    string word;
    word = to_string(number);
    if (start > end)
    {
        return true;
    }

    if (word[start] != word[end])
    {
        return false;
    }

    if (word[start] == word[end])
    {
        return IsPalindrome(word, start + 1, end - 1);
    }


}

int main()
{
    string strinput;
    int intinput;
    string intinput2;
    cout << "Enter a string: ";
    getline(cin, strinput);
    cout << "Enter a number: ";
    cin >> intinput;
    intinput2 = to_string(intinput);
    int strsize = strinput.size();
    int intsize = intinput2.size();
    if (IsPalindrome(strinput, 0, strsize - 1))
    {
        cout << "The word is a palindrome" << endl;
    }
    else
    {
        cout << "The word is not a palindrome" << endl;
    }
    
    if (IsPalindrome(intinput, 0, intsize - 1))
    {
        cout << "The number is a palindrome" << endl;
    }
    else
    {
        cout << "The number is not a palindrome" << endl;
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
