

#include <iostream>
using namespace std;



int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int money[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int amount{0};

    for (int i = 8; i >=0 ; i--)
    {
        if(n/money[i]>=1){
            int temp = n/money[i];
            amount += temp;
            n = n-(money[i]*temp);
            
        }
    }
    cout<< amount;

    return 0;
}
