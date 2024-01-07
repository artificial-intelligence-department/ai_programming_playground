#include <iostream> 
#include <string> 
using namespace std;

string firstNumbersThanText(string str)
{
    string numbers = "";
    string text = "";
    for (int i = 0; i < str.size(); i++)
    {
        int code = int(str[i]) - 48;
        if (code >= 0 && code < 10)
        {
            numbers += str[i];
        }
        else
        {
            text += str[i];
        }
    }

    return text + numbers;
}

int main()
{
    string input;
    cin >> input;
    cout << firstNumbersThanText(input);
    return 0;
}