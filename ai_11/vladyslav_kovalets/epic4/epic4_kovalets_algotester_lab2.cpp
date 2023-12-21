#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    unsigned int size_masiv = 100000;
    unsigned long long Number[size_masiv];
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) 
    {
        cin >> Number[i];
    }

    sort(Number, Number + N);

    int fatigue_1 = Number[N - 1] - Number[1]; 
    int fatigue_2 = Number[N - 2] - Number[0]; 
    int result;


    if (fatigue_1 < fatigue_2)
        result = fatigue_1;
    else
        result = fatigue_2;

    if (result >= 0)
    {
        cout << result;
    }
    else 
    {
        cout << 0;
    }
    return 0;
}
