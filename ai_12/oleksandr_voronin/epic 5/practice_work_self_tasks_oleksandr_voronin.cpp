#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,M;
    vector<int> first;
    vector<int> second;

    cin >> N;

    for(int i=0;i< N;i++){
        int b;
        cin >> b;
        first.push_back(b);
    }

    cin >> M;

    for(int j=0;j< M;j++){
        int a;
        cin >> a;
        second.push_back(a);
    }
   sort(first.begin(),first.end());
   sort(second.begin(),second.end());

   vector<int> diference1; 
   set_difference(first.begin(),first.end(),second.begin(),second.end(),back_inserter(diference1));
    sort(diference1.begin(),diference1.end());
    cout << diference1.size()<<endl;
    for(int i=0;i<diference1.size();i++){
        cout <<diference1[i]<<" ";
    }
    cout << endl;
   vector<int> diference2;
   set_difference(second.begin(),second.end(),first.begin(),first.end(),back_inserter(diference2));
   sort(diference2.begin(),diference2.end());
    cout << diference2.size()<<endl;
    for(int i=0;i<diference2.size();i++){
        cout <<diference2[i]<<" ";
    }
    cout << endl;
   vector<int> intersection;
   set_intersection(first.begin(), first.end(), second.begin(), second.end(),back_inserter(intersection));
    sort(intersection.begin(),intersection.end());
    cout << intersection.size()<<endl;
    for(int i=0;i<intersection.size();i++){
        cout <<intersection[i]<<" ";
    }
    cout << endl;
   vector<int> uni;
   set_union(first.begin(), first.end(), second.begin(), second.end(),back_inserter(uni));
    sort(uni.begin(),uni.end());
    cout << uni.size()<<endl;
    for(int i=0;i<uni.size();i++){
        cout <<uni[i]<<" ";
    }
    cout << endl;
   vector<int> semetric_dif;
   set_symmetric_difference(first.begin(),first.end(),second.begin(),second.end(),back_inserter(semetric_dif));
   sort(semetric_dif.begin(),semetric_dif.end());
   cout << semetric_dif.size()<<endl;
    for(int i=0;i<semetric_dif.size();i++){
        cout <<semetric_dif[i]<<" ";
    }
    cout << endl;
}