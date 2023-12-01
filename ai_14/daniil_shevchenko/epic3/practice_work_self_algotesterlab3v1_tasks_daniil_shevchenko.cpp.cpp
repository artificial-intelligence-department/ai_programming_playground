#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    string* array = new string[N];
    cin.ignore(30000, '\n');
    for (int i = 0; i < N; i++)
    {
        getline(cin, array[i]);


    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int size = array[i].size();
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == '#' && array[i][j+1] != '#')
            {
                count++;
            }
        }
    }
    cout << count;
}