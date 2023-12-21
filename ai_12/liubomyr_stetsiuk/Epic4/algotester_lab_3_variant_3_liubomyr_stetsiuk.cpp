#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long num = 1;
    string input;
    cin >> input;

    vector<char> letters;
    string letter;
    for (char h : input)
    {
        letters.push_back(h);
    }
    for (int i = 0; i < letters.size(); i++)
    {
        if (letters.size() == 1)
        {
            cout << letters[0];
            break;
        }

        if (letters[i] == letters[i + 1])
        {
            num++;
        }

        if (letters[i] != letters[i + 1])
        {
            if (num == 1)
            {
                cout << letters[i];
            }

            else
            {
                cout << letters[i - num + 1] << num;
                num = 1;
            }
        }

        if (letters.empty())
        {
            break;
        }
    }
    return 0;
}
