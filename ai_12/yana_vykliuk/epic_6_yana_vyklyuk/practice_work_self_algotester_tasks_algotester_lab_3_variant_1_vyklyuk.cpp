#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    int counter = 0;
    
    cin >> N;
    cin.ignore();
    
    string lines[N];

    for(int i = 0; i < N; ++i)
    {
        string line;
        getline(cin, line);
        lines[i] += line;
    }

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < lines[i].size(); ++j)
        {
            if(lines[i][j] == '#')
            {
                counter++;
                
                while(lines[i][j] == '#' && j < lines[i].size())
                {
                    j++;
                }
            }
        }
    }

    cout << counter << endl;

    return 0;
}
