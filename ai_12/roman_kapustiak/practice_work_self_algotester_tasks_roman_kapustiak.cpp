//Верховна Рада
#include <iostream>

 using namespace std;

long long greatest_divisor(long long x, long long y);

 int main()
 {  
    int parties, divisor;
    long long result = 0;

    cin >> parties;

    long long votes[parties];

    for (int i = 0; i < parties; i++)
    {
        cin >> votes[i];
        result += votes[i];
    }

    divisor = votes[0];

    for (int i = 1; i < parties; i++)
    {
        divisor = greatest_divisor(divisor, votes[i]);
    }

    result /= divisor;

    cout << result << endl;

    return 0;
 }

long long greatest_divisor(long long x, long long y)    // greatest common divisor
{
    if (y == 0)
        return x;
    return greatest_divisor(y, x % y);
}
