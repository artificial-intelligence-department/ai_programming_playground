#include <iostream>
#include <vector>

using namespace std;

int main(){
    int size_a, size_b, same = 0;

    cin >> size_a;
    vector<int> a(size_a); 
    for(int i = 0; i < size_a; i++){
        cin >> a[i];
    }
    cin >> size_b;
    vector<int> b(size_b);
    for(int i = 0; i < size_b; i++){
        cin >> b[i];
    }

    for(int i = 0; i < size_a; i++){
        for(int j = 0; j < size_b; j++){
            if(a[i]==b[j]){
                same++;
                for(int p = i; p < size_a - 1; p++){
                    a[p] = a[p+1];
                }
                size_a--;
                i--;
                break;
            }
        }
    }

    vector<int> res(size_a+size_b);
    for(int i = 0; i < size_a; i++){
        res[i]=a[i];
    }
    for(int i = size_a, j = 0; j < size_b; i++, j++){
        res[i]=b[j];
    }

    cout << same << endl << res.size();

    return 0;
}