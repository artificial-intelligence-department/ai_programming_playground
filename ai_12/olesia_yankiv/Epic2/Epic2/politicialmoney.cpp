#include <iostream> 
using namespace std;

int main()
{
    int n;
    cin>>n;

    int money [] = {500,200,100,50,20,10,5,2,1};

    int amount = 0;
    for (int i = 0; i < 9; ++i) {
        amount += n / money[i];
        n %= money[i];
    }

    cout <<  amount << endl;

    return 0;
}