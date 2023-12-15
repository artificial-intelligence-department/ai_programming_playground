#include <iostream>
#include<vector>
using namespace std;


vector<string> parse(string text)
{
    vector<string> data;
    string buff;
    for(int i = 0 ;i < text.size(); i++)
    {
        bool is_separator_found = false;
        if (text[i] == ' ')
        {
            is_separator_found = true;
        }

        if (is_separator_found)
        {
            data.push_back(buff);
            buff = "";
        }
        else
        {
            if (text[i]!=' ')
            {
                buff += text[i];
            }

        }
    }
    return data;
}
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

int main() {
    string example ="level radar civic racecar noon elephant computer strawberry programming butterfly";
    string str;
    cout<<"Enter a string: ";
    getline(cin , str);
    cout<<"Entered a string: ";
    cout<< str << endl;
    vector<string> buff = parse(str);
    cout<<"Palindrome words: ";
    for (const auto & i : buff) {
        if(is_palindrome(i, 0, i.length() - 1))
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
