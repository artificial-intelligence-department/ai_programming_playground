//
# include <iostream>
using namespace std;  
int main (){
    unsigned int N, M;
    cin >> N;
    long long nums1[N];
    for (int i=0; i<N; i++){
        cin >> nums1[i];
    } 
    cin >> M;
    long long nums2[M];
    for (int i=0; i<M; i++){
        cin >> nums2[i];
    } 
    long long count=0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
        if (nums1[i]==nums2[j]){
            count++;
        }}}
    cout << count << endl;
    cout <<N+M-count;
return 0;
}