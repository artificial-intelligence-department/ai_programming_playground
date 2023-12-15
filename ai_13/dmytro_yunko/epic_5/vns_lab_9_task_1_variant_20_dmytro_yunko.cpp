#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool hasDuplicate(string line)
{

    istringstream iss(line);
    vector<std::string> words;
    string word;
    while (iss >> word)
    {
        if (find(words.begin(), words.end(), word) != words.end())
            return true;
        words.push_back(word);
    }
    return false;
}

int getVowAm(string line)
{
    int count = 0;
    for (char c : line)
    {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}

int main()
{

    string myText;

    ofstream f1W("F1.txt");

    if (f1W.is_open())
    {
        for (size_t i = 0; i < 10; i++)
        {
            string text;
            getline(cin, text);

            f1W << text << "\n";
        }
        f1W.close();
    }

    vector<string> lines;

    string line;
    string lastLn;
    ifstream f1R("F1.txt");
    ofstream f2("F2.txt");

    if (f1R.is_open())
    {
        while (getline(f1R, line))
        {

            if (hasDuplicate(line))
            {
                f2 << line << endl;
                lastLn = line;
            }
        }
    }
    cout << getVowAm(lastLn);
    return 0;
}
