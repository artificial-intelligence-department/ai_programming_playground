#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Show(vector <int> a){
    sort(a.begin(), a.end());
    cout<<a.size()<<"\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}

int main(){
    //ініціалізація
    int N,M;
    cin>>N;
    vector <int> persha(N);
    for (int i = 0; i < N; i++)
    {
        cin>>persha[i];
    }
    sort(persha.begin(), persha.end());
    cin>>M;
    vector <int> druga(M);
    for (int i = 0; i < M; i++)
    {
        cin>>druga[i];
    }
    sort(druga.begin(), druga.end());
    //Блок обрахунків
    
    vector <int> res1,res2,res3,res4,res5;
    set_difference(persha.begin(),persha.end(),druga.begin(),druga.end(), back_inserter(res1));
    set_difference(druga.begin(),druga.end(),persha.begin(),persha.end(), back_inserter(res2));
    set_intersection(persha.begin(),persha.end(),druga.begin(),druga.end(), back_inserter(res3));
    set_union(persha.begin(),persha.end(),druga.begin(),druga.end(), back_inserter(res4));
    set_symmetric_difference(persha.begin(),persha.end(),druga.begin(),druga.end(), back_inserter(res5));
    //вивід
    
    Show(res1);
    Show(res2);
    Show(res3);
    Show(res4);
    Show(res5);
    
    cout<<'\n';
}