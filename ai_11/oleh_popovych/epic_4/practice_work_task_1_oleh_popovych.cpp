//
// Created by olehio-p on 11/2/2023.
//
#include <iostream>
#include <string>

bool isPalindrome(const std::string&, int, int);
bool isPalindrome(int);
bool is_number(const std::string&);

int main(int argc, char const *argv[])
{
    std::string word;
    bool is_palindrome;

    std::cout << "Enter a word or number to check if it's a palindrome: ";
    std::cin >> word;

    if(is_number(word))
        is_palindrome = isPalindrome(stoi(word));
    else
        is_palindrome = isPalindrome(word, 0, word.length()-1);

    std::string answer = word + (is_palindrome ? " is " : " isn't ") + "palindrome";
    std::cout << answer << std::endl;
    return 0;
}

bool isPalindrome(const std::string& str, int start, int end)
{
    if(start < end)
        return tolower(str[start]) == tolower(str[end])
               && isPalindrome(str, ++start, --end);
    else
        return true;
}

bool isPalindrome(int number)
{
    std::string str = std::to_string(number);
    return isPalindrome(str, 0, str.length()-1);
}

bool is_number(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    while(it != str.end() && std::isdigit(*it))
        ++it;
    return !str.empty() && it == str.end();
}