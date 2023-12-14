    //recursion
int SumOfRow(int n, int i = 1, int result = 0)
{
    if(n > 1)
        return SumOfRow(n - 1, i + 2, result + i);

    return result + i;
}

#include <iostream>
using namespace std;

int main()
{
    int input;
    cin >> input;

    cout << "result: " << SumOfRow(input);
}