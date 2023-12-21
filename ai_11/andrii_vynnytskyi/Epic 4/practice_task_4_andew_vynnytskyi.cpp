#include <iostream>
using namespace std;

bool is_palindrome(string str, int first , int last )
{
    for (int k = 0; k <str.length(); k++)
    {
       str[k] = tolower(str[k]);
    }
    if(last > 0 && first < str.length())
    {
        if (str[first] == str[last]) {
            return is_palindrome(str, ++first, --last);
        }
        else
        {
            return false;
        }

    }
    return true;


}

bool is_palindrome(int num)
{

    return is_palindrome(to_string(num), 0 , to_string(num).length() - 1 );
}

int main()
{
    string example = "radar";
    int example1 = 12321;
    cout<< is_palindrome(example , 0, example.length() - 1)<<endl;
    cout<<(is_palindrome(example1));
    return 0;

}
