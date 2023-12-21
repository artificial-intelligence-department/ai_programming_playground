#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    int N{0};
    int K{0};

    vector<string> words;
    cin >> N;
    cin >> K;
    cin.ignore();
    for (size_t i = 0; i < N; i++)
    {
        string word;
        getline(cin, word);
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
    }
    sort(words.begin(), words.end());
    // for (string n:words)
    // {
    //     for(char m: n){
    //         cout<<m;
    //     }
    //     cout<<endl;
    // }

    string repChars;

    for (vector<string>::iterator i = words.begin(); i != words.end(); i++)
    {
        int counter{1};
        if (*i == "")
        {
            continue;
        }

        for (vector<string>::iterator j = i + 1; j != words.end(); j++)
        {

            if (i != j && *i == *j)
            {
                counter++;
                *j = "";
            }
            else if (i != j && *j != *(j - 1))
            {
                break;
            }
        }
        if (counter >= K)
        {
            repChars.append(*i);
        }
    }

    sort(repChars.begin(), repChars.end(), greater<char>());
    vector<char> outpuChars;

    for (size_t i = 0; i < repChars.length(); i++)
    {

        if (repChars[i] != repChars[i + 1])
        {
            outpuChars.push_back(repChars[i]);
        }
    }

    if (repChars.size() == 0)
    {
        cout << "Empty!";
    }
    else
    {
        cout << outpuChars.size() << endl;
        for (char &ch : outpuChars)
        {
            cout << ch << " ";
        }
    }

    return 0;
}
