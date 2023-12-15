#include <iostream>
#include <string>

using namespace std;

 bool isPalindrome(const string& input, int start, int end) 
            {   
                if (input[start] != input[end])
                    {
                        return false;
                    }
                    else
                    {
                        if (start >= end)
                            return isPalindrome(input, start+1, end-1);
                        else return true;
                    }
            }


bool isPalindrome(int input) {
    int reversed = 0;
    while (input > 0)
    {
        reversed = reversed * 10 + input % 10;
        input /= 10;
    }
    if (reversed==input)
        return true;
    else return false;
    
}

bool inputString(const string& input)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]) == true)
            return false;
    }
    return true;
}

int main() {
    string input;
    cin >> input;
    if (inputString(input)) 
    {
        if (isPalindrome(input, 0, input.size() - 1)) 
        {
            cout << "Is palindrome" << endl;
        } 
        else
        {
            cout << "Is not a palindrome" << endl;
        }
    } 
    else 
    {
        string s = to_string(stoi(input));
        if (isPalindrome(s, 0, input.size() - 1))
        {
            cout << "Is palindrome" << endl;
        }
        else 
        {
            cout << "Is not a palindrome" << endl;
        }
    }

    return 0;
}
