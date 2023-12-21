#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<bool> letters(26, false);
    int unique_letters = 0;
    for (char c : s)
    {
        if (!letters[c - 'A'])
        {
            letters[c - 'A'] = true;
            unique_letters++;
        }
    }

    cout << unique_letters << std::endl;

    return 0;
}