#include <iostream>
#include <vector>
using namespace std;
int main(){
    int M, a, b, c;
    vector <int> vec;
    vector <int> newvec;
    vector <int> sumvec;
    cin >> M;
    for (int i = 0; i < M; i++){
        int input;
        cin >> input;
        vec.push_back(input);
    }
    cin >> a >> b >> c;

    for (int i = 0; i < M; i++){
        if (vec[i] != a && vec[i] != b && vec[i] != c){
            newvec.push_back(vec[i]);
        }
    }
    if (newvec.empty()){
        cout << 0 << endl;
    }
    else{
        for (int i = 0; i < newvec.size() - 1; i++){
            sumvec.push_back(newvec[i] + newvec[i+1]);
        }
        if (!sumvec.empty()) {
            cout << sumvec.size() << endl;
            for (int i = 0; i < sumvec.size(); i++){
                cout << sumvec[i] << " ";
            }
        }
        else{
            cout << 0;
        }
    }
    return 0;
}