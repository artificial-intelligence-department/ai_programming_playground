#include <iostream>
#include <string>

bool isPalindrome(const std::string &str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int isPalindrome (int  n){
    std::string intstring = std::to_string(n);
    return isPalindrome(intstring, 0, intstring.length()-1);
}

int main()
{
    std::cout << "Enter a word to check whether it's a palindrome: " << std::endl;
    std::string input;
    std::cin >> input;
    int start = 0, end;
    end = input.length() - 1;
    if (isPalindrome(input, start, end))
    {
        std::cout << input << " is a palindrome.";
    }
    else
    {
        std::cout << input << " is not a palindrome.";
    }
    std::cout << std::endl << std::endl << "Enter a number to check whether it's a palindrome: " << std::endl;
    int x;
    std::cin >> x;
    if (isPalindrome(x))
    {
        std::cout << x << " is a palindrome.";
    }
    else
    {
        std::cout << x << " is not a palindrome.";
    }
    return 0;
}