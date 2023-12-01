#include <iostream>

using namespace std;

int main()
{   
    int sum = 0;
    
    for (int i = 2; i < 100; i += 2)
        sum += i;

    cout << "The sum of even positive integers less than 100 is: " << sum << endl;

    return 0;
}
