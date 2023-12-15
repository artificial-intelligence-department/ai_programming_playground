#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    unsigned int ai,bi;
    unsigned int a=0,b=0;
    unsigned int N,M;
    cin>>N;
    vector<unsigned int>arr1;
    if (N>100)
        N=100;
    for (int i=0;i<N;i++){
        cin>>ai;
        if (ai>100)
            ai=100;
        if(find(arr1.begin(),arr1.end(),ai)==arr1.end())
            arr1.push_back(ai);
        else
            --i;
    }
    cin>>M;
    vector<unsigned int>arr2;
    if (M>100)
        M=100;
    for (int i=0;i<M;i++){
        cin>>bi;
        if (bi>100)
            bi=100;
        if(find(arr2.begin(),arr2.end(),bi)==arr2.end())
            arr2.push_back(bi);
        else
            i--;
    }
    for (int i=0;i<arr1.size();i++)
    {
        for(int j=0;j<arr2.size();j++){
            if(arr1[i]==arr2[j])
                a++;
        }
    }
    b=M+N-a;
    cout<<a<<endl;
    cout<<b;
    return 0;
}