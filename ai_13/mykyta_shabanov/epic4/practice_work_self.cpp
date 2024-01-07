#include <iostream>
#include <string>

using namespace std;

int CalculateRepetitions(string str, int index)
{
    int n = 1;
    while(str[index] == str[++index])
        n++;

    return n;
}

int main()
{
        //prompting
    string input, result = "";
    cin >> input;

        //length exception
    if(input.size() == 1)
    {
        cout << input[0];
        return 0;
    }

        //main logic
    for(int i = 0; i < input.size(); i++)
    {
        result += input[i];
        if(input[i] == input[i+1])
        {
            int rep = CalculateRepetitions(input, i);
            result += to_string(rep);
            i += rep-1;
        }
    }

    cout << result;

    return 0;
}

