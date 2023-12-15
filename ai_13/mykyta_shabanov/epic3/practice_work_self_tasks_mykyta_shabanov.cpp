#include <iostream>


using namespace std;
int main()
{
        //prompting
    int n;
    cin >> n;
    long long cookies[n], result = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> cookies[i];
        result += cookies[i] - 1;
    }


    cout << result;


    return 0;
   
}
