#include <iostream>
using namespace std;

int main()
{
    int n;
    string sequence;
    cin >> n;
    cin.ignore();
    getline(cin, sequence);
    int signal = 15;
    for (int i = 0; i < n; i++)
    {
        switch (sequence[i])
        {
            case 'k':
            {
                signal = max(signal - 1, 0);
                break;
            }
            case 'p':
            {
                if (signal >= 1) signal = 15;
                else signal = 0;
                break;
            }
            case 'z':
            {
                if (signal >= 1) signal = 0;
                else signal = 15;
                break;
            }
        }
    }
    cout << signal;
}