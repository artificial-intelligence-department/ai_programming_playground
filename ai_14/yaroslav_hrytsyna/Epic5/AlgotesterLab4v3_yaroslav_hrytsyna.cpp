#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compareDecreasing(int a, int b) {
    return a > b;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a (N);
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    int k0=0;
    int k1=0;
    int k2=0;
    std::stable_partition(a.begin(), a.end(), [](int x)
    {
        return x%3==2;
    });
    std::stable_partition(a.begin(), a.end(), [](int x)
    {
        return x%3==1;
         
    });
    std::stable_partition(a.begin(), a.end(), [](int x)
    {
        return x%3==0;
         
    });
    for(int i = 0; i < a.size(); i++){
        if (a[i]%3 == 0)
        {
            k0+=1;
            k1+=1;
            k2+=1;
        }
        else if (a[i]%3 == 1)
        {
            k1+=1;
            k2+=1;
        }
        else if (a[i]%3 == 2)
        {
            k2+=1;
        }
    }
    sort(a.begin(),a.begin()+k0);
    sort(a.begin()+k0,a.begin()+k1,compareDecreasing);
    sort(a.begin()+k1,a.begin()+k2);
    auto new_a = unique(a.begin(),a.end());
    a.erase(new_a, a.end());
    cout<< a.size()<<endl;
    for (const auto& an : a) {
        std::cout << an << " ";
    }
}
