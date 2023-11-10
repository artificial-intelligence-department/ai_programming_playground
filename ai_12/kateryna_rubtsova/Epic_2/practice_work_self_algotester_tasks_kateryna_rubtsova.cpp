
#include <iostream>

using namespace std;

int main()
{
    unsigned int n;
    unsigned int u = 0;
    cout<<"Введіть кількість пачок печива: ";
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cout<<"Введіть кількість печива в " << i + 1 <<"-ій пачці: ";
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        arr[i]--;
        u +=arr[i];
    }

    cout <<"Марічка може з'їсти "<< u <<" штук печива";

    return 0;
}