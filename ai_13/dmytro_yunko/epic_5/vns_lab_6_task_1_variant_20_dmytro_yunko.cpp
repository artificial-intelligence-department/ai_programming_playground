#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    istringstream iss(s);
    string word;

    int max_length = 0;
    while (iss >> word)
    {

        if (word.length() > max_length)
        {
            max_length = word.length();
        }
    }

    cout << "Max length: " << max_length << endl;

    return 0;
}