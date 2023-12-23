#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, output;
    char letterold = '\0'; 
    int count = 1; 
    cin >> input;

    for (char letter : input)
    {
        if (letter == letterold)
        {
            ++count;
        }
        else
        {
            if (count != 1)
            {
                output += to_string(count);
            }
            output += letter;
            count = 1; 
        }
        letterold = letter;
    }

    if (count != 1)
    {
        output += to_string(count);
    }

    cout << output;

    return 0;
}

