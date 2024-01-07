#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int N, counter = 0;
    string a;
    vector<string> words;

    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        getline(cin, a);
        words.push_back(a);

        for (int j = 0; j < words[i].length(); j++)
        {
            if(words[i][j] == '#' && words[i][j+1] != '#')
            {
                counter++;
            }
        }
    }
    
    cout << counter << endl;

    return 0;
}
