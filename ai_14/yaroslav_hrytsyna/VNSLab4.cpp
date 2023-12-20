#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int n=rand()%10;
    int a[n];
    int maxel=0;
    int minel=0;
    for (int i = 0; i < n; ++i) {
        a[i]=rand()%10;
        if (a[i]>a[maxel]){
            maxel=i;
        }
        if (a[i]<a[minel]){
            minel=i;
        }
    }
    swap(a[maxel],a[minel]);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    double avg=sum/n;
    for (int i = 0; i < n; ++i) {
        if (a[i]>avg*1.1){
            a[i]=-1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i]!=-1){
            cout << a[i] << " ";
        }
    }
    cout << endl;
}