#include <iostream>

using namespace std;

int main()
{
    int N;
    
    cin >> N;

    const int n = N;
    int a[n];
    
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int left_dron = 0;
    int right_dron = n - 1;

    while(left_dron < right_dron)
    {
        int left = a[left_dron];
        int right = a[right_dron];
        
        if(left_dron == right_dron - 1)
        {
            cout << left_dron + 1 << " " << right_dron + 1 << endl;
            cout << "Stopped" << endl;
            break;
        }

        left_dron += left;
        right_dron -= right;
    }

    if(left_dron == right_dron)
    {
        cout << left_dron + 1 << " " << right_dron + 1 << endl;
        cout << "Collision" << endl;
    }
    
    if(left_dron > right_dron)
    {
        cout << left_dron + 1 << " " << right_dron + 1 << endl;
        cout << "Miss" << endl;
    }
    
    return 0;
}
