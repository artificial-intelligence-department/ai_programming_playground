#include<iostream>
using namespace std;

string get_string()
{
    string str;
    cin >> str;
    return str;
}

string compress_string(string str)
{
    string compressed_string;
    int counter = 1;
    int index = 1;
    for(int i = 0; i < str.length() - 1; i++)
    {
        compressed_string += str[i];
        if(str[i] == str[i + index])
        {
            while(str[i] == str[i + index])
            {
                index++;
                counter++;
            }
            compressed_string += to_string(counter);
            i += (index - 1);
            counter = 1;
            index = 1;
        }
    }
    if(str[str.length() - 1] != str[str.length() - 2])
    {
        compressed_string += str[str.length() - 1];
    }
    return compressed_string;
}

int main()
{
    string str = get_string();
    cout << compress_string(str);
}
