#include <iostream>
#include <string>

    //finding a palindrome using recursion
bool isPalindrome(const std::string& str, int start, int end)
{
    if(start >= end)
        return true;
    if(str[start] != str[end])
        return false;
    
    return isPalindrome (str, start + 1, end - 1);
}

    //useless overload
bool isPalindrome(int num)
{
    std::string str = std::to_string(num);
    return isPalindrome(str, 0, str.size() - 1);
}

int main() 
{
        //input
    std::string input;
    std::cout << "Enter a word or number to check if it's a palindrome:" << std::endl;
    std::cin >> input;
        
        //using magic on the next line
    bool result = isPalindrome(input, 0, input.size() - 1);
    
        //output
    std::cout << std::endl << input;
    result ? std::cout << " is a palindrome." : std::cout << " is not a palindrome.";

    return 0;
}
